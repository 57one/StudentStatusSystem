#ifndef MODIFYSTUDENTWIDGET_H
#define MODIFYSTUDENTWIDGET_H

#include <QWidget>
#include<QFile>
#include<QVector>
#include<QMessageBox>
#include<QDebug>
#include"studentinfo.h"
namespace Ui {
class ModifyStudentWidget;
}

class ModifyStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyStudentWidget(QWidget *parent = nullptr);
    ~ModifyStudentWidget();
signals:
    void display(int number);
private slots:
    void on_btnQuit_clicked();

    void on_btnModify_clicked();

    void on_btnDelete_clicked();

    void on_Province_currentIndexChanged(const QString &arg1);

    void on_City_currentIndexChanged(const QString &arg1);

private:
    Ui::ModifyStudentWidget *ui;
};

#endif // MODIFYSTUDENTWIDGET_H
