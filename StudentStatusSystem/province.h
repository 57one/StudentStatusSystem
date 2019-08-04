#ifndef PROVINCE_H
#define PROVINCE_H
#include<QString>
class Province
{
private:
    QString ProvinceNumber,ProvinceName;
public:
    Province(){}
    Province(QString ProvinceNumber,QString ProvinceName):ProvinceNumber(ProvinceNumber),ProvinceName(ProvinceName){}
    QString GetProName(){return ProvinceName;}
    QString GetProNumber(){return ProvinceNumber;}
};

#endif // PROVINCE_H
