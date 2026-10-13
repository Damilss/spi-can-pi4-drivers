/**
 * file: CANtest.cpp
 * Author: Emilio ledesma, Trevor Choy
 * Date: 2026-10-11
 *
 * test file for socketCAN drivers for Rapsberrypi CM4, see
 * boards/Logger/CAN/docs for more information
 * 
 */

#include "can.h"

#include <stdio.h>
#include <stdint.h>



/**
 * main(), entry point for CANtest test function creates a SocketCANDevice,
 * defined in ../../../../shared/drivers/cm4/can.cpp, then writes byte, by
 * byte to a frame then writes the frame to the socketCANDevice, then
 * prints out message
 *
 * @return: int, exit status 
 */
  int main() {

	//tests class in can.h
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

            //set struct to pull time from
            struct timespec ts;
            
            // get current time from systemwide clock and store it in ts
            clock_gettime(CLOCK_REALTIME, &ts);

            // .timestamp is in nanoseconds (ns)
            // each mulitplication operation needs their own seperate cast then
            // add together
            uint64_t sec_to_ns = (uint64_t)ts.tv_sec * 1000000000;
            uint64_t ns_to_ms = (uint64_t)ts.tv_nsec;

            uint64_t timestamp = sec_to_ms + ns_to_ms;

            printf("ID: 0x%03X  len: %d  timestamp: %d, Data:",
                frame.can_id & CAN_SFF_MASK,
                frame.len,
                timestamp);

            for (int i = 0; i < frame.len; ++i) {
                printf(" %02X", frame.data[i]);
            }
            printf("\n");
        }
    }
}
