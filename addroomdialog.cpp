#include "addroomdialog.h"
#include "ui_addroomdialog.h"
#include"room.h"
#include"manager.h"
#include<QMessageBox>
extern QHash<QString,Room*> roomInfo;
extern QHash<QString,Manager*> managerInfo;
extern QString loginer;
AddRoomDialog::AddRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRoomDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Room");
}

AddRoomDialog::~AddRoomDialog()
{
    delete ui;
}

void AddRoomDialog::on_pushButton_2_clicked()
{
    this->close();
}

void AddRoomDialog::on_pushButton_clicked()
{
    Room* addroom=new Room(ui->lineEdit_5->text(),
                            managerInfo[loginer]->getbHotelname(),
                            ui->lineEdit->text(),
                            ui->lineEdit_2->text().toFloat(),
                            ui->lineEdit_3->text().toInt(),
                            ui->lineEdit_3->text().toInt(),
                            ui->lineEdit_6->text(),
                            float(10),
                            ui->lineEdit_4->text(),
                           false);

    roomInfo[ui->lineEdit_5->text()]=addroom;
    QMessageBox::information(NULL, "消息", "增加成功", QMessageBox::Yes);
    this->close();
}
