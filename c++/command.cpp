#include <iostream>
using namespace std;

#include "command.h"
#include "cJSON.h"
#include "gameInfo.h"

const string Command::Keys::TEAM_NAME = "team_name";
const string Command::Keys::CLIENT_TOKEN = "client_token";
const string Command::Keys::COMM_TYPE = "comm_type";
const string Command::Keys::MATCH_CONNECT = "MatchConnect";

string Command::getMatchConnectCommand(GameInfo gameInfo)
{
  cJSON *root = cJSON_CreateObject();
  cJSON_AddItemToObject(root, "comm_type", cJSON_CreateString("MatchConnect"));
  cJSON_AddItemToObject(root, "team_name", cJSON_CreateString(gameInfo.getTeamName().c_str()));
  cJSON_AddItemToObject(root, "password", cJSON_CreateString(gameInfo.getTeamPassword().c_str()));
  cJSON_AddItemToObject(root, "match_token", cJSON_CreateString(gameInfo.getMatchToken().c_str()));
  return cJSON_PrintUnformatted(root);
}
