#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <QObject>
#include <UserFile.h>

class Notifier : public QObject
{
    Q_OBJECT
public:
    Notifier() = default;
public slots:
    static void FileChanged(const QString path, qint64 size);
    static void FileDeleted(const QString path);
    static void FileExist(const QString path, qint64 size);
};

#endif // NOTIFIER_H
