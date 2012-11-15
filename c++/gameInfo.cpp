#include <iostream>
#include <stdlib.h>
using namespace std;

#include "gameInfo.h"

GameInfo::GameInfo()
{
  _clientToken = "";
}

void GameInfo::setClientToken(string clientToken)
{
  _clientToken = clientToken;
}

void GameInfo::setTeamName(string teamName)
{
  _teamName = teamName;
}

void GameInfo::setTeamPassword(string teamPassword)
{
  _teamPassword = teamPassword;
}

void GameInfo::setMatchToken(string matchToken)
{
  _matchToken = matchToken;
}

void GameInfo::setHostName(string hostName)
{
  _hostName = hostName;
}

string GameInfo::getClientToken()
{
  return _clientToken;
}

string GameInfo::getTeamName()
{
  return _teamName;
}

string GameInfo::getTeamPassword()
{
  return _teamPassword;
}

string GameInfo::getMatchToken()
{
  return _matchToken;
}

string GameInfo::getHostName()
{
  return _hostName;
}

void GameInfo::print()
{
  cout << "teamName: " << _teamName << endl;
  cout << "teamPassword: " << _teamPassword << endl;
  cout << "matchToken: " << _matchToken << endl;
  cout << "hostName: " << _hostName << endl;
}
