//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2015 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Braden Cleur, David Haverland
// Mail			: braden.cle8463@mediadesign.school.nz, david.hav8466@mediadesign.school.nz
//

#ifndef __SOCKET_H__
#define __SOCKET_H__

// Library Includes
#include <windows.h>
#include <string>


class CSocket
{
public:
	// Default Constructors/Destructors
	CSocket();
	~CSocket();

	//This function call does the act of creating a socket and binding it to the supplied port number on the local machine.
	bool Initialise(unsigned short _usPortNumber);

	//Accessor methods
	SOCKET GetSocketHandle();

	//Additional Methods to enable broadcasting
	void SetRemotePort(unsigned short _usRemotePort);
	void SetRemoteAddress(unsigned long _ulRemoteAddress);

	//Question 7 : Broadcast to detect a server
	int EnableBroadcast();
	int DisableBroadcast();

private:
	//Get the local IP Address to which the socket is bound to
	std::string GetLocalAddress(); //Used for printing the local addrerss in the console window.
private:
	//A handle to as of yet unbound socket
	SOCKET m_hSocket;
	//A sockaddr structure containing the local address and port to bind the socket to.
	sockaddr_in m_SocketAddress;
	
	//Additional member variables : Details of the remote machine which is sending/receving data via this socket object.
	unsigned long m_ulRemoteIPAddress;
	unsigned short m_usRemotePort;
};

#endif