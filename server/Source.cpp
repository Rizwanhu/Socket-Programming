#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <tchar.h>

#include <WS2tcpip.h> // For InetPton

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

string serveraddr = "127.0.0.1";
//int port = 1234;

int main() {


    SOCKET s;

    //s= socket(AF_INRT)



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


    // create address structure

    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(1234);
    int port = 1234;

    // convert the ip put it in binary form
    if (InetPton(AF_INET, _T("0.0.0.0"), &serveraddr.sin_addr) != 1) {
        cout << "setting address structure failed..." << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;

    }



    // Bind the socket to the address and port
    if (bind(listenSocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == SOCKET_ERROR) {
        cerr << "Binding failed." << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }
    cout << "Socket successfully bound to address and port." << endl;



    // listen

    // Create a listening socket
    //SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen(listenSocket, SOMAXCONN)==SOCKET_ERROR) {
        cerr << "Failed to create socket." << endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    } 

    cout << "server running on" << port << endl;




    // accept

    SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);

    if (clientSocket==INVALID_SOCKET)
    {
        cout << "invalid client socket....." << endl;
    }



    // recieve client socekt

    char buffer[4096];
    int bytes_recieved = recv(clientSocket, buffer, sizeof(buffer), 0);
    string message(buffer, bytes_recieved);
    cout << "message recieved form client...." << endl;

    cout << endl << "-----------------------" << endl << message << endl << "---------------------" << endl;



    closesocket(clientSocket);
    closesocket(listenSocket);
    //client get that server is disconnect after all process


    









    WSACleanup();

	return 0;
}