#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QVariant>
#include<QString>
#include<QHash>
#include"customer.h"
#include"hotel.h"
#include"manager.h"
#include"order.h"
#include"room.h"

    bool connection();//链接库
    void disconnection();
    //读到5个全局变量的QHash
    void read_customerInfo();
    void read_orderInfo();
    void read_hotelInfo();
    void read_managerInfo();
    void read_roomInfo();
    void readall();
   //从5个QHash写到数据库
    void write_customerInfo();
    void write_orderInfo();
    void write_hotelInfo();
    void write_managerInfo();
    void write_roomInfo();
    void writeall();



#endif // DATABASE_H
