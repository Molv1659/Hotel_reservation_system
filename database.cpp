#include "database.h"
#include<QDebug>
#include <QSqlError>
#include<QDate>
extern QHash<QString,Customer*>  customerInfo;//customerID
extern QHash<QString,Order*> orderInfo;//orderID
extern QHash<QString,Hotel*> hotelInfo;//hotelID
extern QHash<QString,Manager*> managerInfo;//managerID
extern QHash<QString,Room*> roomInfo;//房间类型代码吧

bool connection()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");


   if(!db.open()) return false;
   QSqlQuery query;
   //1

   if(!db.tables().contains("customerInfoKu"))
   {
       query.exec("create table customerInfoKu (customerID QString primary key, customerPassport QString ,"
                  " mobilePhone QString)");
       qDebug()<<"已创建客户表"<<endl;
   }
   else
   {
       qDebug()<<"已存在客户表"<<endl;
   }
   //2
   if(!db.tables().contains("orderInfoKu"))
   {
        query.exec("create table orderInfoKu (orderID QString primary key,bcustomerID QString , progress QString,"
                   "broomID QString,liveinDate QDate,dayNum int,grade int)");
        qDebug()<<"已创建订单表"<<endl;
    }
    else
    {
        qDebug()<<"已存在订单表"<<endl;
   }
   //3
   if(!db.tables().contains("hotelInfoKu"))
   {
        query.exec("create table hotelInfoKu (hotelID QString primary key, hotelPassport QString,location QString ,"
                   "city QString,telephone QString,"
                   "assessment float,assessNum int,workable bool,hotelPictureAddress QString)");
        qDebug()<<"已创建酒店表"<<endl;
    }
    else
    {
        qDebug()<<"已存在酒店表"<<endl;
   }
   //4
  if(!db.tables().contains("managerInfoKu"))
   {
        query.exec("create table managerInfoKu (managerID QString primary key, managerPassport QString ,"
                   "bhotelName QString)");
        qDebug()<<"已创建酒店管理员表"<<endl;
    }
    else
    {
        qDebug()<<"已存在酒店管理员表"<<endl;
   }
   //5
  if(!db.tables().contains("roomInfoKu"))
   {
        if(query.exec("create table roomInfoKu (roomID QString primary key, hotelName QString,pictureAddress QString,"
                   "price float,totalNum int ,remainingNum int,roomType QString,discount float,discribe QString,"
                   "sellable bool)"))
        qDebug()<<"已创建房间表"<<endl;
    }
    else
    {
        qDebug()<<"已存在房间表"<<endl;
   }
  return(true);


}
void disconnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
     db.close();;

}
void read_customerInfo()
{
    QSqlQuery query;
    query.exec("select * from customerInfoKu");
    while(query.next())
        {
           Customer*cus=new Customer(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());

           customerInfo[cus->getcustomerID()]=cus;
           qDebug()<<"读入顾客"<<cus->getcustomerID()<<endl;

       }

}
void read_orderInfo()
{
    QSqlQuery query;
    query.exec("select * from orderInfoKu");
    while(query.next())
        {
          Order*ord=new Order(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),
                              query.value(3).toString(),query.value(4).toDate(),query.value(5).toInt(),query.value(6).toInt());
           orderInfo[ord->getorderID()]=ord;

       }
}
void read_hotelInfo()
{
    QSqlQuery query;
    query.exec("select * from hotelInfoKu");
    while(query.next())
        {
           Hotel*ho=new Hotel(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),
                              query.value(3).toString(),query.value(4).toString(), query.value(5).toFloat()
                              ,query.value(6).toInt(),query.value(7).toBool(),query.value(8).toString());
           hotelInfo[ho->gethotelID()]=ho;
           qDebug()<<"读入酒店"<<ho->gethotelID()<<endl;
       }

}
void read_managerInfo()
{
    QSqlQuery query;
   if( !query.exec("select * from managerInfoKu"))qDebug()<<"没打开管理员表的原因"<<query.lastError();
    while(query.next())
        {
        Manager*man=new Manager(query.value(0).toString(),query.value(1).toString(),query.value(2).toString());
        managerInfo[man->getmanagerID()]=man;
        qDebug()<<"读入管理员"<<man->getmanagerID()<<endl;
    }
}
void read_roomInfo()
{
    QSqlQuery query;
    if( !query.exec("select * from roomInfoKu"))qDebug()<<"没打开房间的原因"<<query.lastError();
    while(query.next())
        {
        Room* roo =new Room(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),
                            query.value(3).toFloat()
                           ,query.value(4).toInt(),query.value(5).toInt(),query.value(6).toString(),
                            query.value(7).toFloat()
                           ,query.value(8).toString(),query.value(9).toBool());
        roomInfo[roo->getroomID()]=roo;
         qDebug()<<"读入房间"<<roo->getroomID()<<endl;
       }
}

