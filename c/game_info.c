#include <stdlib.h>
#include <string.h>
#include "game_info.h"

struct GameInfo {
	char *client_token;
	char *team_password;
	char *team_name;
	char *match_token;
	char *host_name;
};

size_t game_info_size(void)
{
	return sizeof(struct GameInfo);
}

struct GameInfo* game_info_init()
{
	struct GameInfo *new;
	new = malloc(game_info_size());
	if(new == NULL) exit(1);

	return new;
}

void game_info_print(struct GameInfo* game_info)
{
	printf("client_token: %s\n", game_info->client_token);
	printf("team_password: %s\n", game_info->team_password);
	printf("team_name: %s\n", game_info->team_name);
	printf("match_token: %s\n", game_info->match_token);
	printf("host_name: %s\n", game_info->host_name);
}

char* game_info_get_client_token(struct GameInfo* game_info)
{
	return game_info->client_token;
}

void game_info_set_client_token(struct GameInfo* game_info, char* client_token)
{
	game_info->client_token = malloc(strlen(client_token) + 1);
	strcpy(game_info->client_token, client_token);
}

char* game_info_get_team_password(struct GameInfo* game_info)
{
	return game_info->team_password;
}

void game_info_set_team_password(struct GameInfo* game_info, char* team_password)
{
	game_info->team_password = team_password;
}

char* game_info_get_match_token(struct GameInfo *game_info)
{
	return game_info->match_token;
}

void game_info_set_match_token(struct GameInfo *game_info, char *match_token)
{
	game_info->match_token = match_token;
}

char* game_info_get_host_name(struct GameInfo *game_info)
{
	return game_info->host_name;
}

void game_info_set_host_name(struct GameInfo *game_info, char *host_name)
{
	game_info->host_name = host_name;
}

char* game_info_get_team_name(struct GameInfo* game_info)
{
	return game_info->team_name;
}

void game_info_set_team_name(struct GameInfo* game_info, char* team_name)
{
	game_info->team_name = team_name;
}

void game_info_destroy(struct GameInfo *game_info)
{
	free(game_info->client_token);
	free(game_info);
}
