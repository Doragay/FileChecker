#include "UserFile.h"

UserFile::UserFile(const QString &filePath)
{
    QFileInfo newFile(filePath);
    if(newFile.exists()){ //если файл существует, то обозначаем соответсвующие параметры
        exist = true;
        pathFile = newFile.filePath();
        sizeFile = newFile.size();
    }
    else{ //если отсутсвует, то обозначаем файл, как несуществующий
        exist = false;
        pathFile = filePath;
        sizeFile = 0;
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

void UserFile::setExist(const bool flag)
{
    exist = flag;
}

void UserFile::setNewSize(qint64 size)
{
    sizeFile = size;
}

