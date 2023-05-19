#include <QCoreApplication>
#include <iostream>
#include "Observer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Observer* observer = new Observer(); //создаем наблюдателя
    UserFile *newFile = new UserFile("C://Files/test1.txt"); //создаем объект хранящий данный о файле
    observer->addFile(newFile); // добавляем объект в наблюдателя

    newFile = new UserFile("C://Files/test2.txt");
    observer->addFile(newFile);

    newFile = new UserFile("C://Files/test3.docx");
    observer->addFile(newFile);

    std::cout << "Start to observe" << std::endl; //начинаем процесс неаблюдения
    while(true){
        observer->observe();
    }

    return a.exec();
}