void write_customerInfo()
{
    QSqlQuery query;
   if(!query.exec("delete from customerInfoKu"))qDebug()<<query.lastError();
   QHash<QString, Customer*>::const_iterator i = customerInfo.constBegin();

        while (i != customerInfo.constEnd())

        {

            QString str="insert into customerInfoKu values(?,?,?)";
            query.prepare(str);

             query.addBindValue( i.value()->getcustomerID());
             query.addBindValue( i.value()->getcustomerPassport());
             query.addBindValue( i.value()->getmobilePhone());
             query.exec();

           ++i;
        }

}
void write_orderInfo()
{
    QSqlQuery query;
   QHash<QString, Order*>::const_iterator i = orderInfo.constBegin();

        while (i != orderInfo.constEnd())

        {

            QString str="insert into orderInfoKu values(?,?,?,?,?,?,?)";
            query.prepare(str);

             query.addBindValue( i.value()->getorderID());
             query.addBindValue( i.value()->getbcustomerID());
             query.addBindValue( i.value()->getprogress());
             query.addBindValue( i.value()->getbroomID());
             query.addBindValue( i.value()->getliveinDate());
             query.addBindValue( i.value()->getdayNum());
             query.addBindValue(i.value()->getgrade());
             query.exec();

           ++i;
        }

}
void write_hotelInfo()
{
    QSqlQuery query; if(!query.exec("delete from hotelInfoKu"))qDebug()<<query.lastError();
   QHash<QString, Hotel*>::const_iterator i = hotelInfo.constBegin();

        while (i != hotelInfo.constEnd())

        {
          qDebug()<<"有酒店"<<i.value()->gethotelID()<<endl;
            QString str="insert into hotelInfoKu values(?,?,?,?,?,?,?,?,?)";
            query.prepare(str);
             query.addBindValue( i.value()->gethotelID());
             query.addBindValue( i.value()->gethotelPassport());
             query.addBindValue( i.value()->getlocation());
             query.addBindValue(i.value()->getcity());
             query.addBindValue( i.value()->gettelephone());
             query.addBindValue( i.value()->getassessment());
             query.addBindValue( i.value()->getassessNum());
             query.addBindValue( i.value()->getworkable());
             query.addBindValue( i.value()->gethotelPictureAddress());
             if(!query.exec())
               {
                   qDebug() << "Error: Fail to insert table." << query.lastError();
               }
            // if(query.exec())  qDebug()<<"写入酒店"<<i.value()->gethotelID()<<endl;

           ++i;
        }

}
void write_managerInfo()
{
    QSqlQuery query;
    if(!query.exec("delete from managerInfoKu")) qDebug()<<query.lastError();
     //if(!query.exec("delete from managerInfoKu"))qDebug()<<"没删掉管理员表"<<query.lastError();
     else qDebug()<<"成功删除酒店管理员表";
   QHash<QString, Manager*>::const_iterator i = managerInfo.constBegin();

        while (i != managerInfo.constEnd())

        {

            QString str="insert into managerInfoKu values(?,?,?)";
            query.prepare(str);

             query.addBindValue( i.value()->getmanagerID());
             query.addBindValue( i.value()->getmanagerPassport());
             query.addBindValue( i.value()->getbHotelname());

             if(query.exec())
            { qDebug()<<i.value()->getbHotelname()<<"写入管理员"<<i.value()->getmanagerID();}
               else qDebug()<<"没写入管理员的原因"<<query.lastError();
           ++i;
        }

}
void write_roomInfo()
{
    QSqlQuery query;
    if(!query.exec("delete from roomInfoKu")) qDebug()<<query.lastError();
     else qDebug()<<"成功删除房间表";
   QHash<QString, Room*>::const_iterator i = roomInfo.constBegin();

        while (i != roomInfo.constEnd())

        {

            QString str="insert into roomInfoKu values(?,?,?,?,?,?,?,?,?,?)";
             query.prepare(str);
             query.addBindValue( i.value()->getroomID());
             query.addBindValue( i.value()->gethotelName());
             query.addBindValue( i.value()->getpictureAddress());
             query.addBindValue( i.value()->getprice());
             query.addBindValue( i.value()->gettotalNum());
             query.addBindValue( i.value()->getremainingNum());
             query.addBindValue( i.value()->getroomType());
             query.addBindValue( i.value()->getdiscount());
             query.addBindValue( i.value()->getdiscribe());
             query.addBindValue( i.value()->getsellable());
             if(query.exec())
             {            
             qDebug()<<"写入房间"<<i.value()->getroomID();
             }
             else
                 qDebug()<<query.lastError();
           ++i;
        }

}


void readall()
{
   read_customerInfo();
   read_orderInfo();
   read_hotelInfo();
   read_managerInfo();
   read_roomInfo();
}


void writeall()
{
    write_customerInfo();
    write_orderInfo();
    write_hotelInfo();
    write_managerInfo();
    write_roomInfo();
}
