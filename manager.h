#ifndef MANAGER_H
#define MANAGER_H
#include<QString>

class Manager
{
private:
    QString managerID;
    QString managerPassport;
    QString bHotelname;


public:
    Manager(QString a,QString b,QString c):managerID(a),managerPassport(b),bHotelname(c){}
    QString getmanagerID(){return(managerID);}
    QString getmanagerPassport(){return(managerPassport);}
    QString getbHotelname(){return(bHotelname);}
};

#endif // MANAGER_H
