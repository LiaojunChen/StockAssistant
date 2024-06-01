#ifndef MINUS_H
#define MINUS_H

#include <QWidget>
#include<options.h>
#include<confirmation.h>

namespace Ui {
class Minus;
}

class Minus : public QWidget
{
    Q_OBJECT

public:
    explicit Minus(QWidget *parent = nullptr);
    ~Minus();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_minusall_clicked();

private:
    Ui::Minus *ui;
};

#endif // MINUS_H
