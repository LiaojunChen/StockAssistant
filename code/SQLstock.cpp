#include "SQLstock.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QDebug>
#include <QVariant>
#include <QSqlError>
#include <QMessageBox>
#include "getstock.h"
SQLstock::SQLstock(QWidget *parent) :
    QWidget(parent)
{

}
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
SQLstock::~SQLstock()
{

}
//初始化数据库
void initializeDatabase() {
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance.db");

    if (!db.open()) {
        qDebug() << "Error: failed to connect to the database." << db.lastError().text();
        return;
    }
    QSqlQuery query;
    query.clear();
    // 创建包含所需字段的表
    if (!query.exec("CREATE TABLE IF NOT EXISTS stocks ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "stockname TEXT, "
                        "stocknumber TEXT, "
                        "initprice REAL, "
                        "currentprice REAL, "
                        "cost REAL, "
                        "positionamount INTEGER, "
                        "profitandloss TEXT, "
                        "profitandlossrate TEXT)")) {
            qDebug() << "Failed to create table:" << query.lastError().text();
            return;
    }
            bool columnExists = false;
                if (query.exec("PRAGMA table_info(stocks)")) {
                    while (query.next()) {
                        if (query.value(1).toString() == "latestprofitandloss") {
                            columnExists = true;
                            break;
                        }
                    }
                }
                // Add column if it doesn't exist
                if (!columnExists) {
                    if (!query.exec("ALTER TABLE stocks ADD COLUMN latestprofitandloss TEXT")) {
                        qDebug() << "Failed to add column:" << query.lastError().text();
                    }
                }
            }
