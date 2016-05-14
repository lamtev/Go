#ifndef GO_COUNTER_H
#define GO_COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
private:
    int count;

public:
    Counter();

public slots:
    void slotIncrement();

signals:
    void goodbye();
    void counterChanged( int );

};


#endif //GO_COUNTER_H
