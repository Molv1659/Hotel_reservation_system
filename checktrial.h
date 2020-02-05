#ifndef CHECKTRIAL_H
#define CHECKTRIAL_H
#include"customer.h"
#include"hotel.h"
#include"manager.h"
extern QHash<QString,Customer*>  customerInfo;//customerID
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Manager*> managerInfo;//managerID
bool checktrial(QString a,QHash<QString,Customer*> c);
bool checktrial(QString a,QHash<QString,Hotel*> c);
bool checktrial(QString a,QHash<QString,Manager*> c);

bool checktrial(QString a,QString b,QHash<QString,Customer*> c);
bool checktrial(QString a,QString b,QHash<QString,Hotel*> c);
bool checktrial(QString a,QString b,QHash<QString,Manager*> c);


#endif // CHECKTRIAL_H
