#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "gameInfo.h"
#include "command.h"
#include "communication.h"

static const char client_usage_string[] =
"client <command> [<args>]\n"
"   -t <team_name>\n"
"   -p <team_password>\n"
"   -m <match_token>\n"
"   -n <host_name>";

class Client
{
public:
  void run(int argc, char* argv[]);
};

void do_argv(int* argc, char*** argv, GameInfo &gameInfo)
{
  while(true) {
    if(strcmp(**argv, "-t") == 0) {
      (*argv)++;
      (*argc)--;
      gameInfo.setTeamName(**argv);
    } else if(strcmp(**argv, "-p") == 0) {
      (*argv)++;
      (*argc)--;
      gameInfo.setTeamPassword(**argv);
    } else if(strcmp(**argv, "-m") == 0) {
      (*argv)++;
      (*argc)--;
      gameInfo.setMatchToken(**argv);
    } else if(strcmp(**argv, "-n") == 0) {
      (*argv)++;
      (*argc)--;
      gameInfo.setHostName(**argv);
    }

    // move to next command
    if(*argc > 1) {
      (*argv)++;
      (*argc)--;
    } else {
      break;
    }
  }
}

void Client::run(int argc, char* argv[])
{
  argv++;
  argc--;

  if(argc < 8) {
    cout << "usage: " << client_usage_string << endl;
    exit(1);
  }

  GameInfo gameInfo;
  do_argv(&argc, &argv, gameInfo);

  cout << "Starting Battle Tetris Client..." << endl;

  Command command;
  string connectCmd = command.getMatchConnectCommand(gameInfo);

  cout << "Connecting to server..." << endl;

  Communication comm(gameInfo.getHostName());
  string clientToken = comm.send(connectCmd, Command::Keys::CLIENT_TOKEN);
  gameInfo.setClientToken(clientToken);

  cout << "Received client token... " << gameInfo.getClientToken() << endl;
  cout << "Starting game..." << endl;
  ///
  /// ADD ALGORITHM
  cout << "Missing algorithm..." << endl;
  ///

  cout << "Exiting..." << endl;
}

int main(int argc, char* argv[])
{
  Client client;
  client.run(argc, argv);
}