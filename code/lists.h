#ifndef LISTS_H
#define LISTS_H

#include <QWidget>
#include<core.h>
#include<options.h>
#include<purchase.h>
#include "getstock.h"
namespace Ui {
class Lists;
}

class Lists : public QWidget
{
    Q_OBJECT

public:
    explicit Lists(QWidget *parent = nullptr);
    ~Lists();
    void showstock();
    void showstockpic();
private slots:
    void onComboBoxChanged(int index);
    void on_switch_2_clicked();
private:
    Ui::Lists *ui;
};

#endif // LISTS_H
