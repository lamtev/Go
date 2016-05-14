#include "Counter.h"

Counter::Counter() : QObject{}, count{ 0 } {}

void Counter::slotIncrement()
{
    emit counterChanged(++count);

    if( count / 26  )
    {
        emit goodbye();
    }
}