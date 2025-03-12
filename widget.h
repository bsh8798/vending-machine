#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget  //widget.ui
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //member
    int money{0};  //(int money = 0) == (int money{0}))
    void increaseMoney(int value);
    void changeButtonState();
    void pbCoffieButtonState();
    void pbMilkCoffieButtonState();
    void pbTeaButtonState();
    void pbResetButtonState();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffie_clicked();

    void on_pbMilkCoffie_clicked();

    void on_pbTea_clicked();

    void on_pbReset_clicked();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
