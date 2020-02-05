#ifndef HOTELREGESTRATIONDLG_H
#define HOTELREGESTRATIONDLG_H

#include <QDialog>

namespace Ui {
class HotelRegestrationDlg;
}

class HotelRegestrationDlg : public QDialog
{
    Q_OBJECT

public:
    explicit HotelRegestrationDlg(QWidget *parent = 0);
    ~HotelRegestrationDlg();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::HotelRegestrationDlg *ui;
};

#endif // HOTELREGESTRATIONDLG_H
