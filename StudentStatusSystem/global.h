#ifndef GLOBAL_H
#define GLOBAL_H
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include"studentinfo.h"
class Global
{
public:
    Global();
};
bool GetStudentInfo(QVector<StudentInfo> &allStudentInfo);
void WriteFile(QVector<StudentInfo>&allStudentInfo);
#endif // GLOBAL_H
