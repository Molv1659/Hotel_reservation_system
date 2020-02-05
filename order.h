#ifndef ORDER_H
#define ORDER_H
#include<QString>
#include"room.h"
#include<QDate>
class Order
{
private:
    QString orderID;
    QString bcustomerID;
    QString progress;//1.待接单2.已接单3.使用中4.使用完毕5.申请退款6.已退款7.拒绝接单
    QString broomID;
    QDate liveinDate;
    int dayNum;
    int grade;

public:
    Order(QString orderID , QString bcustomerID ,QString progress,QString broomID, QDate liveinDate,int dayNum,int grade=0):
        orderID(orderID),bcustomerID(bcustomerID),progress(progress),broomID(broomID), liveinDate(liveinDate),dayNum(dayNum),grade(grade){}
    QString getorderID(){return(orderID);}
    void setorderID(QString a);

    QString getbcustomerID(){return(bcustomerID);}
    void setbcustomerID(QString a);

    QString getprogress(){return(progress);}
    void setprogress(QString a);

    QString getbroomID(){return(broomID);}
    void setbroomID(QString a);

    QDate getliveinDate(){return(liveinDate);}
    void setliveinDate(QDate a);

    int getdayNum(){return(dayNum);}
    void setdayNum(int a);

    int getgrade(){return(grade);}
    void setgrade(int a);
};

#endif // ORDER_H
