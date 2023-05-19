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
    static void FileChanged(const QString path, qint64 size); //слот оповещающий об изменении в файле
    static void FileDeleted(const QString path); //слот оповещающий об удалении  файла
    static void FileExist(const QString path, qint64 size); //слот оповещающий о существовании файле
};

#endif // NOTIFIER_H
