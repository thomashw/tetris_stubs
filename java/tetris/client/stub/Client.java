package tetris.client.stub;

import org.zeromq.ZMQ;

final class Client
{
	public static void main(String[] args)
	{
		Client.run(args);
	}

	public static void run(String[] args)
	{
		String teamName = null;
		String matchToken = null;
		String teamPassword = null;
		String hostName = null;

		if(args.length < 4) {
			Client.printHelp();
			return;
		}

		teamName = args[0];
		teamPassword = args[1];
		matchToken = args[2];
		hostName = args[3];
		Communication.setHostName(hostName);

		System.out.println("Starting Battle Tetris Client...");

		Command command = new Command();

		// retrieve the command to connect to the server
		String connectCommand = command.getMatchConnectCommand(teamName, matchToken, teamPassword);

		// retrieve the communication singleton
		Communication comm = Communication.getInstance();
		comm.setSubscription(matchToken);

		// send the command to connect to the server
		System.out.println("Connecting to server...");
		String clientToken = comm.send(connectCommand, Command.Key.CLIENT_TOKEN);
		System.out.println("Received client token... " + clientToken);

		// the GameInfo object will hold the client's name, token, game type, etc.
		GameInfo gameInfo = new GameInfo(clientToken, teamName);

		///
		/// ADD ALGORITHM
		System.out.println("Missing algorithm...");
		///

		System.out.println("Exiting...");
	}

	public static void printHelp()
	{
			System.out.println("usage: Client <team-name> <team-password> <match-token> <host-name>");
	}
}
