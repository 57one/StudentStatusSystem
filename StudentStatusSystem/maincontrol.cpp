#include "maincontrol.h"
#include "ui_maincontrol.h"
mainControl::mainControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainControl)
{
    ui->setupUi(this);    //初始化界面
    stackedLayout=new QStackedLayout;   //QStackedLayoutlay对象的建立
    loggingWidget=new LoggingWidget;
    menuwidget=new MenuWidget;
    addstuwidget=new AddStudentWidget;
    modifystuwidget=new ModifyStudentWidget;
    searchstuwidget=new SearchStudentWidget;
    sortstuwidget=new SortStuWidget;
    stackedLayout->addWidget(loggingWidget);   //向stackedlayout中添加界面
    stackedLayout->addWidget(menuwidget);
    stackedLayout->addWidget(addstuwidget);
    stackedLayout->addWidget(modifystuwidget);
    stackedLayout->addWidget(searchstuwidget);
    stackedLayout->addWidget(sortstuwidget);
    setLayout(stackedLayout);                //设置界面
    connect(loggingWidget,&LoggingWidget::display,stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(menuwidget,&MenuWidget::display,stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(addstuwidget,&AddStudentWidget::display,stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(modifystuwidget,&ModifyStudentWidget::display,stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(searchstuwidget,&SearchStudentWidget::display,stackedLayout,&QStackedLayout::setCurrentIndex);
    connect(sortstuwidget,&SortStuWidget::display,stackedLayout,&QStackedLayout::setCurrentIndex);
}

mainControl::~mainControl()
{
    delete ui;
}
