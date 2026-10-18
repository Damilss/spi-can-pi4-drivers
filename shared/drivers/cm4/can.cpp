/**
 * file: can.cpp
 * author: Emilio Ledesma, Trevor Choy
 * date: 2026-10-11
 *
 * can.cpp holds the definitions for the socketCANDevice in can.h
 * see can.h for more info
 * see boards/Logger/CAN/docs for more info
 */

#include "can.h"

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

// Constuctor Definition for SocketCANDevice
SocketCANDevice::SocketCANDevice (const char *canbusName){

	//create socket (this is for RAW can)
	if (((socketFD = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)){
		perror("SocketCANDevice(): creating socket failed");
		throw std::runtime_error(
				"SocketCANDevice(): Failed to create "
				"SocketCAN socket"
				);
	}

	// send the canbus name through an ifreq struct
	strcpy(ifr.ifr_name, canbusName);

	if(ioctl(socketFD, SIOCGIFINDEX, &ifr)< 0){
		perror(
			"SocketCANDevice(): getting CAN interface index "
			"failed"
			);
		throw std::runtime_error(
				"SocketCANDevice(): getting CAN interface "
				"index failed"
				);
	}

	// bind socket to CAN interface
	memset(&addr, 0, sizeof(addr));
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if(bind(socketFD, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("SocketCANDevice(): binding socket failed");
		throw std::runtime_error(
				"SocketCANDevice(): binding socket failed"
				);
	}
}

bool SocketCANDevice::readCANMessage(struct can_frame &frame){

	// read the data (the frame passed will get data)
	int status = read(socketFD, &frame, sizeof(frame));

	//check status for err
	if (status < 0){
		perror(
			"readCANMessage(): Error while trying to read can "
				"message"
			);
		return false;
	}

	return true;
}

bool SocketCANDevice::writeCANMessage(struct can_frame frame){

	if(write(socketFD, &frame, sizeof(frame)) != sizeof(frame)){
		perror(
			"writeCANMessage(): Error while trying to write "
			"CAN message"
				);
		return false;
	}

	return true;
}
