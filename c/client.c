#include <stdlib.h>
#include "game_info.h"
#include "command.h"
#include "communication.h"
#include "type.h"

const char client_usage_string[] =
	"client <command> [<args>]\n"
	"		-t <team_name>\n"
	"		-p <team_password>\n"
	"		-m <match_token>\n"
	"		-n <host_name>";

/* parses arguments the user supplied when running the app */
boolean do_argv(int* argc, char*** argv, struct GameInfo* game_info)
{
	boolean done = yes;
	if(strcmp(**argv, "-t") == 0) {
		/* move from key "-g" to value */
		(*argv)++;
		(*argc)--;
		game_info_set_team_name(game_info, **argv);
		done = no;
	} else if(strcmp(**argv, "-p") == 0) {
		/* move from key "-n" to value */
		(*argv)++;
		(*argc)--;
		game_info_set_team_password(game_info, **argv);
		done = no;
	} else if(strcmp(**argv, "-m") == 0) {
		(*argv)++;
		(*argc)--;
		game_info_set_match_token(game_info, **argv);
		done = no;
	} else if(strcmp(**argv, "-n") == 0) {
		(*argv)++;
		(*argc)--;
		game_info_set_host_name(game_info, **argv);
		done = no;
	}

	/* move to next command */
	if(done == no) {
		(*argv)++;
		(*argc)--;
	}

	return done;
}

int main(int argc, char **argv)
{
	struct GameInfo *game_info;
	game_info = game_info_init();

	argv++;
	argc--;

	if(argc < 8) {
		printf("usage: %s\n", client_usage_string);
		exit(1);
	}

	while(argc > 0 && !do_argv(&argc, &argv, game_info));

	printf("Starting Battle Tetris Client...\n");

	/* create zeromq socket connections */
	connect_server_init(game_info);

	/* connect to server, get client token */
	cmd_match_connect(game_info);

	///
	/// ADD ALGORITHM
	printf("Missing algorithm...\n");
	///

	printf("Exiting...\n");
	/* destroy */
	connect_server_destroy();
	game_info_destroy(game_info);

	return 0;
}
