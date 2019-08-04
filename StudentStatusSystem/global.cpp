#include "global.h"

Global::Global()
{

}
bool GetStudentInfo(QVector<StudentInfo> &allStudentInfo)
{
    QFile file("StudentInfo.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    while (!file.isOpen()) {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return false;
    }
    QTextStream inp(&file);
    bool have=false;
    while(!inp.atEnd())
    {
        have=true;
        QString name,province,city,district;
        int id,math,english,programming,pe;
        inp>>name>>id>>math>>english>>programming>>pe>>province>>city>>district;
        allStudentInfo.push_back(StudentInfo(name,id,math,english,programming,pe,province,city,district));
    }
    if(have)
    {
        allStudentInfo.pop_back();
    }
    file.close();
    return true;
}
void WriteFile(QVector<StudentInfo>&allStudentInfo)
{
    QFile file("StudentInfo.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    while (!file.isOpen()) {
        QMessageBox::about(NULL,"错误","文件打开失败");
        return ;
    }
    QTextStream outp(&file);
    for(auto it: allStudentInfo)
    {
        QMessageBox::about(NULL,"",it.GetName());
        outp<<it.GetName()<<" "<<it.GetID()<<" "<<it.GetMathScore()<<" "<<it.GetEngScore()<<" "<<
        it.GetProScore()<<" "<<it.GetPEScore()<<" "<<it.GetProvince()<<" "<<it.GetCity()<<" "<<it.GetDistrict()<<endl;
    }
    file.close();
}
