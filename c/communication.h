#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "game_info.h"

extern void *context;
extern void *pub_socket;
extern void *cmd_socket;

// initializes tcp connections to the server
void connect_server_init(struct GameInfo *game_info);

// closes socket connections to the server
void connect_server_destroy();

/* receive messages from socket */
char* s_recv (void *socket);

/* send messages on socket */
int s_send (void *socket, char *string);

#endif
