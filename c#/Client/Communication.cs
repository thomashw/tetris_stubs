using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ZMQ;
using Newtonsoft.Json;

namespace Tetris
{
    class Communication
    {
        public enum MessageOrigin {
            PublishSocket = 0,
            CommandSocket
        };

        private static string PUB_SOCKET_ADDR;
        private static string CMD_SOCKET_ADDR;

        private static Communication instance;
        private ZMQ.Context context;
        private ZMQ.Socket pubSocket;
        private ZMQ.Socket cmdSocket;

        private Communication()
        {
            this.context = new ZMQ.Context(1);
            this.pubSocket = context.Socket(SocketType.SUB);
            this.cmdSocket = context.Socket(SocketType.REQ);

            pubSocket.Connect(PUB_SOCKET_ADDR);
            cmdSocket.Connect(CMD_SOCKET_ADDR);
        }

        public static Communication getInstance()
        {
            if (instance == null)
            {
                instance = new Communication();
            }

            return instance;
        }

        public static void setHostName(string hostName)
        {
            Console.WriteLine("Setting host name...");
            PUB_SOCKET_ADDR = "tcp://" + hostName + ":5556";
            CMD_SOCKET_ADDR = "tcp://" + hostName + ":5557";
        }

        public void setSubscription(string value)
        {
            System.Text.ASCIIEncoding enc = new System.Text.ASCIIEncoding();
            pubSocket.SetSockOpt(SocketOpt.SUBSCRIBE, enc.GetBytes(value));
        }

        public string send(string message, string key)
        {
            string reply = send(message);
            Dictionary<string, string> dict = JsonConvert.DeserializeObject<Dictionary<string, string>>(reply);

            return dict[key];
        }

        public string send(string message)
        {
            cmdSocket.Send(message, Encoding.ASCII);
            return receive(MessageOrigin.CommandSocket);
        }

        public string receive(MessageOrigin origin)
        {
            string msg = "";

            switch (origin)
            {
                case MessageOrigin.CommandSocket:
                    msg = cmdSocket.Recv(Encoding.ASCII);
                    break;
                case MessageOrigin.PublishSocket:
                    msg = pubSocket.Recv(Encoding.ASCII);
                    break;
                default:
                    break;
            }

            return msg;
        }
    }
}
