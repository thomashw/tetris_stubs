#include <czmq.h>
#include "communication.h"

/* zmq */
void *context;
void *pub_socket;
void *cmd_socket;

/* create server socket connections */
void connect_server_init(struct GameInfo *game_info)
{
    char *host_name = game_info_get_host_name(game_info);
    int size = snprintf(NULL, 0, "tcp://%s:5556", host_name) + 1;
    char *pub_address = malloc(size);
    char *cmd_address = malloc(size);

    sprintf(pub_address, "tcp://%s:5556", host_name);
    sprintf(cmd_address, "tcp://%s:5557", host_name);

    printf("Creating zeromq connections...\n");
	context = zmq_init(1);

	pub_socket = zmq_socket(context, ZMQ_SUB);
	cmd_socket = zmq_socket(context, ZMQ_REQ);

	zmq_connect(pub_socket, pub_address);
    zmq_connect(cmd_socket, cmd_address);

    zmq_setsockopt(pub_socket, ZMQ_SUBSCRIBE, "", 0);
}

/* close server socket connections */
void connect_server_destroy()
{
	zmq_close(pub_socket);
	zmq_close(cmd_socket);
	zmq_term(context);
}

//  Receive 0MQ string from socket and convert into C string
//  Caller must free returned string. Returns NULL if the context
//  is being terminated.
char* s_recv(void *socket)
{
    zmq_msg_t message;
    zmq_msg_init (&message);
    if (zmq_recv (socket, &message, 0) == -1)
        return NULL;

    void *msg_data = zmq_msg_data(&message);
    int size = zmq_msg_size(&message);
    char *string = malloc (size + 1);
    if(string == NULL) exit(1);

    memcpy (string, msg_data, size);
    zmq_msg_close (&message);
    string [size] = 0;
    return (string);
}

//  Convert C string to 0MQ string and send to socket
int s_send(void *socket, char *string)
{
    zmq_msg_t message;
    zmq_msg_init_size (&message, strlen (string));
    memcpy (zmq_msg_data (&message), string, strlen (string));
    int size = zmq_send (socket, &message, 0);
    zmq_msg_close (&message);
    return (size);
}
