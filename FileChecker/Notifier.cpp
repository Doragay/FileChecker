#include "Notifier.h"
#include <iostream>

void Notifier::FileChanged(const QString path, qint64 size)
{
    std::cout << "file "<< path.toStdString() << " was changed " << size << " bytes" <<std::endl;
}

void Notifier::FileExist(const QString path, qint64 size)
{
    std::cout << "file "<< path.toStdString() << " is exist " << size << " bytes" <<std::endl;
}

void Notifier::FileDeleted(const QString path)
{
    std::cout << "file " << path.toStdString() << " was deleted" << std::endl;
}

