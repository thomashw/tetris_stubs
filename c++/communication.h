#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <zmq.hpp>

class Communication
{
private:
  zmq::context_t context;
  zmq::socket_t pub_socket;
  zmq::socket_t cmd_socket;

public:
  enum MessageOrigin {
    PublishSocket = 0,
    CommandSocket
  };

  Communication(string hostName);

  string send(string msg);
  string send(string msg, string key);
  string receive(MessageOrigin origin);
};

#endif