#ifndef WIN1_H
#define WIN1_H

#include <QDialog>

namespace Ui {
class win1;
}

class win1 : public QDialog
{
    Q_OBJECT

public:
    explicit win1(QWidget *parent = nullptr);
    ~win1();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::win1 *ui;
    double m, n, x, y, z, w, sum1, sum2, sum3, sum4;
};

#endif // WIN1_H
