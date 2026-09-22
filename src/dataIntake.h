#ifndef __DATA_INTAKE_H
#define __DATA_INTAKE_H

#include "../../../shared/common/CANStructs.h"
#include "../../../shared/drivers/rtos/FreeRTOS.h"
#include "../../../shared/drivers/rtos/task.h"

#include <linux/can.h>
#include <linux/can/raw.h>

#define DATA_BUFFER_SIZE 2400 //how many 8 byte messages can be stored
#define MAX_PAYLOAD_FRAME_SIZE 18 //maximum message length header + data
#define PAYLOAD_BUFFER_SIZE DATA_BUFFER_SIZE * MAX_PAYLOAD_FRAME_SIZE //how large the buffer should be

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