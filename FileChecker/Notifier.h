#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <QString>
#include <QObject>
#include <UserFile.h>

class Notifier : public QObject
{
    Q_OBJECT
public:
    Notifier() = default;
public slots:
    static void FileState(QString &message);
};

#endif // NOTIFIER_H
