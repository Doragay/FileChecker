#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVector>
#include "Notifier.h"

class Observer : public QObject  //наследуется от qo
{
    Q_OBJECT //для сигналов и слотов
    QVector<UserFile*> files;
public:
    Observer();
    void addFile(UserFile *newFile);
    void observe();
    void deleteFile(QString &FileName);
signals:
    void fileExist(const QString path, qint64 size);
    void fileNotExist(const QString path);
    void fileChanged(const QString path, qint64 size);
};


#endif // OBSERVER_H
