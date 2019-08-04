#include "searchstudentwidget.h"
#include "ui_searchstudentwidget.h"
#include "global.h"

SearchStudentWidget::SearchStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchStudentWidget)
{
    ui->setupUi(this);
}

SearchStudentWidget::~SearchStudentWidget()
{
    delete ui;
}

void SearchStudentWidget::on_btnQuit_clicked()
{
    emit display(1);
}

void SearchStudentWidget::on_btnSearch_clicked()
{
   if(ui->ID_Text->text()=="")
    {
        QMessageBox::about(NULL,"反馈","id为空");
        return ;
    }
    QVector<StudentInfo>allStudentInfo;
    if(!GetStudentInfo(allStudentInfo))
        return ;
    bool flag=false;
    for(QVector<StudentInfo>::iterator it=allStudentInfo.begin();it!=allStudentInfo.end();it++)
    {
        if(it->GetID()==ui->ID_Text->text().toInt())
        {
            flag=true;
            ui->Name_Label->setText(it->GetName());
            ui->Math_Label->setText(QString::number(it->GetMathScore()));
            ui->Eng_Label->setText(QString::number(it->GetEngScore()));
            ui->Pro_Label->setText(QString::number(it->GetProScore()));
            ui->PE_Label->setText(QString::number(it->GetPEScore()));
            ui->Province->setText(it->GetProvince());
            ui->City->setText(it->GetCity());
            ui->District->setText(it->GetDistrict());
            break;
        }
    }
    if(flag)
        QMessageBox::about(NULL,"反馈","查找成功");
    else
        QMessageBox::about(NULL,"反馈","id不存在");

}
