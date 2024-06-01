#ifndef PLUS_H
#define PLUS_H

#include <QWidget>
#include<options.h>
#include<confirmation.h>

namespace Ui {
class Plus;
}

class Plus : public QWidget
{
    Q_OBJECT

public:
    explicit Plus(QWidget *parent = nullptr);
    ~Plus();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Plus *ui;
};

#endif // PLUS_H
