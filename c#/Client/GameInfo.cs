using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Tetris
{
    class GameInfo
    {
        private string clientToken;
        private string teamName;
        private string matchToken;

        public GameInfo(string clientToken,
            string teamName,
            string matchToken)
        {
            this.clientToken = clientToken;
            this.teamName = teamName;
            this.matchToken = matchToken;
        }

        public string getClientToken()
        {
            return clientToken;
        }

        public string getTeamName()
        {
            return teamName;
        }
    }
}
