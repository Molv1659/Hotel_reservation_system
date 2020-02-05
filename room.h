#ifndef ROOM_H
#define ROOM_H
#include<QString>

class Room
{
private:
    QString roomID;
    QString hotelName;
    QString pictureAddress;
    float price;
    int totalNum;
    int remainingNum;
    QString roomType;//房型暂订QString型
    float discount;
    QString discribe;//酒店对之的描述
    bool sellable;
public:
    Room(QString roomID,QString hotelName,QString pictureAddress,float price,int totalNum,int remainingNum1, QString roomType,
         float discount=float(10),QString discribe=NULL,bool sellable=false):roomID(roomID),hotelName(hotelName),pictureAddress(pictureAddress),
        price(price),totalNum(totalNum),remainingNum(remainingNum1),roomType(roomType),discount(discount),discribe(discribe),sellable(sellable){}
    QString getroomID(){return(roomID);}
    QString gethotelName(){return(hotelName);}
    QString getpictureAddress(){return(pictureAddress);}
    float getprice(){return(price);}
    int gettotalNum(){return(totalNum);}
    int getremainingNum(){return(remainingNum);}
    QString getroomType(){return(roomType);}
    float getdiscount(){return(discount);}
    QString getdiscribe(){return(discribe);}
    bool getsellable(){return(sellable);}

    void setroomID(QString a){roomID=a;}
    void sethotelName(QString a){hotelName=a;}
    void setpictureAddress(QString a){pictureAddress=a;}
    void setprice(float a){price=a;}
    void settotalNum(int a){totalNum=a;}
    void setremainingNum(int a){remainingNum=a;}
    void setroomType(QString a){roomType=a;}
    void setdiscount(float a){discount=a;}
    void setdiscribe(QString a){discribe=a;}
    void setsellable(bool a){sellable=a;}


};

#endif // ROOM_H
