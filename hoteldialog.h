#ifndef HOTELDIALOG_H
#define HOTELDIALOG_H

#include <QDialog>

namespace Ui {
class HotelDialog;
}

class HotelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HotelDialog(QWidget *parent = 0);
    void refreshmanagertable();
    ~HotelDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::HotelDialog *ui;
};

#endif // HOTELDIALOG_H
