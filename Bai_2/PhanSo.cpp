#include "PhanSo.h"
//Hàm tính và trả về quả ước chung lớn nhất của hai số nguyên
int ucln(int a, int b)
{
	if (b == 0) return a;
	return ucln(b, a % b);
}
//Hàm rút gọn phân số bằng cách chia cả tử và mẫu cho ucln của chúng
void PhanSo::rut_gon()
{
	int u = ucln(tu, mau);
	tu /= u;
	mau /= u;
}
//Hàm constructor có truyền hai tham số tử và mẫu
PhanSo::PhanSo(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}
//Hàm bạn nạp chông toán tử nhập và kiểm tra dữ liệu nhập của 1 phân số
istream& operator>>(istream& is, PhanSo& x)
{
	cout << "Nhap tu so: ";
	is >> x.tu;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap tu so: ";
		is >> x.tu;
	}
	cout << "Nhap mau so: ";
	is >> x.mau;
	while (cin.fail() || x.mau == 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap mau so: ";
		is >> x.mau;
	}
	return is;
}
//Hàm bạn nạp chồng toán tử xuất theo đúng logic của 1 phân số
ostream& operator<<(ostream& os, PhanSo& x)
{
	x.rut_gon();
	if (x.tu % x.mau == 0) cout << x.tu / x.mau;
	else if (x.tu < 0 && x.mau < 0) cout << -x.tu << "/" << -x.mau;
	else if (x.tu < 0 || x.mau < 0) cout << -abs(x.tu) << "/" << abs(x.mau);
	else cout << x.tu << "/" << x.mau;
	return os;
}
//Hàm nạp chồng toán tử cộng, cho phép cộng 2 phân số bằng công thức cộng phân số thông thường
PhanSo PhanSo::operator+(const PhanSo& x) 
{
	int tu = this->tu * x.mau + x.tu * this->mau;
	int mau = this->mau * x.mau;
	return PhanSo(tu, mau);
}
//Hàm nạp chồng toán tử trừ, cho phép trừ 2 phân số bằng công thức trừ phân số thông thường 
PhanSo PhanSo::operator-(const PhanSo& x) 
{
	int tu = this->tu * x.mau - x.tu * this->mau;
	int mau = this->mau * x.mau;
	return PhanSo(tu, mau);
}
//Hàm nạp chồng toán tử nhân, cho phép nhân 2 phân số bằng công thức nhân phân số thông thường
PhanSo PhanSo::operator*(const PhanSo& x) 
{
	int tu = this->tu * x.tu;
	int mau = this->mau * x.mau;
	return PhanSo(tu, mau);
}
//Hàm nạp chồng toán tử chia, cho phép chia 2 phân số bằng công thức chia phân số thông thường
PhanSo PhanSo::operator/(const PhanSo& x)
{
	int tu = this->tu * x.mau;
	int mau = this->mau * x.tu;
	return PhanSo(tu, mau);
}
//Hàm getter lấy và trả về giá trị của tử số
int PhanSo::getTu()
{
	return tu;
}
// Toán tử dấu bé hơn
bool operator<(const PhanSo& a, const PhanSo& b)
{
	return a.tu * b.mau < b.tu * a.mau;
}

// Toán tử dấu lớn hơn
bool operator>(const PhanSo& a, const PhanSo& b)
{
	return a.tu * b.mau > b.tu * a.mau;
}

