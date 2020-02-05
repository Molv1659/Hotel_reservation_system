#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include <QSqlError>
#include"customer.h"
#include"hotel.h"
#include"manager.h"
#include"order.h"
#include"room.h"
#include"database.h"
#include<QString>
QHash<QString,Customer*>  customerInfo;//customerID
QHash<QString,Order*> orderInfo;//orderID
QHash<QString,Hotel*> hotelInfo;//hotelID
QHash<QString,Manager*> managerInfo;//managerID
QHash<QString,Room*> roomInfo;//room需要酒店＋房型才能确定，放弃快速找到的方法，要用时遍历找
// 这5个是与数据库的桥，引用 考虑这个优化
QString loginer;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   connection();
   QSqlQuery query;

   readall();
   disconnection();

    MainWindow w;
    w.show();


    return a.exec();



}
