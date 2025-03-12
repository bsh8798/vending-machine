#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeButtonState();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::increaseMoney(int value) {
    money += value;
    ui->lcdNumber->display(money);
    changeButtonState();
}

void Widget::changeButtonState() {
    pbCoffieButtonState();
    pbMilkCoffieButtonState();
    pbTeaButtonState();
    pbResetButtonState();
}
void Widget::pbCoffieButtonState() {
    if(money < 100) {
        ui->pbCoffie->setEnabled(false);
    }
    else {
        ui->pbCoffie->setEnabled(true);
    }
}
void Widget::pbMilkCoffieButtonState() {
    if(money < 150) {
        ui->pbMilkCoffie->setEnabled(false);
    }
    else {
        ui->pbMilkCoffie->setEnabled(true);
    }
}
void Widget::pbTeaButtonState() {
    if(money < 200) {
        ui->pbTea->setEnabled(false);
    }
    else {
        ui->pbTea->setEnabled(true);
    }
}
void Widget::pbResetButtonState() {
    if(money <= 0) {
        ui->pbReset->setEnabled(false);
    }
    else {
        ui->pbReset->setEnabled(true);
    }
}


void Widget::on_pb10_clicked()
{
    increaseMoney(10);
}
void Widget::on_pb50_clicked()
{
    increaseMoney(50);
}
void Widget::on_pb100_clicked()
{
    increaseMoney(100);
}
void Widget::on_pb500_clicked()
{
    increaseMoney(500);
}


void Widget::on_pbCoffie_clicked()
{
    increaseMoney(-100);
}
void Widget::on_pbMilkCoffie_clicked()
{
    increaseMoney(-150);
}
void Widget::on_pbTea_clicked()
{
    increaseMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int cash[4] = {0, 0, 0, 0};
    cash[3] = money / 500;
    money %= 500;
    cash[2] = money / 100;
    money %= 100;
    cash[1] = money / 50;
    money %= 50;
    cash[0] = money / 10;

    QString message = QString("10won - %1 / 50won - %2 / 100won -%3 / 500won - %4")
                          .arg(cash[0])
                          .arg(cash[1])
                          .arg(cash[2])
                          .arg(cash[3]);
    QMessageBox mb;
    mb.information(this, "Return money", message);
    increaseMoney(-money);
}

