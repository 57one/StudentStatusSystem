#include "loggingwidget.h"
#include "ui_loggingwidget.h"

LoggingWidget::LoggingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoggingWidget)
{
    ui->setupUi(this);
    ui->UserName_Text->setPlaceholderText("请输入用户名");
    ui->UserPasd_Text->setPlaceholderText("请输入密码");
}

LoggingWidget::~LoggingWidget()
{
    delete ui;
}

void LoggingWidget::on_btnLogging_clicked()
{
    emit display(1);
}

void LoggingWidget::on_btnExit_clicked()
{
    QApplication::exit();
}
