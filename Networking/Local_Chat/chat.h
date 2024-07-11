#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QUdpSocket>
#include <QNetworkDatagram>


class Chat : public QObject
{
    Q_OBJECT

public:
    explicit Chat(QObject *parent = nullptr);

public slots:
    void command(QString inputName);
    void send(QString message);
    void readyRead();

private:
    QString name;
    QUdpSocket socket;
    quint16 port = 3020;

};

#endif // CHAT_H
