# C# Battle Tetris Sample Client

## Dependencies

### 1. ZeroMQ

[ZeroMQ](http://www.zeromq.org/)

### 2. ZeroMQ C# Binding

[ZeroMQ C# Binding](http://www.zeromq.org/bindings:clr)

## Running the Client

### On AWS

1. Copy the clrzmq.dll and clrzmq-ext.dll's into the Client folder
2. Open the pre-installed Microsoft Windows SDK 7.1 Command Prompt
3. Change to the client folder using `cd`
4. Invoke the C# compiler using `csc /reference:clrzmq.dll /reference:Newtonsoft.Json.dll *.cs`
5. Run your client by typing the name of the generated binary

### Note

The included Newtonsoft.Json.dll is 32-bit. On a 64-bit system you may need to either get a 64-bit version or recompile the Newtonsoft.Json.dll for 64-bit.

Precompiled dll's and the source are found here: http://james.newtonking.com/pages/json-net.aspx