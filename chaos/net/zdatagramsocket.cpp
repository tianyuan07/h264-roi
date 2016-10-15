/*******************************************************************************
**                                  LibChaos                                  **
**                             zdatagramsocket.cpp                            **
**                          See COPYRIGHT and LICENSE                         **
*******************************************************************************/
#include "zdatagramsocket.h"

namespace LibChaos {

ZDatagramSocket::ZDatagramSocket() : ZSocket(ZSocket::DATAGRAM){
    allowRebind(true);
}

bool ZDatagramSocket::open(){
    return ZSocket::open(ZAddress::IPV6, ZSocket::DATAGRAM, 0);
}
void ZDatagramSocket::close(){
    ZSocket::close();
}
bool ZDatagramSocket::isOpen() const {
    return ZSocket::isOpen();
}

bool ZDatagramSocket::bind(ZAddress port){
    return ZSocket::bind(port);
}

bool ZDatagramSocket::send(ZAddress destination, const ZBinary &data){
    return ZSocket::send(destination, data);
}

zu32 ZDatagramSocket::receive(ZAddress &sender, ZBinary &str){
    return ZSocket::receive(sender, str);
}

void ZDatagramSocket::receiveFunc(receiveCallback receivedFunc){
    while(true){
        ZAddress sender;
        ZBinary data;
        if(!receive(sender, data))
            continue;
        receivedFunc(this, sender, data);
    }
}

}
