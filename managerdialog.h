#ifndef MANAGERDIALOG_H
#define MANAGERDIALOG_H

#include <QDialog>

namespace Ui {
class ManagerDialog;
}

class ManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerDialog(QWidget *parent = 0);
    void refreshoroomtable();
    void refreshoordertable();
    ~ManagerDialog();
private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::ManagerDialog *ui;
};

#endif // MANAGERDIALOG_H
