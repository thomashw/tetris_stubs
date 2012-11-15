#include <czmq.h>
#include "command.h"
#include "cJSON.h"
#include "communication.h"

/* creates json string to connect to server */
char* cmd_match_connect_init(struct GameInfo* game_info)
{
	cJSON *root = cJSON_CreateObject();
	cJSON_AddItemToObject(root, "comm_type", cJSON_CreateString("MatchConnect"));
	cJSON_AddItemToObject(root, "team_name", cJSON_CreateString(game_info_get_team_name(game_info)));
	cJSON_AddItemToObject(root, "password", cJSON_CreateString(game_info_get_team_password(game_info)));
	cJSON_AddItemToObject(root, "match_token", cJSON_CreateString(game_info_get_match_token(game_info)));
	return cJSON_PrintUnformatted(root);
}

boolean cmd_match_connect(struct GameInfo* game_info)
{
	printf("Connecting to server...\n");
	char *cmd_connect = cmd_match_connect_init(game_info);
	
	/* connect to game */
	s_send(cmd_socket, cmd_connect);
	free(cmd_connect);

	/* print server response */
	char* reply = s_recv(cmd_socket);

	/* parse client token */
	cJSON* temp = cJSON_Parse(reply);
	free(reply);

	cJSON* obj = cJSON_GetObjectItem(temp, "client_token");
	char* temp_token = (*obj).valuestring;
	game_info_set_client_token(game_info, temp_token);

	printf("Received client token... %s\n", game_info_get_client_token(game_info));
	cJSON_Delete(temp);

	return yes;
}
