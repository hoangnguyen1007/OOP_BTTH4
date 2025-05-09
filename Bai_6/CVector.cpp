#include "CVector.h"
#include <numeric>
//Hàm constructor sao chép của lớp CVector 
CVector::CVector(const vector<double>& v) : duLieu(v) {}
//Hàm constructor mặc định và truyền tham số của lớp CVector
CVector::CVector(int soChieu, double giaTriMacDinh) : duLieu(soChieu, giaTriMacDinh) {}
//Hàm nạp chông toán tử [] cho phép truy cập và thay đổi giá trị của 1 phần tử trong vector
double& CVector::operator[](int i)
{
    if (i < 0 || i >= duLieu.size()) 
    {
        throw out_of_range("Chi so vuot qua gioi han");
    }
    return duLieu[i];
}
//Hàm nạp chồng toán tử [] cho phép lấy giá trị một phần tử trong vector
const double& CVector::operator[](int i) const 
{
    if (i < 0 || i >= duLieu.size())
    {
        throw out_of_range("Chi so vuot qua gioi han");
    }
    return duLieu[i];
}
//Hàm getter lấy và trả về số phần tử của vector
int CVector::getSize()
{
    return duLieu.size();
}
//Hàm getter lấy và trả về số chiều của vector 
int CVector::laySoChieu() const 
{
    return duLieu.size();
}
//Hàm nạp chồng toán tử cộng cho phép công hai vector khi chúng cùng số chiều
CVector CVector::operator+(const CVector& vkhac) const
{
    CVector ketQua(duLieu.size());
    for (int i = 0; i < duLieu.size(); ++i)
    {
        ketQua.duLieu[i] = duLieu[i] + vkhac.duLieu[i];
    }
    return ketQua;
}
//Hàm nạp chồng toán tử trừ cho phép công hai vector khi chúng cùng số chiều
CVector CVector::operator-(const CVector& vkhac) const
{
    CVector ketQua(duLieu.size());
    for (int i = 0; i < duLieu.size(); ++i)
    {
        ketQua.duLieu[i] = duLieu[i] - vkhac.duLieu[i];
    }
    return ketQua;
}
//Hàm nạp chồng toán tử nhân cho phép nhân 1 vector với 1 tích vô hướng theo công thức
CVector CVector::operator*(double x) const
{
    CVector ketQua(duLieu.size());
    for (int i = 0; i < duLieu.size(); ++i)
    {
        ketQua[i] = duLieu[i] * x; 
    }
    return ketQua;
}
//Hàm bạn nạp chông toán tử xuất, cho phép xuất từng phần tử trong vector
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
//Hàm nạp chồng toán tử nhập cho phép nhập và kiểm tra dữ liệu nhập
istream& operator>>(istream& is, CVector& v)
{
    int soChieu;
    cout << "Nhap so chieu: ";
    is >> soChieu;
    while (soChieu < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so chieu: ";
        is >> soChieu;
    }
    v.duLieu.resize(soChieu);
    if (soChieu == 0) return is;
    cout << "Nhap lan luot cac gia tri: ";
    for (int i = 0; i < soChieu; ++i) 
    {
        is >> v.duLieu[i];
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Khong hop le! Vui long nhap lai: ";
            is >> v.duLieu[i];
        }
    }
    return is;
}
