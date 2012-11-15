using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Newtonsoft.Json;

namespace Tetris
{
    class Command
    {
        private string COMM_TYPE = "comm_type";
        private string TEAM_NAME = "team_name";
        private string MATCH_TOKEN = "match_token";
        public static string CLIENT_TOKEN = "client_token";
        private string MATCH_CONNECT = "MatchConnect";
        private string PASSWORD = "password";

        public string getMatchConnectCommand(string teamName, string matchToken, string teamPassword)
        {
            Dictionary<string, string> dict = new Dictionary<string, string>();
            dict.Add(COMM_TYPE, MATCH_CONNECT);
            dict.Add(TEAM_NAME, teamName);
            dict.Add(MATCH_TOKEN, matchToken);
            dict.Add(PASSWORD, teamPassword);
            return JsonConvert.SerializeObject(dict);
        }
    }
}
