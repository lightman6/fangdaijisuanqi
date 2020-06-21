#ifndef WIN2_H
#define WIN2_H

#include <QDialog>

namespace Ui {
class win2;
}

class win2 : public QDialog
{
    Q_OBJECT

public:
    explicit win2(QWidget *parent = nullptr);
    ~win2();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::win2 *ui;
    double m, n, x, y, z, w, sum1, sum2, sum3, sum4;
};

#endif // WIN2_H
