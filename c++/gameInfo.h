#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <string>
using namespace std;

class GameInfo
{
public:
  GameInfo();
  void setClientToken(string clientToken);
  void setTeamName(string teamName);
  void setTeamPassword(string teamPassword);
  void setMatchToken(string matchToken);
  void setHostName(string hostName);

  string getClientToken();
  string getTeamName();
  string getTeamPassword();
  string getMatchToken();
  string getHostName();

  void print();

private:
  string _clientToken;
  string _teamName;
  string _teamPassword;
  string _matchToken;
  string _hostName;
};

#endif