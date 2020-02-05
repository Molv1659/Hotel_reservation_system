#ifndef HOTEL_H
#define HOTEL_H
#include<QString>
#include<QHash>
#include"manager.h"
#include"room.h"
class Hotel
{
private:

    QString hotelID;
    QString hotelPassport;
    QString location;
    QString city;
    QString telephone;
    float assessment;
    int assessNum;
    bool workable;
    QString hotelPictureAddress;

public:
    Hotel(QString hotelID,QString hotelPassport,QString location,QString city,QString telephone,float assessment=0,int assessNum=0,bool workable=false,
          QString hotelPictureAddress=NULL): hotelID(hotelID),
        hotelPassport(hotelPassport),location(location),city(city),
        telephone(telephone),assessment(assessment),assessNum(assessNum),workable(workable),hotelPictureAddress(hotelPictureAddress){}
    void sethotelID(QString a);
    void sethotelPassport(QString a);
    void setlocation(QString a);
    void setcity(QString a);
    void settelephone(QString a);
    void setassessment(float a);
    void setassessNum(int a);
    void setworkable(int a);
    void sethotelPictureAddress(QString a);

    QString gethotelID(){return(hotelID);}
    QString gethotelPassport(){return(hotelPassport);}
    QString getlocation(){return(location);}
    QString getcity(){return(city);}
    QString gettelephone(){return(telephone);}
    float getassessment(){return(assessment);}
    int getassessNum(){return(assessNum);}
    bool getworkable(){return(workable);}
    QString gethotelPictureAddress(){return(hotelPictureAddress);}

};

#endif // HOTEL_H
