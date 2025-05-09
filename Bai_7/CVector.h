#pragma once
#include <iostream>
#include <vector>
using namespace std;
class CVector {
private:
    vector<double> duLieu;
public:
    CVector(const vector<double>& v);
    CVector(int soChieu = 0, double giaTriMacDinh = 0.0);
    int getSize();
    double& operator[](int i);
    const double& operator[](int i) const;
    int laySoChieu() const;
    CVector operator+(const CVector& vkhac) const;
    CVector operator-(const CVector& vkhac) const;
    CVector operator*(double voHuong) const;
    friend ostream& operator<<(ostream& os, const CVector& v);
    friend istream& operator>>(istream& is, CVector& v);
    const vector<double>& getDuLieu() const {
        return duLieu;
    }
};
