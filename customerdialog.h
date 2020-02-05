#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>
#include<QMessageBox>
#include<QDebug>
#include"room.h"
#include"order.h"
#include"manager.h"
#include"hotel.h"
#include"addroomdialog.h"
#include"customer.h"
#include"managerusedorderdialog.h"
extern QHash<QString,Customer*>  customerInfo;
extern QHash<QString,Room*> roomInfo;
extern QHash<QString,Order*> orderInfo;
extern QHash<QString,Manager*> managerInfo;
extern QHash<QString,Hotel*>hotelInfo;
extern QString loginer;
namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = 0);

    void refreshmyordertable();
    int uproomNum();
    int downroomNum();
    void refreshroomtableall();
    void refreshroomtable2();
    void refreshroomtable1();
    void refreshtable(QHash<QString,Room*> roomInfo1,int a,int b);
    ~CustomerDialog();

private slots:
    void neworder();
    void newhotegrade();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::CustomerDialog *ui;
};

#endif // CUSTOMERDIALOG_H
