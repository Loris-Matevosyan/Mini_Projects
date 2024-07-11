#include <QCoreApplication>
#include <QtConcurrent>
#include <QFuture>
#include "commandLine.h"
#include "chat.h"


int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    CommandLine cmd(&a, stdin);

    QFuture<void> future = QtConcurrent::run(&CommandLine::monitor, &cmd);

    Chat chat;
    QObject::connect(&cmd, &CommandLine::command, &chat, &Chat::command);

    qInfo() << "Enter your name: ";

    return a.exec();
}
