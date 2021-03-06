
#ifndef email_hpp
#define email_hpp
#include "cnformat.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#define MAX_LEN 255
using namespace std;

enum SocketType {
    Server,
    Client
};



class EmailSocket {
    public:
        SocketType typeOfSocket;
        int client_sock;
        int listen_sock;
        struct sockaddr_in server_addr;
        int hostnum;
        int buffSize;
        string run(string message="");
        EmailSocket(SocketType type);
        ~EmailSocket();
    private:
        void connectEmailServer();
        void bindSocket();
        void listenSocket(int listenLog);
        void acceptSocket();
        void sendMessageTo(string message);
        void loopSendAndRecviveMessage();
        string reveiveMessageFrom(bool showMsg=false);
        void closeSocket(int socketData);
};

#endif

