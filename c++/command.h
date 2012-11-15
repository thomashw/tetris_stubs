#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

#include "gameInfo.h"

class Command
{
public:
  string getMatchConnectCommand(GameInfo gameInfo);

  class Keys
  {
  public:
    static const string TEAM_NAME;
    static const string CLIENT_TOKEN;
    static const string COMM_TYPE;
    static const string MATCH_CONNECT;
  };
};

#endif