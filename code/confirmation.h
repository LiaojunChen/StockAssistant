#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QWidget>
#include<options.h>
#include<terminal.h>


extern int state;
namespace Ui {
class Confirmation;
}

class Confirmation : public QWidget
{
    Q_OBJECT

public:
    explicit Confirmation(QWidget *parent = nullptr);
    ~Confirmation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Confirmation *ui;
};

#endif // CONFIRMATION_H
