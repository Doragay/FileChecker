#include "UserFile.h"

UserFile::UserFile(const QString &filePath)
{
    QFileInfo newFile(filePath);
    if(newFile.exists()){
        exist = true;
        pathFile = newFile.filePath();
        sizeFile = newFile.size();
        lastModified = newFile.lastModified();
    }
    else{
        exist = false;
        pathFile = filePath;
        sizeFile = 0;
        lastModified = QDateTime();
    }
}

bool UserFile::isExist()
{
    return exist;
}

QString UserFile::path()
{
    return pathFile;
}

qint64 UserFile::size()
{
    return sizeFile;
}

QDateTime UserFile::getLastTime()
{
    return lastModified;
}

void UserFile::setExist(const bool flag)
{
    exist = flag;
}

void UserFile::setLastTime(QDateTime time)
{
    lastModified = time;
}

void UserFile::setNewSize(qint64 size)
{
    sizeFile = size;
}

