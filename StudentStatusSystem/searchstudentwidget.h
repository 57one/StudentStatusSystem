#ifndef SEARCHSTUDENTWIDGET_H
#define SEARCHSTUDENTWIDGET_H

#include <QWidget>
#include<QFile>
#include<QVector>
#include<QMessageBox>
#include<QDebug>
#include<QString>
#include"studentinfo.h"
namespace Ui {
class SearchStudentWidget;
}

class SearchStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SearchStudentWidget(QWidget *parent = nullptr);
    ~SearchStudentWidget();
signals:
    void display(int number);
private slots:
    void on_btnQuit_clicked();

    void on_btnSearch_clicked();

private:
    Ui::SearchStudentWidget *ui;
};

#endif // SEARCHSTUDENTWIDGET_H