//获取持仓股票名字
void updatestocknamelist()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance.db");
    if (!db.open()) {
        qDebug() << "Error: failed to connect to the database." << db.lastError().text();
        return;
    }
    int count=0;
    QSqlQuery query;
        if (!query.exec("SELECT stockname FROM stocks")) {
            qDebug() << "Query failed:" << query.lastError().text();
            return ;
        }
        while (query.next()) {
            QString stockName = query.value(0).toString();
            if(count>=allstockname.size())
            {
                allstockname.append(stockName);
            }
            if(count<allstockname.size())
                allstockname[count]=stockName;
            count++;
        }
}
//创建新的仓位
void insertStockData(const QString &stockname, const QString &stocknumber, double initprice, double currentprice,int positionamount) {
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance.db");
    if (!db.open()) {
        qDebug() << "Error: failed to connect to the database." << db.lastError().text();
        return;
    }
    QSqlQuery query;
    query.clear();
    if (!query.prepare("INSERT INTO stocks (stockname, stocknumber, initprice, currentprice, cost, positionamount, profitandloss, latestprofitandloss, profitandlossrate) "
                           "VALUES (:stockname, :stocknumber, :initprice, :currentprice, :cost, :positionamount, :profitandloss, :latestprofitandloss, :profitandlossrate)")) {
            qDebug() << "Prepare failed:" << query.lastError().text();
            return;
        }
    double q=initprice*positionamount;
    double cost=q;
    double m = currentprice * positionamount-cost;
        QString profitandloss="+"+QString::number(m, 'f', 2);
    if(m<0)
        {
        double M=abs(m);
        profitandloss="-"+QString::number(M, 'f', 2);
    }
    double n = m / cost*100;
    QString profitandlossrate="+"+QString::number(n, 'f', 2)+"%";
    if(n<0)
    {
        n=abs(n);
        profitandlossrate="-"+QString::number(n, 'f', 2)+"%";
    }
    query.bindValue(":stockname", stockname);
    query.bindValue(":stocknumber", stocknumber);
    query.bindValue(":initprice", initprice);
    query.bindValue(":currentprice", currentprice);
    query.bindValue(":cost", cost);
    query.bindValue(":positionamount", positionamount);
    query.bindValue(":profitandloss", profitandloss);
    query.bindValue(":latestprofitandloss", "+0.00%");
    query.bindValue(":profitandlossrate", profitandlossrate);

    if (!query.exec()) {
        qDebug() << "Insert stock failed:" << query.lastError().text();
    }
    db.close();
}
//创建临时变量保存股票数据
void GetStockData() {//将数据存储到userstock
    initextern();
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance.db");
    if (!db.open()) {
        qDebug() << "Error: failed to connect to the database." << db.lastError().text();
        return;
    }
    QSqlQuery query("SELECT stockname, stocknumber, initprice, currentprice,cost, positionamount, profitandloss,latestprofitandloss, profitandlossrate FROM stocks");
    while (query.next()) {
        userstock.stockname.append(query.value(0).toString());
        userstock.stocknumber.append(query.value(1).toString());
        userstock.initprice.append(query.value(2).toDouble());
        userstock.currentprice.append(query.value(3).toDouble());
        userstock.positionamount.append(query.value(4).toInt());
        userstock.cost.append(query.value(5).toDouble());
        userstock.profitandloss.append(query.value(6).toString());
        userstock.latestprofitandloss.append(query.value(7).toString());
        userstock.profitandlossrate.append(query.value(8).toString());
    }
    if (!query.exec()) {
        qDebug() << "更新失败：" << query.lastError().text();
        return;
    }
    db.close();
}
int state=0;
//更新持仓
void updatepositionamount(const QString &stockname,int newPositionAmount) {
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance.db");
    if (!db.open()) {
            qDebug() << "数据库连接失败";
            return ;
        }
    if(newPositionAmount==0)
    {
        deleteStockByNumber(stockname);
        return;
    }
        QSqlQuery query;
        query.clear();
        query.prepare("SELECT positionamount,cost,currentprice FROM stocks WHERE stockname = :stockname");
          query.bindValue(":stockname", stockname);
          // 执行查询
          int positionamount=0;
          double cost=0;
          double currentprice=0;
          if (query.exec()) {
              if (query.next()) {
                  positionamount = query.value(0).toInt();
                  cost = query.value(1).toDouble();
                  currentprice = query.value(2).toDouble();
              }
          }
          double Cost=0.00;
          int PositionAmount = newPositionAmount+positionamount;
          if(PositionAmount<0)
          {
              QMessageBox::critical(nullptr, "错误", "输入的减仓数不能大于持仓数");
              state=1;
              return;
          }
          if(PositionAmount==0)
          {
              deleteStockByNumber(stockname);
              return;
          }
          if(newPositionAmount<0)
          {
            Cost=cost/positionamount*PositionAmount;
          }
          else
          {
              Cost=cost+newPositionAmount*currentprice;
          }
           // 这里设置新的positionamount值
           query.clear();
        // 构建SQL更新语句
        query.prepare("UPDATE stocks SET positionamount = :positionamount,cost = :cost WHERE stockname = :stockname");
        query.bindValue(":positionamount", PositionAmount);
        query.bindValue(":cost", Cost);
        query.bindValue(":stockname", stockname);
        if (!query.exec()) {
            qDebug() << "更新失败：" << query.lastError().text();
            return;
        }
db.close();
}
//更新股票信息
void updatestockinfo()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finance.db");
    if (!db.open()) {
            qDebug() << "数据库连接失败";
            return ;
        }
    QSqlQuery query;
    query.clear();
    if (!query.exec("SELECT stocknumber, cost,positionamount FROM stocks")) {
         qDebug() << "更新失败：" << query.lastError().text();
         return;
    }
        while (query.next()) {
            QString number = query.value(0).toString();
            double Cost=query.value(1).toDouble();
            int pa=query.value(2).toInt();
            webgetlateststock(number);
            double m=pa*instantstock.currentprice[0]-Cost;
            QString pf="+"+QString::number(m, 'f', 2);
            if(m<0)
            {
                double M=abs(m);
                pf="-"+QString::number(M, 'f', 2);
            }
            double n=m/Cost*100;
            QString pfr="+"+QString::number(n, 'f', 2)+"%";
            if(n<0)
            {
                n=abs(n);
                pfr="-"+QString::number(n, 'f', 2)+"%";
            }
            // 更新数据库中的价格
            QSqlQuery updatequery;
            QString sql = QString("UPDATE stocks SET latestprofitandloss = '%1', profitandloss = '%2', profitandlossrate = '%3', currentprice = '%5' WHERE stocknumber = '%4'")
                                        .arg(instantstock.latestprofitandloss[0])
                                        .arg(pf)
                                        .arg(pfr)
                                        .arg(number)
                                        .arg(instantstock.currentprice[0]);
                    // Execute the update
                    if (!updatequery.exec(sql)) {
                        qDebug() << "Update failed for stock number" << number << ":" << updatequery.lastError().text();
                        return;
                    }
        }
    db.close();}
//删除清仓的股票
void deleteStockByNumber(const QString &stockname) {
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
    if (!db.isOpen()) {
        qDebug() << "Error: failed to connect to the database." << db.lastError().text();
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM stocks WHERE stockname = :stockname");
    query.bindValue(":stockname", stockname);
    if (!query.exec()) {
        qDebug() << "Delete stock failed:" << query.lastError().text();
    }
}

