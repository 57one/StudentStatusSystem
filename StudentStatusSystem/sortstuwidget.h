#ifndef SORTSTUWIDGET_H
#define SORTSTUWIDGET_H

#include <QWidget>
#include<QFile>
#include<QVector>
#include<QMessageBox>
#include<QDebug>
#include<QButtonGroup>
#include<QtAlgorithms>
#include<QString>
#include<QTableWidgetItem>
#include"studentinfo.h"
namespace Ui {
class SortStuWidget;
}

class SortStuWidget : public QWidget
{
    Q_OBJECT
private:
    QButtonGroup *buttonGroup;
    QStringList stringList;
public:
    explicit SortStuWidget(QWidget *parent = nullptr);
    ~SortStuWidget();
signals:
    void display(int number);
private slots:
    void on_pushButton_2_clicked();

    void on_btnSort_clicked();

private:
    Ui::SortStuWidget *ui;
};

#endif // SORTSTUWIDGET_H
