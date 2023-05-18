#include "Observer.h"
#include <iostream>

Observer::Observer()
{
    connect(this, &Observer::fileChanged, &Notifier::FileChanged);
    connect(this, &Observer::fileNotExist, &Notifier::FileDeleted);
    connect(this, &Observer::fileExist, &Notifier::FileExist);
}

void Observer::addFile(UserFile *newFile)
{
    files.push_back(newFile);
    if(newFile->isExist())
        emit fileExist(newFile->path(), newFile->size());
    else
        emit fileNotExist(newFile->path());
}

void Observer::observe()
{
    for(QVector<UserFile*>::iterator it = files.begin(); it != files.end(); it++){
        auto file = *it;
        QFileInfo checkFile(file->path());
        if((file->isExist()) && (!checkFile.exists())){
            file->setExist(false);
            file->setNewSize(0);

            emit fileNotExist(file->path());
        }
        else if((!file->isExist()) && (checkFile.exists())){
            file->setExist(true);
            file->setNewSize(checkFile.size());

            emit fileExist(file->path(), file->size());
        }
        else if(checkFile.size() != file->size()){
            file->setNewSize(checkFile.size());
            emit fileChanged(file->path(), file->size());
        }
    }
}

void Observer::deleteFile(QString &FileName)
{
    for(int i = 0; i < files.size(); i++){
        if(files[i]->path() == FileName){
            files.remove(i);
        }
    }
}
