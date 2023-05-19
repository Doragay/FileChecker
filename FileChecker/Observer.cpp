#include "Observer.h"
#include <iostream> //ььььь

Observer::Observer()
{
    //соединяем сигналы со слотами
    connect(this, &Observer::fileChanged, &Notifier::FileChanged);
    connect(this, &Observer::fileNotExist, &Notifier::FileDeleted);
    connect(this, &Observer::fileExist, &Notifier::FileExist);
}

void Observer::addFile(UserFile *newFile)
{
    files.push_back(newFile); //добавляем объект файла в вектор наблюдения
    //Если файл существует, говорим об этом, иначе говорим, что не существует
    if(newFile->isExist())
        emit fileExist(newFile->path(), newFile->size());
    else
        emit fileNotExist(newFile->path());
}

void Observer::observe() //функция наблюдения
{
    //Проходим по каждому файлу в векторе
    for(QVector<UserFile*>::iterator it = files.begin(); it != files.end(); it++){
        auto file = *it; //file - UserFile*
        QFileInfo checkFile(file->path());

        //проверям изменился ли файл или изменилось ли его наличие
        if((file->isExist()) && (!checkFile.exists())){ // если файл существовал, а потом перестал
            file->setExist(false);//обновляем данные
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

void Observer::deleteFile(QString &FileName) //функция удаления файла из наблюдения
{
    for(int i = 0; i < files.size(); i++){
        if(files[i]->path() == FileName){
            files.remove(i);
        }
    }
}
