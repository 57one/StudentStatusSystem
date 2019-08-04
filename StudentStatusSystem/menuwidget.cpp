#include "menuwidget.h"
#include "ui_menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::on_BtnAddStu_clicked()
{
    emit display(2);
}

void MenuWidget::on_BtnModifyStu_clicked()
{
    emit display(3);
}

void MenuWidget::on_BtnSearchStu_clicked()
{
    emit display(4);
}

void MenuWidget::on_BtnSortStu_clicked()
{
    emit display(5);
}

void MenuWidget::on_BtnExit_clicked()
{
    emit display(0);
}
