#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu, mau;
public:
    PhanSo(int = 0, int = 1);
    void rut_gon();
    int getTu();
    PhanSo operator+(const PhanSo&);
    PhanSo operator-(const PhanSo&);
    PhanSo operator*(const PhanSo&);
    PhanSo operator/(const PhanSo&);
    friend istream& operator>>(istream&, PhanSo&);
    friend ostream& operator<<(ostream&, PhanSo&);
    friend bool operator <(const PhanSo&, const PhanSo&);
    friend bool operator >(const PhanSo&, const PhanSo&);
};
