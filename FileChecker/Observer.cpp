#include "Observer.h"
#include <iostream>

Observer::Observer()
{
    connect(this, &Observer::notify, &Notifier::FileState);
}

void Observer::addFile(UserFile *newFile)
{
    files.push_back(newFile);
    QString message;
    if(newFile->isExist())
        message = "File " + newFile->path() + " is exist with size " + newFile->size() +" bytes "
                + newFile->getLastTime().toString("hh:mm:ss dd.MM.yyyy") + " last modified time\n";
    emit notify(message);
}

void Observer::observe()
{
    QString message;
    for(auto& file : files){
        QFileInfo checkFile(file->path());
        if((file->isExist()) && (!checkFile.exists())){
            file->setExist(false);
            file->setLastTime(QDateTime());
            file->setNewSize(0);

            message = "File " + file->path() + " isn't exist\n";
            emit notify(message);
        }
        else if((!file->isExist()) && (checkFile.exists())){
            file->setExist(true);
            file->setLastTime(checkFile.lastModified());
            file->setNewSize(checkFile.size());

            message = "File " + file->path() + " is exist with size " + file->size() +" bytes "
                    + file->getLastTime().toString("hh:mm:ss dd.MM.yyyy") + " last modified time\n";
            emit notify(message);
        }
        else if(checkFile.lastModified() != file->getLastTime()){
            file->setLastTime(checkFile.lastModified());
            message = "File " + file->path() + " is exist with size " + file->size() +" bytes and was changed "
                    + file->getLastTime().toString("hh:mm:ss dd.MM.yyyy") + " last modified time\n";
            emit notify(message);
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
