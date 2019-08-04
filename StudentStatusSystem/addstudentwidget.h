#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QWidget>
#include<QFile>
#include<QVector>
#include<QMessageBox>
#include<QDebug>
#include<QTextStream>
#include<QList>
#include"province.h"
namespace Ui {
class AddStudentWidget;
}

class AddStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentWidget(QWidget *parent = nullptr);
    ~AddStudentWidget();
signals:
    void display(int number);
private slots:
    void on_btnQuit_clicked();

    void on_btnAdd_clicked();

    void on_Province_currentIndexChanged(const QString &arg1);

    void on_City_currentIndexChanged(const QString &arg1);

private:
    Ui::AddStudentWidget *ui;
};

#endif // ADDSTUDENTWIDGET_H
