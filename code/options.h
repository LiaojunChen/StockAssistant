#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include<lists.h>
#include<plus.h>
#include<minus.h>
#include <QApplication>
#include <QWidget>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QSqlDatabase>
namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    void switchstock();
    void setupComboBox(QComboBox *comboBox);
    explicit Options(QWidget *parent = nullptr);
    ~Options();

private slots:
    void on_pushButton_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
