#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTextStream>


class CommandLine : public QObject
{
    Q_OBJECT

public:
    explicit CommandLine(QObject *parent = nullptr, FILE *filehandler = nullptr);
    void monitor();

signals:
    void command(QString name);

private:
    QTextStream input;

};

#endif // COMMANDLINE_H
