// Guard against multiple inclusions of this header file to avoid redefinition errors.
#ifndef TCPSERVICES_H
#define TCPSERVICES_H
#include <QDebug>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Standard UNIX includes for system calls.
#include <unistd.h>

// Include the header file for the parent class "COMService".
#include "comservices.h"

// System includes for socket programming.
#include <sys/socket.h>

// Include for using std::thread for threading.
#include <thread>

/**
 * @brief The TCPService class is a COMService that communicates with the vehicle via TCP.
 */
class TCPServices : public COMServices // Declares a new class named "TCPService" that inherits from "COMService".
{
private:
    int socket_fd;                // File descriptor for the TCP socket.
    std::atomic<bool> end{false}; // Atomic flag to indicate when the service should stop.

    // Defines a thread that runs the "run" function upon creation of a TCPService object.
    std::thread thrd{&TCPServices::run, this};

    // Declaration of the overriden "run" function which is expected to provide the main functionality.
    void run(void) override;

public:
    // Default constructor declaration.
    TCPServices() = default;

    // Destructor declaration.
    // It ensures that when a TCPService object is destroyed,
    // the socket is shutdown and closed, and the associated thread is joined.
    ~TCPServices()
    {
        end = true;                     // Set the "end" flag to true to indicate the service should stop.
        shutdown(socket_fd, SHUT_RDWR); // Shutdown both reading and writing on the socket.
        close(socket_fd);               // Close the socket.
        thrd.join();                    // Wait for the associated thread to finish.
    }
};

#endif