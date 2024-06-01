#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <core.h>


extern QString externtext;
namespace Ui {
class Search;
}
extern int searchstate;
class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
