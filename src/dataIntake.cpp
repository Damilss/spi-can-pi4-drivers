#include "dataIntake.h"

#include "../../../shared/common/CANStructs.h"
#include "../../../shared/common/circlequeue.h"
#include "../../../shared/common/peripherals/rtc.h"
#include "../../../shared/drivers/rtos/FreeRTOS.h"
#include "../../../shared/drivers/rtos/task.h"
#include <string.h>

CircleQueue<intakeStruct, DATA_BUFFER_SIZE> dataQueue;
uint8_t payloadBuffer[PAYLOAD_BUFFER_SIZE] = {};

//need to figure out how this will work on PI first
void intakeMessage(can_frame* message) {
    intakeStruct data = {};
    data.id = message->can_id;
    data.dlc = message->len;
    memcpy(data.data, &message->data, sizeof(data.data));
    data.eTime = rtc::ms_getEpochTime();
    //add new can message to the queue for storage
    dataQueue.enqueueOverwrite(data);
}

uint32_t packPayload() {
    uint32_t payloadSize = 0;
    uint8_t* ptr = payloadBuffer;
    intakeStruct data;

    //take an item from the queue, package it into the payload buffer, and track the payload size
    //maximizes data storage efficiency, push as much processing and data onto clients as possible
    while (dataQueue.dequeue(&data) && (payloadSize + MAX_PAYLOAD_FRAME_SIZE) <= sizeof(payloadBuffer)) {
        uint16_t header = (data.id << 5) | (data.dlc << 1);
        memcpy(ptr, &header, sizeof(header));  //add header to payload

        ptr += sizeof(header);
        payloadSize += sizeof(header);

        memcpy(ptr, data.data, data.dlc);  //add data to payload

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