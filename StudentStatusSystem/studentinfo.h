#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include"QString"
class StudentInfo
{
private:
    QString Name;
    int ID,MathScore,EngScore,ProScore,PEScore;
    QString Province,City,District;
public:
    StudentInfo(){}
    StudentInfo(QString Name,int ID,int MathScore,int EngScore,int ProScore,
                int PEScore,QString Province,QString City,
                QString District):Name(Name),ID(ID),MathScore(MathScore),EngScore(EngScore),ProScore(ProScore),
        PEScore(PEScore),Province(Province),City(City),District(District){}
    QString GetName()const{return Name;}
    int GetID()const{return ID;}
    int GetMathScore()const{return MathScore;}
    int GetEngScore()const{return EngScore;}
    int GetProScore()const{return ProScore;}
    int GetPEScore()const{return PEScore;}
    QString GetProvince()const{return Province;}
    QString GetCity()const{return City;}
    QString GetDistrict()const{return District;}
    void SetName(QString name){Name=name;}
    void SetMathScore(int mathScore){MathScore=mathScore;}
    void SetEngScore(int engScore){EngScore=engScore;}
    void SetProScoer(int proScore){ProScore=proScore;}
    void SetPEScore(int peScore){PEScore=peScore;}
    void SetProvince(QString province){Province=province;}
    void SetCity(QString city){City=city;}
    void SetDistrict(QString district){District=district;}
};
#endif // STUDENTINFO_H
