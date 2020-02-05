#ifndef DETAILEDINFODIALOG_H
#define DETAILEDINFODIALOG_H

#include <QDialog>

namespace Ui {
class DetailedInfoDialog;
}

class DetailedInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedInfoDialog(QWidget *parent = 0);
    ~DetailedInfoDialog();
signals:
    void backrefresh();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DetailedInfoDialog *ui;
};

#endif // DETAILEDINFODIALOG_H
