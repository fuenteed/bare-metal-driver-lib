#include "ring_buffer.h"

RING_BUFF_STATUS init_buffer(struct ring_buffer *buff, char *name)
{
	buff->buffer_name = name;
	buff->head = 0;
	buff->tail = 0;
	return RING_BUFFER_SUCCESS;
}

RING_BUFF_STATUS is_buffer_full(struct ring_buffer *buff)
{
	// if head - tail == head then full
	// example: if we have added 8 elements, then head = 64
	// tail = 0, then the difference should be 
	if(buff->head - buff->tail >= RING_BUFFER_SIZE) {
		return RING_BUFFER_FULL;
	}else {
		return RING_BUFFER_HAS_SPACE;
	}
}

// write the byte 'value' into the ring buffer
RING_BUFF_STATUS  add_to_queue(struct ring_buffer *buff, uint8_t value)
{
	
	//first check if the buffer is full
	if (is_buffer_full(buff)){

	}


	// if we are allowed to add element, then add it
	buff->buffer[buff->head % RING_BUFFER_SIZE] = value;
	buff->head += 1; // add 1 to it to add a byte.
	return RING_BUFFER_SUCCESS;
}

RING_BUFF_STATUS pop_from_queue(struct ring_buffer *buff)
{


	buff->tail += 1;
	return RING_BUFFER_SUCCESS;
}

