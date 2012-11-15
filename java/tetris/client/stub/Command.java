package tetris.client.stub;

import org.json.JSONObject;
import org.json.JSONException;

final class Command
{
	class Key {
		private static final String TEAM_NAME = "team_name";
		public static final String CLIENT_TOKEN = "client_token";
		private static final String COMM_TYPE = "comm_type";
		private static final String MATCH_TOKEN = "match_token";
		private static final String PASSWORD = "password";

		class CommType {
			private static final String MATCH_CONNECT = "MatchConnect";
		}
	}

	public String getMatchConnectCommand(String teamName, String matchToken, String teamPassword)
	{
		JSONObject json = new JSONObject();

		try {
			json.put(Key.COMM_TYPE, Key.CommType.MATCH_CONNECT);
			json.put(Key.TEAM_NAME, teamName);
			json.put(Key.MATCH_TOKEN, matchToken);
			json.put(Key.PASSWORD, teamPassword);
		} catch(JSONException e) {
			System.err.println("[Command connectCommand] couldn't create command");
			return null;
		}

		return json.toString();
	}
}