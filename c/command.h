#ifndef COMMAND_H
#define COMMAND_H

#include "type.h"
#include "game_info.h"

extern void *cmd_socket;

/* connect to the server, receive a client token */
boolean cmd_match_connect(struct GameInfo*);

#endif