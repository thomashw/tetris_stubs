using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ZMQ;

namespace Tetris
{
    class Client
    {
        static void Main(string[] args)
        {
            Client client = new Client();
            client.run(args);
        }

        public void run(string[] args)
        {
            string teamName = null;
            string matchtoken = null;
            string teamPassword = null;
            string hostName = null;

            if (args.Length < 4)
            {
                this.printHelp();
                Environment.Exit(1);
            }

            teamName = args[0];
            teamPassword = args[1];
            matchtoken = args[2];
            hostName = args[3];
            Communication.setHostName(hostName);

            Console.WriteLine("Starting Battle Tetris Client...");

            Command cmd = new Command();
            string connectCommand = cmd.getMatchConnectCommand(teamName, matchtoken, teamPassword);

            Communication comm = Communication.getInstance();
            comm.setSubscription(matchtoken);

            Console.WriteLine("Connecting to server...");
            string clientToken = comm.send(connectCommand, Command.CLIENT_TOKEN);
            Console.WriteLine("Received client token... " + clientToken);

            GameInfo gameInfo = new GameInfo(clientToken, teamName, matchtoken);
            Console.WriteLine("Starting game...");

            //
            // ADD ALGORITHM
            Console.WriteLine("Missing algorithm...");
            ///

            Console.WriteLine("Exiting...");
        }

        public void printHelp()
        {
            Console.WriteLine("usage: Client <team-name> <team-password> <match-token> <host-name>");
        }
    }
}
