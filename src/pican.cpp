#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdexcept>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

class SocketCANDevice{
    private:
        int socketFD;
        struct sockaddr_can addr;
        struct ifreq ifr;

    public:
        SocketCANDevice(const char* canbusName){
            //create socket (this one is for RAW can)
            if((socketFD = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0){
                perror("creating socket failed");
                throw std::runtime_error("Failed to create SocketCAN socket");
            }

            //send the canbus name through an ifreq struct
            strcpy(ifr.ifr_name, canbusName);

            if(ioctl(socketFD, SIOCGIFINDEX, &ifr) < 0){
                perror("getting CAN interface index failed");
                throw std::runtime_error("getting CAN interface index failed");
            }

            //bind socket to CAN interface
            memset(&addr, 0, sizeof(addr));
            addr.can_family = AF_CAN;
            addr.can_ifindex = ifr.ifr_ifindex;

            if(bind(socketFD, (struct sockaddr *)&addr, sizeof(addr)) < 0){
                perror("binding socket failed");
                throw std::runtime_error("binding socketCAN socket failed");
            }
        }
        /**
         * @param frame a can_frame struct that will be populated with data by the function
         * @return boolean for if the message was successfully read or not
         * can_frame struct info:
         * .can_id: gives can ID
         * .len: gives length of data packet
         * .data: array with each byte of can data
         */
        bool readCANMessage(struct can_frame &frame){
            int nBytes;

            //read the can data (the frame passed in will get populated with data)
            nBytes = read(socketFD, &frame, sizeof(frame));

            //check for an error
            if(nBytes < 0){
                perror("Error while trying to read CAN message");
                return false;
            }

            return true;
        }

        bool writeCANMessage(struct can_frame frame){
            if(write(socketFD, &frame, sizeof(frame)) != sizeof(frame)){
                perror("Error while trying to write CAN message");
                return false;
            }
            return true;
        }
};


//used for testing
int main() {
    SocketCANDevice can("can0");

    for(int i = 0; i < 100; i++) {
        can_frame writeFrame{};

        writeFrame.can_id = 0x001;
        writeFrame.len = 5;

        writeFrame.data[0] = 0xDE;
        writeFrame.data[1] = 0xAD;
        writeFrame.data[2] = 0xBE;
        writeFrame.data[3] = 0xEF;
        writeFrame.data[4] = static_cast<uint8_t>(i);

        can.writeCANMessage(writeFrame);

        can_frame frame{};

        if (can.readCANMessage(frame)) {
            printf("ID: 0x%03X  len: %d  Data:",
                   frame.can_id & CAN_SFF_MASK,
                   frame.len);

            for (int i = 0; i < frame.len; ++i) {
                printf(" %02X", frame.data[i]);
            }
            printf("\n");
        }
    }
}