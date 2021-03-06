#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__

#include "common.h"
#include "basic_stream.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/StreamSocket.h"

struct Message
{
public:
    const static uint8 kHeaderLength = 8;

    Message(){}
    virtual ~Message(){}

    virtual int32 byteSize() = 0;
    virtual void encode(byte* buffer, size_t size) = 0;
    virtual void decode(const byte* buffer, size_t size) = 0;
};

class TcpConnection : public Poco::Net::TCPServerConnection
{
    static const int MAX_RECV_LEN = 1024 * 4;

public:
    TcpConnection(const Poco::Net::StreamSocket& socket);
    virtual ~TcpConnection();
    void run();

public:
    void sendMessage(const BasicStreamPtr& packet);
	void sendMessage(int16 opcode, const byte* buff, size_t size);
	void sendMessage(uint16 opcode, Message& message);

private:
    byte* _buffer;
    Poco::Net::StreamSocket& _socket;
};

#endif // !__TCP_CONNECTION_H__
