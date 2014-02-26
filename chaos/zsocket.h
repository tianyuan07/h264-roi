#ifndef ZSOCKET_H
#define ZSOCKET_H

#include "ztypes.h"
#include "zaddress.h"
#include "zbinary.h"

namespace LibChaos {

class ZSocket {
public:
    typedef void (*receiveCallback)(ZSocket *_socket, const ZAddress &sender, const ZBinary &data);

    enum socket_type {
        tcp = SOCK_STREAM,
        udp = SOCK_DGRAM
        //raw = SOCK_RAW
    };
//    enum socket_family {
//        ipv4 = AF_INET,
//        unix = AF_UNIX,
//        ipv6 = AF_INET6
//    };

    ZSocket(socket_type type);
    ~ZSocket();

    // UDP
    bool open(ZAddress port);
    void close();
    bool isOpen() const;
    bool send(ZAddress destination, const ZBinary &data);
    zu32 receive(ZAddress &sender, ZBinary &str);
    void listen(receiveCallback receivedFunc);

    // TCP
    bool openStream(ZAddress address);

    bool setBlocking(bool);
    bool allowRebind(bool);

private:
    static bool InitializeSockets();
    static void ShutdownSockets();

    static zu64 socket_count;

    int _socket;
    int _type;
    unsigned char *buffer;
};

}

#endif // ZSOCKET_H
