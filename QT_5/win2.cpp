#include "win2.h"
#include "ui_win2.h"
#include<QDebug>
#include<math.h>
#include<QMessageBox>
win2::win2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win2)
{
    ui->setupUi(this);
    ui->radioButton_3->setChecked(true);
    ui->widget_11->hide();
    ui->lineEdit_5->setToolTip("请输入正数");
    ui->lineEdit_6->setToolTip("请输入正数");
    ui->lineEdit_7->setToolTip("请输入正数");
    ui->lineEdit_8->setToolTip("请输入不大于100的正数");
}

win2::~win2()
{
    delete ui;
}

void win2::on_pushButton_3_clicked()
{
    this->close();
}

double power3(double x, int y, double z)
{
    double m = 1;
    m = pow((1+z),y);
    qDebug()<<m;
    return (x*z*m)/(m-1);

}


double power4(double x, double y, int z)
{
    double m =0;
    for(int i = 0; i<z; i++)
    {
        m = x + m;
        x = x-y;
    }
    return m;
}


void win2::on_pushButton_clicked()
{
    //将界面的数据传输回来。
        m=ui->lineEdit_5->text().toDouble();//房单价
        n=ui->lineEdit_6->text().toDouble();//面积和
        x=ui->lineEdit_7->text().toDouble();//贷款数
        x = 10000*x;
        switch (ui->comboBox_3->currentIndex())//按揭成数
        {
        case 0:
            y = 0.8;
            break;
        case 1:
            y=0.75;
            break;
        case 2:
            y=0.7;
            break;
        case 3:
            y=0.65;
            break;
        case 4:
            y=0.6;
            break;
        case 5:
            y=0.55;
            break;
        case 6:
            y=0.5;
            break;
        case 7:
            y=0.45;
            break;
        case 8 :
            y=0.4;
            break;
        case 9 :
            y=0.35;
            break;
        case 10 :
            y=0.3;
            break;
        case 11 :
            y=0.25;
            break;
        default:
            y=0.2;
            break;
        }
    //年数
        switch (ui->comboBox_1->currentIndex()) {
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
        w=ui->lineEdit_8->text().toDouble();//利率
        w=w/1200;
        qDebug()<<"房单价"<<m;
        qDebug()<<"面积和"<<n;
        qDebug()<<"贷款数"<<x;
        qDebug()<<"按揭成数"<<1-y;
        qDebug()<<"每月利率"<<w*1200;
        if(ui->radioButton_3->isChecked())//判断计算方式
        {
            qDebug()<<"已选择等额本金的还款方式";
            ui->widget_23->hide();
            ui->widget_13->move(10,190);
            ui->label_4->move(10,110);
            ui->label_9->setText("每月月供");
            if(ui->btn_2->isChecked())
            {
                qDebug()<<"已选择根据贷款总额计算";
                sum1 = x;
            }
            else
            {
                qDebug()<<"已选择根据单价、面积计算";
                sum1 = m*n*y;
            }
    //数据传输完毕，开始计算及传输到界面。
            qDebug()<<power3(sum1, z, w);
            sum2 = power3(sum1, z, w);
            ui->out_1->setText(QString::number(sum2,'f',1));
            ui->out_2->setText(QString::number(sum1,'f',1));
            ui->out_3->setText(QString::number(sum2*z-sum1,'f',1));
            ui->out_4->setText(QString::number(sum2*z,'f',1));
            ui->out_5->setText(QString::number(z,'f',1));
        }
        else
        {
            qDebug()<<"已选择按的额本息还款方式";
            ui->widget_13->move(10,60);
            ui->label_4->move(10,9);
            ui->widget_23->show();
            ui->label_9->setText("首月月供");
            if(ui->btn_2->isChecked())
            {
                qDebug()<<"已选择根据贷款总额计算";
                sum1 = x;
            }
            else
            {
                qDebug()<<"已选择根据单价、面积计算";
                sum1 = m*n*y;
            }
            sum2 = sum1*w/z;
            sum3 = power4(sum1*w,sum2,z);
            qDebug()<<sum3;
            ui->out_1->setText(QString::number(sum1/z+sum1*w,'f',1));
            ui->out_2->setText(QString::number(sum1,'f',1));
            ui->out_3->setText(QString::number(sum3,'f',1));
            ui->out_4->setText(QString::number(sum1+sum3,'f',1));
            ui->out_5->setText(QString::number(z,'f',1));
            ui->out_6->setText(QString::number(sum2,'f',1));
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
            ui->out_6->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
        }
}

void win2::on_pushButton_2_clicked()
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
           ui->out_6->clear();
           ui->lineEdit_5->clear();
           ui->lineEdit_6->clear();
           ui->lineEdit_7->clear();
           ui->lineEdit_8->clear();
        }

}
