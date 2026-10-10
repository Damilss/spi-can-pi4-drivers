#ifndef __DATA_INTAKE_H
#define __DATA_INTAKE_H

// #includes directory mappping for STMcarcode
// We can adjust as needed
#include "../../../../shared/common/CANStructs.h"
#include "../../../../shared/drivers/rtos/FreeRTOS.h"
#include "../../../../shared/drivers/rtos/task.h"

// On PI; don't worry about errors here
#include <linux/can.h>
#include <linux/can/raw.h>

//how many 8 byte messages can be stored
#define DATA_BUFFER_SIZE 2400

//maximum message length header + data
#define MAX_PAYLOAD_FRAME_SIZE 18 

//how large the buffer should be
#define PAYLOAD_BUFFER_SIZE DATA_BUFFER_SIZE * MAX_PAYLOAD_FRAME_SIZE 

typedef struct {
    uint16_t id;
    uint8_t dlc;
    uint8_t data[8];
    uint64_t eTime;
} intakeStruct;

void intakeMessage(can_frame* message);
uint32_t packPayload();
uint8_t* getPayloadPointer();

#endif
