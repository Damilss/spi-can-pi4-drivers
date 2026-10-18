/**
 * file: dataIntake.h
 * author: Emilio Ledesma, Trevor Choy
 * date: 2026-10-11
 *
 * dataIntake.h provides the declarations and descriptions for
 * intakeMessage, packPayload, and getPayloadPointer
 *
 */
#ifndef __DATA_INTAKE_H
#define __DATA_INTAKE_H

#include <stdint.h>
#include <linux/can.h>

// how many can frames can be stored
#define DATA_BUFFER_SIZE 2400

// maximum message length header + data + timestamp
#define MAX_PAYLOAD_FRAME_SIZE 18

// how large the buffer should be
#define PAYLOAD_BUFFER_SIZE (DATA_BUFFER_SIZE * MAX_PAYLOAD_FRAME_SIZE)

/**
 * intakeStruct is a formatted way to hold all the data from the can_frame
 * uint16_t id holds id for can_frame, gets merged into the same header
 * with dlc
 *
 * uint8_t dlc, data length code, gets merged into the same header with
 * id. data length specifies how long the data section is
 *
 * uint8_t data[8], data section
 *
 * uint64_t eTime, timestamp where the time is given in milliseconds from
 * unix epoch. time is obtained right before data gets enqueued (see
 * intakeMessage())
 */
typedef struct {
	uint16_t id;
	uint8_t dlc;
	uint8_t data[8];
	uint64_t eTime;
} intakeStruct;

/**
 * intakeMessage formats inputted can_frame *message and adds message to a set
 * queue, if buffer is full, overwrites and returns the last item and
 * continues to enqueue specified item. If inputted CAN frame is extended
 * format, return and don't intake it, this could cause formatting issues
 * with the ID and give botched data. Possible future implementation would
 * have to change the format of how data gets taken in.
 * remember CAN is little-endian.
 *
 * @param: can_frame *message, can_frame to be formatted and to be set to
 * 		queue
 * @return: void
 */
void intakeMessage(can_frame* message);

/**
 * packPayload(): takes an item from the queue, packages it into the payload
 * buffer, and tracks the payload size, while maximizing storage efficiency,
 * pushing as much data onto the clients as posssible.
 * One payload frame is 10-18 bytes, depending on data frame size
 *
 * Header - 2 bytes, combining the id, which are bits 5-15, and dlc,
 * which are bits 1-4, bit 0 is always unset
 *
 * data - variable from 0-8 bytes set by the dlc
 *
 * eTime - 8 bytes, is the time in ms since unix epoch
 *
 * @return: uint32_t, returns the new size of the paylaad after packing
 */
uint32_t packPayload();

/**
 * getPayloadPointer returns the entire payload
 *
 * Type: uint8_t[PAYLOAD_BUFFER_SIZE]
 *
 * return: returns pointer for the payloadBuffer
 */
uint8_t* getPayloadPointer();

#endif
