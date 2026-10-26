/**
 * File: can.h
 * Author: Emilio Ledesma, Trevor Choy
 * Date: 2026-10-11
 *
 * can.h holds the SocketCANDevice class that wraps around the "can0" device
 * that will communicate with the MCP25625 click
 * see boards/Logger/CAN/docs for more information
 */

#ifndef PICAN_H
#define PICAN_H

#include <net/if.h>

#include <linux/can.h>

/**
 * SocketCANDevice class
 */
class SocketCANDevice{
	private:
		int socketFD;
		struct sockaddr_can addr;
		struct ifreq ifr;

	public:
		/**
		 * Constructor for SocketCANDevice class
		 * @Param: const char *canbusName, takes a string literal
		 * 		and uses it as the SocketCanDevice name
		 */
		SocketCANDevice(const char *canbusName);

		/**
		 * readCANMessage() reads a data from a specified CAN
		 * socket
		 * @param: struct can_frame &frame, the meesage from
		 * 		the CAN socket
		 * @return: bool, for if the message was
		 * 		successfully read from the specified
		 * 		socket or not
		 */
		bool readCANMessage(struct can_frame &frame);

		/**
		 * WriteCANMessage writes a can_frame to a specified Socket
		 * @param: struct can_frame frame, this is the can_frame
		 * 		that is being written to the socket
		 * @return: bool, for if the messaage was successfully
		 * 		written to the specified socket or not
		 */
		bool writeCANMessage(struct can_frame frame);


		// TODO: DESTRUCTOR METHOD STILL REQUIRED
};


#endif
