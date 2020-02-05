
#include"checktrial.h"

bool checktrial(QString a, QHash<QString, Customer *> c)
{
    QHash<QString, Customer*>::const_iterator i = c.constBegin();

        while (i != c.constEnd())

        {

           if(a==i.value()->getcustomerID())return  (true);

            ++i;

        }
        return(false);
}



bool checktrial(QString a, QString b, QHash<QString, Customer *> c)
{
    QHash<QString, Customer*>::const_iterator i = c.constBegin();

        while (i != c.constEnd())

        {

           if(a==i.value()->getcustomerID()&&b==i.value()->getcustomerPassport()) return  (true);

            ++i;

        }
        return(false);
}


bool checktrial(QString a, QHash<QString, Hotel *> c)
{
    QHash<QString, Hotel*>::const_iterator i = c.constBegin();

        while (i != c.constEnd())

        {

           if(a==i.value()->gethotelID())return  (true);

            ++i;

        }
        return(false);
}

bool checktrial(QString a, QString b, QHash<QString, Hotel *> c)
{
    QHash<QString, Hotel*>::const_iterator i = c.constBegin();

        while (i != c.constEnd())

        {

           if(a==i.value()->gethotelID()&&b==i.value()->gethotelPassport()) return  (true);

            ++i;

        }
        return(false);
}

bool checktrial(QString a, QHash<QString, Manager *> c)
{
    QHash<QString, Manager*>::const_iterator i = c.constBegin();

        while (i != c.constEnd())

        {

           if(a==i.value()->getmanagerID())return  (true);

            ++i;

        }
        return(false);
}

bool checktrial(QString a, QString b, QHash<QString, Manager *> c)
{
    QHash<QString, Manager*>::const_iterator i = c.constBegin();

        while (i != c.constEnd())

        {

           if(a==i.value()->getmanagerID()&&b==i.value()->getmanagerPassport()) return  (true);

            ++i;

        }
        return(false);
}
