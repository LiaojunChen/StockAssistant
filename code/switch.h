#ifndef SWITCH_H
#define SWITCH_H

#include <QWidget>


namespace Ui {
class Switch;
}

class Switch : public QWidget
{
    Q_OBJECT

public:
    explicit Switch(QWidget *parent = nullptr);
    ~Switch();

private slots:

private:
    Ui::Switch *ui;
};

#endif // SWITCH_H
