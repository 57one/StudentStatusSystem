#ifndef MAINCONTROL_H
#define MAINCONTROL_H
#include <QWidget>
#include<QStackedLayout>
#include<QMessageBox>       //用于消息提示
#include"loggingwidget.h"
#include"menuwidget.h"
#include"addstudentwidget.h"
#include"modifystudentwidget.h"
#include"searchstudentwidget.h"
#include"sortstuwidget.h"
namespace Ui {
class mainControl;
}

class mainControl : public QWidget
{
    Q_OBJECT
private:
    QStackedLayout *stackedLayout;
    MenuWidget *menuwidget;
    AddStudentWidget *addstuwidget;
    ModifyStudentWidget *modifystuwidget;
    SearchStudentWidget *searchstuwidget;
    SortStuWidget *sortstuwidget;
    LoggingWidget *loggingWidget;
public:
    explicit mainControl(QWidget *parent = nullptr);
    ~mainControl();

private:
    Ui::mainControl *ui;
};

#endif // MAINCONTROL_H
