#ifndef SQLSTOCK_H
#define SQLSTOCK_H

#include <QWidget>
#include <core.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
namespace Ui {
class SQLstock;
}extern QSqlDatabase db;

class SQLstock : public QWidget
{
    Q_OBJECT

public:
    explicit SQLstock(QWidget *parent = nullptr);
    ~SQLstock();

};
void deleteStockByNumber(const QString &stocknumber);
void updatepositionamount(const QString &stockname,int newPositionAmount);
void updatestocknamelist();
void initializeDatabase();
void insertStockData(const QString &stockname, const QString &stocknumber, double initprice, double currentprice, int positionamount);
void GetStockData();
void updatestockinfo();
#endif // SQLSTOCK_H
