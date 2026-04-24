#ifndef CLI_H_
#define CLI_H_

#include <stddef.h>

#define BUFFER_SIZE 128
#define NULL_TERM '\r'

//the command line can have several commands concurrently running
//so we should initialize a single terminal which can have severl commands running at once.


//curent command
//the command owns the string itself.
typedef struct {

    char* cmd; 

} command;


//instance of command line interface
typedef struct {

    command *cmds; //array of commands
    size_t num_cmds; //length of array of commands

} cli;


#endif /*CLI_H_*/