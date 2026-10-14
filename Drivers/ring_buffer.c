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
	if(buff->head - buff->tail >= RING_BUFFER_SIZE) {
		return RING_BUFFER_FULL;
	}else {
		return RING_BUFFER_HAS_SPACE;
	}
}

void add_to_queue(struct ring_buffer *buff, uint8_t value)
{
	
	

	// if we are allowed to add element, then add it
	buff->buffer[buff->head % RING_BUFFER_SIZE] = value;
}

void pop_from_queue(uint8_t value)
{

}

