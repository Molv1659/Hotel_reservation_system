#include "hotel.h"



void Hotel::sethotelID(QString a)
{
    hotelID=a;
}

void Hotel::sethotelPassport(QString a)
{
    hotelPassport=a;
}

void Hotel::setlocation(QString a)
{
    location=a;
}

void Hotel::setcity(QString a)
{
    city=a;
}

void Hotel::settelephone(QString a)
{
    telephone=a;
}



void Hotel::setassessment(float a)
{
    assessment=a;
}

void Hotel::setassessNum(int a)
{
    assessNum=a;
}

void Hotel::setworkable(int a)
{
    if(a==0) workable=false;
    else workable=true;
}

void Hotel::sethotelPictureAddress(QString a)
{
    hotelPictureAddress=a;
}




