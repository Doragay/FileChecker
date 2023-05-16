#ifndef USERFILE_H
#define USERFILE_H
#include <QFileInfo>
#include <QDateTime>

//хранит информацию о файле
class UserFile
{
    bool exist;
    QString pathFile;
    qint64 sizeFile;
    QDateTime lastModified;
public:
    UserFile() = default;
    UserFile(const QString &filePath);
    bool isExist();
    QString path();
    qint64 size();
    QDateTime getLastTime();
    void setExist(const bool flag);
    void setLastTime(QDateTime time);
    void setNewSize(qint64 size);
};

#endif // USERFILE_H
