#include <stdbool.h>
#include <stdint.h>
#include "constants.h"

#ifndef UTILS_H_
#define UTILS_H_

#define MAX_SIZE 255

/**
* struct used to represent a single request
* .cmd = command e.g. GET, SET, ...
* .res = resource, 0-32, theoretically could be more
* .len = length of data being sent in bytes
* .data = request data
*
*/
typedef struct request {
    uint16_t cmd;
    uint16_t res;
    uint16_t len;
    char data[MAX_SIZE + 1];
} request;

/**
* struct represting a single response
* .status = response status, e.g. OK, ERROR, ...
* .len = length of message being sent
* .data = reponse data
*
*/
typedef struct response {
    uint16_t status;
    uint16_t len;
    char *data;
} response;

typedef struct response_lm {
    uint16_t status;
    uint32_t time;
} response_lm;

/**
* shortuct for perror() & exit(1)
*/
void dieWithError(char const *errorMessage);

/**
* reads 4 bytes from a socet into a usigned 16 bit integer
* @returns true on success
*/
bool read_uint16(int sock, uint16_t *num);

/**
* reads <len> bytes from socket into <buffer>,
* appends null terminator to the end
* @returns true on success
*/
bool read_str(int sock, char *buffer, int len);

bool send_id(int sock, uint16_t id);

bool send_uint16(int sock, uint16_t num);

#endif
