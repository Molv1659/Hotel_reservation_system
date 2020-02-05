#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>

class Customer
{
private:
    QString customerID;
    QString customerPassport;
    QString mobilePhone;

public:
    Customer(QString customerID,QString customerPassport,QString mobilePhone):customerID(customerID),customerPassport(customerPassport), mobilePhone( mobilePhone){}
   void setcustomerID(QString a);
   QString getcustomerID(){return(customerID);}
   void setcustomerPassport(QString a);
   QString getcustomerPassport(){return(customerPassport);}
   void setmobilePhone(QString a);
   QString getmobilePhone(){return(mobilePhone);}

};

#endif // CUSTOMER_H
