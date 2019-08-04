#include "sortstuwidget.h"
#include "ui_sortstuwidget.h"
#include"global.h"
SortStuWidget::SortStuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortStuWidget)
{
    ui->setupUi(this);
    buttonGroup=new QButtonGroup;
    buttonGroup->addButton(ui->rbtnMath,0);
    buttonGroup->addButton(ui->rbtnEnglish,1);
    buttonGroup->addButton(ui->rbtnProgramming,2);
    buttonGroup->addButton(ui->rbtnPE,3);
    buttonGroup->addButton(ui->rbtnProvince,4);
    buttonGroup->addButton(ui->rbtnID,5);
    buttonGroup->setExclusive(true);
    ui->tableWidget->setColumnCount(9);
    stringList<<tr("姓名")<<tr("学号")<<tr("数学成绩")<<("英语成绩")<<tr("程序设计成绩")<<tr("体育成绩")<<tr("省")<<tr("市")<<tr("区");
    ui->tableWidget->setHorizontalHeaderLabels(stringList);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(1);
}

SortStuWidget::~SortStuWidget()
{
    delete ui;
}

void SortStuWidget::on_pushButton_2_clicked()
{
    emit display(1);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(1);
}
bool cmp_Math(const StudentInfo &a,const StudentInfo &b)
{
    return a.GetMathScore()>b.GetMathScore();
}
bool cmp_English(const StudentInfo &a,const StudentInfo &b)
{
    return a.GetEngScore()>b.GetEngScore();
}
bool cmp_Programming(const StudentInfo &a,const StudentInfo &b)
{
    return a.GetProScore()>b.GetProScore();
}
bool cmp_PE(const StudentInfo &a,const StudentInfo &b)
{
    return a.GetPEScore()>b.GetPEScore();
}
bool cmp_ID(const StudentInfo &a,const StudentInfo &b)
{
    return a.GetID()>b.GetID();
}
bool cmp_Province(const StudentInfo &a,const StudentInfo &b)
{
    return a.GetProvince()>b.GetProvince();
}
void SortStuWidget::on_btnSort_clicked()
{
    QVector<StudentInfo>allStudentInfo;
    if(!GetStudentInfo(allStudentInfo))
        return ;
    int tag=buttonGroup->checkedId();
    switch (tag)
    {
    case 0:std::sort(allStudentInfo.begin(),allStudentInfo.end(),cmp_Math);break;
    case 1:std::sort(allStudentInfo.begin(),allStudentInfo.end(),cmp_English);break;
    case 2:std::sort(allStudentInfo.begin(),allStudentInfo.end(),cmp_Programming);break;
    case 3:std::sort(allStudentInfo.begin(),allStudentInfo.end(),cmp_PE);break;
    case 4:std::sort(allStudentInfo.begin(),allStudentInfo.end(),cmp_Province);break;
    case 5:std::sort(allStudentInfo.begin(),allStudentInfo.end(),cmp_ID);break;
    }
    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->setRowCount(allStudentInfo.size()); //设置行数与学生数相同 否则添加后显示不出来
    for(int i=0;i<allStudentInfo.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(allStudentInfo.at(i).GetName()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(allStudentInfo.at(i).GetID())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(allStudentInfo.at(i).GetMathScore())));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(allStudentInfo.at(i).GetEngScore())));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(allStudentInfo.at(i).GetProScore())));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(allStudentInfo.at(i).GetPEScore())));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(allStudentInfo.at(i).GetProvince()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(allStudentInfo.at(i).GetCity()));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(allStudentInfo.at(i).GetDistrict()));
    }
    ui->tableWidget->setSortingEnabled(true);
}
