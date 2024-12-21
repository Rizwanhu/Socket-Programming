#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;


#include <WS2tcpip.h>


// initialize winisock library

// create the socket

// get ip and port 

// bind the ip/port 

// listen on the socket 

// accept 

// receive and then send

// close the socket

// cleanup the winsock

/*
void Run(int argc, char* argv[])
{
    // Validate input
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <hostname>\n";
        return;
    }

    char* host = argv[1];
    struct hostent* entry = gethostbyname(host);

    if (entry)
    {
        struct in_addr* addr = (struct in_addr*)entry->h_addr;
        cout << "IP Address: " << inet_ntoa(*addr) << endl;
    }
    else
    {
        cerr << "ERROR: Resolution failure for host: " << host << ".\n";
    }
}
*/


bool Initialize() {

    // made a wsadata to store the data for socket
    WSADATA wsaData;

    // Initialize Winsock
    // return if socket is connected or not
    return (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0);
    
}



int main() {

    if (!Initialize()) {
        cout << "min socket not initialized...." << endl;
    }
    else {
        cout << "Connected yea..." << endl;
    }

	cout << "server program" << endl;

    // create socket:

    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (listenSocket == INVALID_SOCKET) {
        cout << "socket creation failed " << endl;
    }
    else {
        cout << "connected..." << endl;
    }

    WSACleanup();

	return 0;
}