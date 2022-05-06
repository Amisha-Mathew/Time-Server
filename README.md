# Time-Server

A TIME server which gives the following services by contacting an actual time server 
> Timezone selection 
> Time Synchronization

To execute the program, open 2 terminals
1. On the first terminal, compile the program: gcc client.c -o client
2. Second terminal- ./server 4444
3. First terminal- ./client 4444

The server listens for the clients and the client obtains the time from the server
