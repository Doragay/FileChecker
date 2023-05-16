#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVector>
#include "Notifier.h"

class Observer : public QObject  //наследуется от qo
{
    Q_OBJECT
    QVector<UserFile*> files;
public:
    Observer();
    void addFile(UserFile *newFile);
    void observe();
    void deleteFile(QString &FileName);
    bool changedFile(QFileInfo& file, UserFile& oldFile);
signals:
    void notify(QString &message);
};


#endif // OBSERVER_H
