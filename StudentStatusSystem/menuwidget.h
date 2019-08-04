#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();
signals:
    void display(int number);
private slots:
    void on_BtnAddStu_clicked();

    void on_BtnModifyStu_clicked();

    void on_BtnSearchStu_clicked();

    void on_BtnSortStu_clicked();

    void on_BtnExit_clicked();

private:
    Ui::MenuWidget *ui;
};

#endif // MENUWIDGET_H
