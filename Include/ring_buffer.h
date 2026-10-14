#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

#define RING_BUFFER_SIZE 64 //bytes
// keep track of number of elements, head and tail
typedef enum
{
	RING_BUFFER_FULL, // 0
	RING_BUFFER_ERROR,
	RING_BUFFER_SUCCESS,
	RING_BUFFER_HAS_SPACE
} RING_BUFF_STATUS ;

/*

head and tail need to be volatile becuase they are shared by normal execution 
flow and ISR. compiler does not know this

*/
struct ring_buffer {
	volatile size_t head; // how many elements have we pushed
	volatile size_t tail; // how many elements have we popped?
	uint8_t buffer[RING_BUFFER_SIZE]; // buffer itself, 64 elements * 8 bytes per element
	const char* buffer_name;
};

RING_BUFF_STATUS init_buffer(struct ring_buffer *buff, char *name);
RING_BUFF_STATUS add_to_queue(struct ring_buffer *buff, uint8_t value);
RING_BUFF_STATUS pop_from_queue(uint8_t value);
RING_BUFF_STATUS is_buffer_full(struct ring_buffer *buff);


#endif // RING_BUFFER_H_