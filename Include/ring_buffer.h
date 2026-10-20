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
	RING_BUFFER_ERROR, // 1
	RING_BUFFER_SUCCESS, // 2
	RING_BUFFER_HAS_SPACE, // 3
	RING_BUFFER_EMPTY, // 4
	RING_BUFFER_NOT_EMPTY // 5
} RING_BUFF_STATUS ;

/*

head and tail need to be volatile becuase they are shared by normal execution 
flow and ISR. compiler does not know this

*/
struct ring_buffer {
	volatile size_t head; // how many elements have we pushed
	volatile size_t tail; // how many elements have we popped?
	volatile uint8_t buffer[RING_BUFFER_SIZE]; // buffer itself, 64 elements * 8 bytes per element
};

RING_BUFF_STATUS init_buffer(struct ring_buffer *buff);
RING_BUFF_STATUS add_to_queue(struct ring_buffer *buff, uint8_t value);
uint8_t pop_from_queue(struct ring_buffer *buff);
RING_BUFF_STATUS is_buffer_full(struct ring_buffer *buff);


#endif // RING_BUFFER_H_