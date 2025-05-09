#include "CVector.h"
#include <numeric>

CVector::CVector(const vector<double>& v) : duLieu(v) {}

CVector::CVector(int soChieu, double giaTriMacDinh) : duLieu(soChieu, giaTriMacDinh) {}

double& CVector::operator[](int i)
{
    if (i < 0 || i >= duLieu.size()) 
    {
        throw out_of_range("Chi so vuot qua gioi han");
    }
    return duLieu[i];
}

const double& CVector::operator[](int i) const 
{
    if (i < 0 || i >= duLieu.size())
    {
        throw out_of_range("Chi so vuot qua gioi han");
    }
    return duLieu[i];
}

int CVector::laySoChieu() const 
{
    return duLieu.size();
}
int CVector::getSize()
{
    return duLieu.size();
}
CVector CVector::operator+(const CVector& vkhac) const
{
    CVector ketQua(duLieu.size());
    for (int i = 0; i < duLieu.size(); ++i)
    {
        ketQua.duLieu[i] = duLieu[i] + vkhac.duLieu[i];
    }
    return ketQua;
}

CVector CVector::operator-(const CVector& vkhac) const
{
    CVector ketQua(duLieu.size());
    for (int i = 0; i < duLieu.size(); ++i)
    {
        ketQua.duLieu[i] = duLieu[i] - vkhac.duLieu[i];
    }
    return ketQua;
}

CVector CVector::operator*(double x) const
{
    CVector ketQua(duLieu.size());
    for (int i = 0; i < duLieu.size(); ++i)
    {
        ketQua[i] = duLieu[i] * x; 
    }
    return ketQua;
}

ostream& operator<<(ostream& os, const CVector& v) 
{
    os << "[";
    for (int i = 0; i < v.duLieu.size(); ++i)
    {
        os << v.duLieu[i];
        if (i < v.duLieu.size() - 1) 
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

istream& operator>>(istream& is, CVector& v)
{
    int soChieu;
    cout << "Nhap so chieu: ";
    is >> soChieu;
    v.duLieu.resize(soChieu);
    cout << "Nhap lan luot cac gia tri: ";
    for (int i = 0; i < soChieu; ++i) 
    {
        is >> v.duLieu[i];
    }
    return is;
}
