#ifndef HOTELINFOCHANGEDIALOG_H
#define HOTELINFOCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
class HotelInfoChangeDialog;
}

class HotelInfoChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HotelInfoChangeDialog(QWidget *parent = 0);
    ~HotelInfoChangeDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::HotelInfoChangeDialog *ui;
};

#endif // HOTELINFOCHANGEDIALOG_H
