#include <QCoreApplication>
#include <iostream>
#include "Observer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Observer* observer = new Observer();
    UserFile *newFile = new UserFile("C://test1.txt");
    observer->addFile(newFile);

    newFile = new UserFile("C://test2.txt");
    observer->addFile(newFile);

    newFile = new UserFile("C://test3.docx");
    observer->addFile(newFile);

    std::cout << "Start to observe" << std::endl;
    while(true){
        observer->observe();
    }

    return a.exec();
}
