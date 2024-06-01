#ifndef PURCHASE_H
#define PURCHASE_H

#include <QWidget>
#include <lists.h>
#include <confirmation.h>

namespace Ui {
class Purchase;
}

class Purchase : public QWidget
{
    Q_OBJECT

public:
    explicit Purchase(QWidget *parent = nullptr);
    ~Purchase();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Purchase *ui;
};

#endif // PURCHASE_H
