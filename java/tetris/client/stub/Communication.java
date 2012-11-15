package tetris.client.stub;

import org.zeromq.ZMQ;
import org.json.JSONObject;
import org.json.JSONException;

final class Communication
{
	enum MessageOrigin {
		PublishSocket,
		CommandSocket
	};

	private static Communication instance = null;

	private static String PUB_SOCKET_ADDR;
	private static String CMD_SOCKET_ADDR;

	private ZMQ.Context context;
	private ZMQ.Socket pubSocket;
	private ZMQ.Socket cmdSocket;
	private String pubSocketAddress;
	private String cmdSocketAddress;

	private Communication()
	{
		context = ZMQ.context(1);
		pubSocket = context.socket(ZMQ.SUB);
		cmdSocket = context.socket(ZMQ.REQ);

		pubSocket.connect(PUB_SOCKET_ADDR);
		cmdSocket.connect(CMD_SOCKET_ADDR);
	}

	public static Communication getInstance()
	{
		if(instance == null) {
			System.out.println("Creating zeromq connections...");
			instance = new Communication();
		}

		return instance;
	}

	public static void setHostName(String hostName)
	{
		System.out.println("Setting host name...");
		PUB_SOCKET_ADDR = "tcp://" + hostName + ":5556";
		CMD_SOCKET_ADDR = "tcp://" + hostName + ":5557";
	}

	public void setSubscription(String value)
	{
		pubSocket.subscribe(value.getBytes());
	}

	public String send(String message)
	{
		byte[] bytes = message.getBytes();
		cmdSocket.send(bytes, 0);

		// wait for reply
		return receive(Communication.MessageOrigin.CommandSocket);
	}

	public String send(String message, String key)
	{
		String reply = send(message);
		JSONObject json = null;
		String value = null;

		try {
			json = new JSONObject(reply);
		} catch(JSONException e) {
			System.err.println("[Communication send] couldn't create JSONObject from reply");
			return null;
		}

		try {
			value = json.getString(key);
		} catch(JSONException e) {
			System.err.println("[Communication send] couldn't extract value for key: " + key + " from reply");
			return null;
		}

		return value;
	}

	public String receive(MessageOrigin origin)
	{
		byte[] bytes = null;
		switch(origin) {
			case PublishSocket:
				bytes = pubSocket.recv(0);
				break;
			case CommandSocket:
				bytes = cmdSocket.recv(0);
				break;
			default:
				break;
		}

		return new String(bytes);
	}
}