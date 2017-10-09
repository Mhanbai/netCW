/* The Connection class */

#ifndef CONNECTION_H
#define CONNECTION_H

#include <WinSock2.h>
#include <time.h>


// The (fixed) size of message that we send between the two programs
#define MESSAGESIZE 40


// Each instance of this class represents a connected client.
class Connection {
public:
	// Constructor.
	// sock: the socket that we've accepted the client connection on.
	Connection(SOCKET sock);

	// Destructor.
	~Connection();

	// Return the client's socket.
	SOCKET sock();

	// Return whether this connection is in a state where we want to try
	// reading from the socket.
	bool wantRead();

	// Return whether this connection is in a state where we want to try
	// writing from the socket.
	bool wantWrite();

	// Call this when the socket is ready to read or write.
	bool doReadWrite();

	time_t getLastActivity();
private:
	// This client's socket.
	SOCKET sock_;

	// The data we've read from the client.
	int readCount_;
	char readBuffer_[MESSAGESIZE];
	bool isReading = true;
	time_t lastActivityTime;
};

#endif