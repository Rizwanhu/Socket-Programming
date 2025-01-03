#include <iostream>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <tchar.h>
#include <WS2tcpip.h> // For InetPton
//#include <arpa/inet.h>  // For inet_pton and htons

using namespace std;


//#include <WS2tcpip.h>



bool Initialize() {

    // made a wsadata to store the data for socket
    WSADATA wsaData;

    // Initialize Winsock
    // return if socket is connected or not
    return (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0);

}





int main() {

    if (!Initialize()) {
        cout << "initialized winsocekt falied..." << endl;

        return 1;
    }

    SOCKET s;

    cout << "client program started...." << endl;



    s = socket(AF_INET, SOCK_STREAM, 0);
    int port = 1234;
    if (s==INVALID_SOCKET)
    {
        cout << "invalid socket created..." << endl;
        return 1;
    }
    //int port = 12345;
    string serveraddress = "127.0.0.1";
    //serveraddress.sin_port = htons(port);

    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, serveraddress.c_str(), &(serveraddr.sin_addr));

    if (connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) {
        cout << "Not able to connect to the server..." << endl;
        closesocket(s);
        WSACleanup();
        return 1;
    }


    cout << "succesfully connect to server..." << endl;

    string message = "hello i am rizwan!";
    int bytesent;
    bytesent = send(s, message.c_str(), message.length(), 0);
    

    if (bytesent==SOCKET_ERROR)
    {
        cout << "send failed...." << endl;
    }
    closesocket(s);

    cout << "end here." << endl;



    WSACleanup();


	return 0;
}