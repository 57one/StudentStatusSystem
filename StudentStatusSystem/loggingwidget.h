#ifndef LOGGINGWIDGET_H
#define LOGGINGWIDGET_H

#include <QWidget>
#include<QLineEdit>
namespace Ui {
class LoggingWidget;
}

class LoggingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoggingWidget(QWidget *parent = nullptr);
    ~LoggingWidget();
signals:
    void display(int number);
private slots:
    void on_btnLogging_clicked();
    void on_btnExit_clicked();

private:
    Ui::LoggingWidget *ui;
};

#endif // LOGGINGWIDGET_H
