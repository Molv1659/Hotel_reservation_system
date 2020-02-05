#ifndef MANAGERREGESTRATIONDLG_H
#define MANAGERREGESTRATIONDLG_H

#include <QDialog>

namespace Ui {
class ManagerRegestrationDlg;
}

class ManagerRegestrationDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerRegestrationDlg(QWidget *parent = 0);
    ~ManagerRegestrationDlg();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ManagerRegestrationDlg *ui;
};

#endif // MANAGERREGESTRATIONDLG_H
