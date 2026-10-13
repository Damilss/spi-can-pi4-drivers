/**
 * file: dataIntake.cpp
 * author: Emilio Ledesma, Trevor Choy
 * date: 2026-10-11
 *
 * functions for dataIntake API recieving CAN_frame data from can0 interface
 *
 */


#include "dataIntake.h"

#include "../../../../shared/common/circlequeue.h"

#include <time.h>
#include <string.h>
#include <stdint.h>
#include <linux/can.h>
#include <linux/can/raw.h>

CircleQueue<intakeStruct, DATA_BUFFER_SIZE> dataQueue;
uint8_t payloadBuffer[PAYLOAD_BUFFER_SIZE] = {};

void intakeMessage(can_frame *message) {

	// create intake struct to format data	
	intakeStruct data;

	/**
	* returns prematurely if CAN_EFF_FLAG is set, prevents obtaining
	* botched data and sending it to client; If we we wanna implement
	* intaking extended format CAN messages we have to change the 
	* intake format
	*/
	if(message->can_id & CAN_EFF_FLAG){
		return;
	}

	// expllicitly mask standard format
	data.id = message->can_id & CAN_SFF_MASK;
	data.dlc = message->len;
	memcpy(data.data, &message->data, sizeof(data.data));    

	//set struct to pull time from
	struct timespec ts;
	
	// get current time from systemwide clock and store it in ts
	clock_gettime(CLOCK_REALTIME, &ts);

	// .eTime is in the the format of ms (milliseconds)
	// each mulitplication operation needs their own seperate cast then
	// add together
	uint64_t sec_to_ms = (uint64_t)ts.tv_sec * 1000;
	uint64_t ns_to_ms = (uint64_t)ts.tv_nsec / 1000000;
	data.eTime = sec_to_ms + ns_to_ms;

	// add new can message to the queue for storage
    	dataQueue.enqueueOverwrite(data);
}

uint32_t packPayload() {
	uint32_t payloadSize = 0;
	uint8_t *ptr = payloadBuffer;
	intakeStruct data;

	// take an item from the queue, package it into the payload buffer,
	// and track the payload size
	// maximizes data storage efficiency, push as much processing and
	// data onto clients as possible
	while (
		dataQueue.dequeue(&data) && 
		(payloadSize + MAX_PAYLOAD_FRAME_SIZE) <= 
		sizeof(payloadBuffer)
	) {
		uint16_t header = (data.id << 5) | (data.dlc << 1);

		// add header to payload
		memcpy(ptr, &header, sizeof(header));

        	ptr += sizeof(header);
        	payloadSize += sizeof(header);
	
		// add data to payload
        	memcpy(ptr, data.data, data.dlc);

        	ptr += data.dlc;
        	payloadSize += data.dlc;

        	memcpy(ptr, &data.eTime, sizeof(uint64_t));

        	ptr += sizeof(uint64_t);
		payloadSize += sizeof(uint64_t);
    }

    return payloadSize;
}
uint8_t* getPayloadPointer() {
	return payloadBuffer;	
}
