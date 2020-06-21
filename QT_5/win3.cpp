#include "win3.h"
#include "ui_win3.h"
#include<math.h>
#include<QDebug>
#include<QMessageBox>
win3::win3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win3)
{
    ui->setupUi(this);
    ui->radioButton_3->setChecked(true);
    ui->widget_11->hide();
    ui->lineEdit->setToolTip("请输入正数");
    ui->lineEdit_2->setToolTip("请输入不大于100正数");
    ui->lineEdit_3->setToolTip("请输入正数");
    ui->lineEdit_4->setToolTip("请输入不大于100的正数");
}

win3::~win3()
{
    delete ui;
}

void win3::on_pushButton_3_clicked()
{
    this->close();
}


double power5(double x, double z, int y)
{
    double m = 1;
    m = pow((1+z),y);
    qDebug()<<m;
    return (x*z*m)/(m-1);

}


double power6(double x, double y, int z)
{
    double m =0;
    for(int i = 0; i<z; i++)
    {
        m = x + m;
        x = x-y;
    }
    return m;
}



void win3::on_pushButton_clicked()
{
    x = ui->lineEdit->text().toDouble();
    x = x*10000;
    y = ui->lineEdit_2->text().toDouble();
    y = y/1200;
    m = ui->lineEdit_3->text().toDouble();
    m = m*10000;
    n = ui->lineEdit_4->text().toDouble();
    n = n/1200;
    switch (ui->comboBox_3->currentIndex()) {
    case 0:
        z = 300;
        break;
    case 1:
        z = 288;
        break;
    case 2:
        z = 276;
        break;
    case 3:
        z = 264;
        break;
    case 4:
        z = 252;
        break;
    case 5:
        z = 240;
        break;
    case 6:
        z = 228;
        break;
    case 7:
        z = 216;
        break;
    case 8:
        z = 204;
        break;
    case 9:
        z = 192;
        break;
    case 10:
        z = 180;
        break;
    case 11:
        z = 168;
        break;
    case 12:
        z = 156;
        break;
    case 13:
        z = 144;
        break;
    case 14:
        z = 132;
        break;
    case 15:
        z = 120;
        break;
    case 16:
        z = 108;
        break;
    case 17:
        z = 96;
        break;
    case 18:
        z = 84;
        break;
    case 19:
        z = 72;
        break;
    case 20:
        z = 60;
        break;
    case 21:
        z = 48;
        break;
    case 22:
        z = 36;
        break;
    case 23:
        z = 24;
        break;
    default:
        z = 12;
        break;
    }

    if(ui->radioButton_3->isChecked())//判断计算方式
    {
        qDebug()<<"已选择等额本金的还款方式";
        ui->widget_35->hide();
        ui->widget_13->move(10,190);
        ui->label_11->move(10,110);
        ui->label_9->setText("每月月供");
        num1 = power5(x, y, z) + power5(m, n, z);
        ui->out_1->setText(QString::number(num1,'f',1));
        ui->out_2->setText(QString::number(x+m,'f',1));
        ui->out_3->setText(QString::number(num1*z-x-m,'f',1));
        ui->out_4->setText(QString::number(num1*z,'f',1));
        ui->out_5->setText(QString::number(z));
    }
    else
    {
        qDebug()<<"已选择按的额本息还款方式";
        ui->widget_13->move(10,60);
        ui->label_11->move(10,9);
        ui->widget_35->show();
        ui->label_9->setText("首月月供");
        num1 = x*y/z+m*n/z;
        num2 = x/z + x*y + m/z + m*n;
        num3 = power6(x*y+m*n, num1, z);
        ui->out_1->setText(QString::number(num2,'f',1));
        ui->out_2->setText(QString::number(x+m,'f',1));
        ui->out_3->setText(QString::number(num3,'f',1));
        ui->out_4->setText(QString::number(num3+x+m,'f',1));
        ui->out_5->setText(QString::number(z));
        ui->out_108->setText(QString::number(num1,'f',1));
    }


    ui->widget_11->show();
    if(ui->out_4->text() == "nan")
    {
        QMessageBox::critical(NULL, "critical", "输入错误，请重试", QMessageBox::Yes | QMessageBox::Ok, QMessageBox::Yes);
        ui->widget_11->hide();
        ui->out_1->clear();
        ui->out_2->clear();
        ui->out_3->clear();
        ui->out_4->clear();
        ui->out_5->clear();
        ui->out_108->clear();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
    }
}

void win3::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton m = QMessageBox::warning(NULL, "warning", "确定清空内容么？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(m == QMessageBox::Yes)
        {
           ui->widget_11->hide();
           ui->out_1->clear();
           ui->out_2->clear();
           ui->out_3->clear();
           ui->out_4->clear();
           ui->out_5->clear();
           ui->out_108->clear();
           ui->lineEdit->clear();
           ui->lineEdit_2->clear();
           ui->lineEdit_3->clear();
           ui->lineEdit_4->clear();
        }

}
