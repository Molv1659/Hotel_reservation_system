#ifndef ADDROOMDIALOG_H
#define ADDROOMDIALOG_H

#include <QDialog>

namespace Ui {
class AddRoomDialog;
}

class AddRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRoomDialog(QWidget *parent = 0);
    ~AddRoomDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddRoomDialog *ui;
};

#endif // ADDROOMDIALOG_H
