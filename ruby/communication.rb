require 'zmq'
require 'json'

class Communication
    def initialize(host_name)
        @context = ZMQ::Context.new(1)

        @pub_socket = @context.socket(ZMQ::SUB)
        @pub_socket.connect('tcp://' + host_name + ':5556')

        @cmd_socket = @context.socket(ZMQ::REQ)
        @cmd_socket.connect('tcp://' + host_name + ':5557')
    end

    def set_sub(value)
        @pub_socket.setsockopt(ZMQ::SUBSCRIBE, value)
    end

    def send(msg, key=nil)
        @cmd_socket.send(msg)
        reply = recv(MessageOrigin::COMMAND_SOCKET)

        json = JSON.parse(reply)
        if key != nil
            json[key]
        else
            json
        end
    end

    def recv(origin)
        if origin == MessageOrigin::PUBLISH_SOCKET
           msg = @pub_socket.recv
        elsif origin == MessageOrigin::COMMAND_SOCKET
           msg = @cmd_socket.recv
        end
    end

    def close
        @pub_socket.close
        @cmd_socket.close
        @context.close
    end

    module MessageOrigin
        PUBLISH_SOCKET = 0
        COMMAND_SOCKET = 1
    end
end