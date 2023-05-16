#include "Notifier.h"
#include <iostream>

void Notifier::FileState(QString &message)
{
    std::cout << message.toStdString() <<std::endl;
}

