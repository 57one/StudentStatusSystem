#include "modifystudentwidget.h"
#include "ui_modifystudentwidget.h"
#include"global.h"
#include"province.h"
ModifyStudentWidget::ModifyStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyStudentWidget)
{
    ui->setupUi(this);
    QFile file("F:\\country\\china\\provinces.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen())
    {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return ;
    }
    QTextStream inp(&file);
    QVector<Province>allProvince;
    QList<QString>ProvinceList;
    bool have=false;
    while(!inp.atEnd())
    {
        QString ProvinceNumber,ProvinceName;
        inp>>ProvinceNumber>>ProvinceName;
        allProvince.push_back(Province(ProvinceNumber,ProvinceName));
        ProvinceList.append(ProvinceName);
    }
    if(have)
        allProvince.pop_back();
    file.close();
    ui->Province->addItems(ProvinceList);
}

ModifyStudentWidget::~ModifyStudentWidget()
{
    delete ui;
}

void ModifyStudentWidget::on_btnQuit_clicked()
{
    emit display(1);
}

void ModifyStudentWidget::on_btnModify_clicked()
{
    if(ui->Name_Text->text()==""||ui->ID_Text->text()==""||ui->Math_Text->text()==""||
            ui->English_Text->text()==""||ui->Programming_Text->text()==""||
            ui->PE_Text->text()=="")
    {
        QMessageBox::about(NULL,"错误","存在空项");
        return ;
    }
    QVector<StudentInfo>allStudentInfo;
    if(!GetStudentInfo(allStudentInfo))
        return ;
    bool flag=false;
    for(QVector<StudentInfo>::iterator it=allStudentInfo.begin();it!=allStudentInfo.end();it++) //为什么没进入？？？？？
    {                                                                                           //进入了 但我啥也没改啊
        if(it->GetID()==ui->ID_Text->text().toInt())
        {
            flag=true;
            it->SetName(ui->Name_Text->text());
            it->SetMathScore(ui->Math_Text->text().toInt());
            it->SetEngScore(ui->English_Text->text().toInt());
            it->SetProScoer(ui->Programming_Text->text().toInt());
            it->SetPEScore(ui->PE_Text->text().toInt());
            it->SetProvince(ui->Province->currentText());
            it->SetCity(ui->City->currentText());
            it->SetDistrict(ui->District->currentText());
            break;
        }
    }
    if(flag)
    {
        QMessageBox::about(NULL,"反馈","修改成功");
        WriteFile(allStudentInfo);
    }
    else
        QMessageBox::about(NULL,"反馈","id不存在");
    ui->ID_Text->clear();
}

void ModifyStudentWidget::on_btnDelete_clicked()
{

    if(ui->ID_Text->text()=="")
    {
        QMessageBox::about(NULL,"错误","id不得为空");
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
            allStudentInfo.erase(it);
            break;
        }
    }
    if(flag)
    {
        QMessageBox::about(NULL,"反馈","删除成功");
        WriteFile(allStudentInfo);
    }
    else
        QMessageBox::about(NULL,"反馈","id不存在");
    ui->ID_Text->clear();
}

void ModifyStudentWidget::on_Province_currentIndexChanged(const QString &arg1)
{
    ui->City->clear();
    QString DatAddress="F:\\country\\china\\"+arg1+"\\"+arg1+"Cities.txt";
    QFile file(DatAddress);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen())
    {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return ;
    }
    QTextStream inp(&file);
    QVector<Province>allProvince;
    QList<QString>ProvinceList;
    bool have=false;
    while(!inp.atEnd())
    {
        QString ProvinceNumber,ProvinceName;
        inp>>ProvinceNumber>>ProvinceName;
        allProvince.push_back(Province(ProvinceNumber,ProvinceName));
        ProvinceList.append(ProvinceName);
    }
    if(have)
        allProvince.pop_back();
    file.close();
    ui->City->addItems(ProvinceList);
}

void ModifyStudentWidget::on_City_currentIndexChanged(const QString &arg1)
{
    ui->District->clear();
    QString DatAddress="F:\\country\\china\\"+ui->Province->currentText()+"\\"+ui->Province->currentText()+"Cities\\"+arg1+".txt";
    QFile file(DatAddress);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    /*if(!file.isOpen())
    {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return ;
    }*/
    QTextStream inp(&file);
    QVector<Province>allProvince;
    QList<QString>ProvinceList;
    bool have=false;
    while(!inp.atEnd())
    {
        QString ProvinceNumber,ProvinceName;
        inp>>ProvinceNumber>>ProvinceName;
        allProvince.push_back(Province(ProvinceNumber,ProvinceName));
        ProvinceList.append(ProvinceName);
    }
    if(have)
        allProvince.pop_back();
    file.close();
    ui->District->addItems(ProvinceList);
}
