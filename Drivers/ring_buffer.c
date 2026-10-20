#include "ring_buffer.h"

void buff_set(struct ring_buffer *buff, uint8_t value)
{
	for(int i = 0; i < RING_BUFFER_SIZE; i++)
		buff->buffer[i] = value;
}

RING_BUFF_STATUS init_buffer(struct ring_buffer *buff)
{
	buff->head = 0;
	buff->tail = 0;
	buff_set(buff, 0);
	return RING_BUFFER_SUCCESS;
}

RING_BUFF_STATUS is_buffer_full(struct ring_buffer *buff)
{
	// if head - tail >= buffer size
	// example: if we have added 8 elements, then head = 64
	// tail = 0, then the difference should be 
	if(buff->head - buff->tail >= RING_BUFFER_SIZE) {
		return RING_BUFFER_FULL;
	}else {
		return RING_BUFFER_HAS_SPACE;
	}
}

RING_BUFF_STATUS is_buffer_empty(struct ring_buffer *buff)
{
	// if index same, but not full then its empty
	if(buff->head == buff->tail && !(is_buffer_full(buff) == RING_BUFFER_FULL))
		return RING_BUFFER_EMPTY;
	else
	 	return RING_BUFFER_NOT_EMPTY;
}

// write the byte 'value' into the ring buffer
RING_BUFF_STATUS add_to_queue(struct ring_buffer *buff, uint8_t value)
{
	//first check if the buffer is full -> if it is then we need to pop from the tail
	if (is_buffer_full(buff) == RING_BUFFER_FULL){
		pop_from_queue(buff);
	}

	// if we are allowed to add element, then add it
	buff->buffer[buff->head % RING_BUFFER_SIZE] = value;
	buff->head = buff->head + 1 % RING_BUFFER_SIZE; // add 1 to it to add a byte.
	return RING_BUFFER_SUCCESS;
}

// return popped element
uint8_t pop_from_queue(struct ring_buffer *buff)
{
	// grab the element popped, store it
	uint8_t popped = buff->buffer[buff->tail % RING_BUFFER_SIZE];
	buff->buffer[buff->tail % RING_BUFFER_SIZE] = 0;
	buff->tail = buff->tail + 1 % RING_BUFFER_SIZE;
	return popped;
}

