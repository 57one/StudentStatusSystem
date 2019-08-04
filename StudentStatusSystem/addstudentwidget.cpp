#include "addstudentwidget.h"
#include "ui_addstudentwidget.h"

AddStudentWidget::AddStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudentWidget)
{
    ui->setupUi(this);
    QFile file("F:\\country\\china\\provinces.txt"); // 打开省的文档
    file.open(QIODevice::ReadOnly|QIODevice::Text);  //打开方式 readonly只读 text以文本形式打开
    if(!file.isOpen())                           //判断文件打开是否成功
    {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return ;
    }
    QTextStream inp(&file);                     //利用QTextStream读写文件
    QVector<Province>allProvince;               //利用QVector录入行政号及地区
    QList<QString>ProvinceList;                 //利用QList录入地区
    bool have=false;                            //检测是否录入信息
    while(!inp.atEnd())
    {
        have=true;
        QString ProvinceNumber,ProvinceName;
        inp>>ProvinceNumber>>ProvinceName;
        allProvince.push_back(Province(ProvinceNumber,ProvinceName));
        ProvinceList.append(ProvinceName);
    }
    if(have)                               //这里这个没有也可以
        allProvince.pop_back();
    file.close();
    ui->Province->addItems(ProvinceList);   //设置combobox的items
}

AddStudentWidget::~AddStudentWidget()
{
    delete ui;
}

void AddStudentWidget::on_btnQuit_clicked()
{
    emit display(1);
}

void AddStudentWidget::on_Province_currentIndexChanged(const QString &arg1)
{
    ui->City->clear(); //清空市combobox的内容
    QString DatAddress="F:\\country\\china\\"+arg1+"\\"+arg1+"Cities.txt";  //利用省combobox的改变来访问市文档
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

void AddStudentWidget::on_City_currentIndexChanged(const QString &arg1)
{
    ui->District->clear();
    QString DatAddress="F:\\country\\china\\"+ui->Province->currentText()+"\\"+ui->Province->currentText()+"Cities\\"+arg1+".txt";
    QFile file(DatAddress);      //利用省和市来访问区文档
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
void AddStudentWidget::on_btnAdd_clicked()
{
    if(ui->Name_Text->text()==""||ui->ID_Text->text()==""||ui->Math_Text->text()==""||
            ui->English_Text->text()==""||ui->Programming_Text->text()==""||
            ui->PE_Text->text()=="")
    {
        QMessageBox::about(NULL,"错误","存在空项");     //存在空项进行报错
        return ;
    }
    QFile file("StudentInfo.txt");              //打开文档 也可以使用绝对路径
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    while (!file.isOpen())
    {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return ;
    }
    QTextStream outp(&file);
    outp<<ui->Name_Text->text()<<" "<<ui->ID_Text->text()<<" "<<ui->Math_Text->text()<<" "<<ui->English_Text->text()<<" "
    <<ui->Programming_Text->text()<<" "<<ui->PE_Text->text()<<" "<<ui->Province->currentText()<<" "<<ui->City->currentText()<<
    " "<<ui->District->currentText()<<endl;
    file.close();
    QMessageBox::about(NULL,"反馈","录入成功");
    ui->Name_Text->clear();      //清空plaintext
    ui->ID_Text->clear();
    ui->Math_Text->clear();
    ui->English_Text->clear();
    ui->Programming_Text->clear();
    ui->PE_Text->clear();
    ui->Province->setCurrentText("北京市"); //设置为默认
}

