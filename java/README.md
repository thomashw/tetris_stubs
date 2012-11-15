# Java Battle Tetris Sample Client

## Running the Client

### Ubuntu
    1. javac -cp /usr/local/share/java/zmq.jar:. tetris/client/stub/Client.java  
    2. java -Djava.library.path=/usr/local/lib -cp /usr/local/share/java/zmq.jar:. tetris.client.stub.Client

### Windows
    1. javac -cp .;C:\zmq\java\lib\zmq.jar tetris\client\stub\Client.java
    2. java -Djava.library.path=C:\zmq\java\lib -cp .;C:\zmq\java\lib\zmq.jar tetris.client.stub.Client

## Dependencies (Already installed on AWS VM's)

### 1. ZeroMQ

[ZeroMQ](http://www.zeromq.org/)

### 2. ZeroMQ Java Binding

[ZeroMQ Java Binding](http://www.zeromq.org/bindings:java)