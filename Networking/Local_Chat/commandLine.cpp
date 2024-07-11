#include "commandLine.h"

CommandLine::CommandLine(QObject *parent, FILE *filehandler)
    : QObject{parent}, input{filehandler}
    {
        //Empty
    }

void CommandLine::monitor()
{
    while(true)
    {
        QString data = input.readLine();
        emit command(data);
    }
}
