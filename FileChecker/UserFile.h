#ifndef USERFILE_H
#define USERFILE_H
#include <QFileInfo>

//хранит информацию о файле
class UserFile
{
    bool exist;
    QString pathFile;
    qint64 sizeFile;

public:
    UserFile() = default;
    UserFile(const QString &filePath);

    //getters
    bool isExist();
    QString path();
    qint64 size();

    //setters
    void setExist(const bool flag);
    void setNewSize(qint64 size);
};

#endif // USERFILE_H
