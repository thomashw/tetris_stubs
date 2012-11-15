#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <stdio.h>
#include "type.h"

struct GameInfo;

/* returns a pointer to an initialized game_info struct */
struct GameInfo* game_info_init();

/* prints all members of the game_info struct */
void game_info_print(struct GameInfo*);

/* returns the client token */
char* game_info_get_client_token(struct GameInfo* game_info);\

/* sets the client token */
void game_info_set_client_token(struct GameInfo* game_info, char* client_token);

/* returns the client name */
char* game_info_get_team_password(struct GameInfo* game_info);

/* sets the client name */
void game_info_set_team_password(struct GameInfo* game_info, char* team_password);

// returns the publish socket address
char* game_info_get_match_token(struct GameInfo *game_info);

// sets the publish socket address
// ex. tcp://localhost:5556
void game_info_set_match_token(struct GameInfo *game_info, char *match_token);

// returns the command socket address
char* game_info_get_host_name(struct GameInfo *game_info);

// sets the command socket address
// ex. tcp://localhost:5557
void game_info_set_host_name(struct GameInfo *game_info, char *cmd_socket_address);

/* returns the game name */
char* game_info_get_team_name(struct GameInfo* game_info);

/* sets the game name */
void game_info_set_team_name(struct GameInfo* game_info, char* team_name);

// frees the memory allocated to game_info
void game_info_destroy(struct GameInfo *game_info);

#endif