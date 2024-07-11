#include "Chat.h"

Chat::Chat(QObject *parent) : QObject{parent}
{
    if(!socket.bind(port, QAbstractSocket::ReuseAddressHint))
    {
        qInfo() << socket.errorString();
    }
    else
    {
        qInfo() << "Connected to " << socket.localAddress() << " on port: " << socket.localPort();
        connect(&socket, &QUdpSocket::readyRead, this, &Chat::readyRead);
    }
}

void Chat::command(QString inputName)
{
    QString message = name + ": ";

    if( name.isEmpty() )
    {
        name = inputName;
        message = name + ": joined";
        send(message);
        return;
    }

    message.append(inputName);
    send(message);
}


void Chat::send(QString message)
{
    QByteArray data = message.toLatin1();
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);

    if(!socket.writeDatagram(datagram))
    {
        qInfo() << socket.errorString();
    }
}


void Chat::readyRead()
{
    while( socket.hasPendingDatagrams() )
    {
        QNetworkDatagram datagram = socket.receiveDatagram();
        qInfo() << datagram.data();
    }
}




