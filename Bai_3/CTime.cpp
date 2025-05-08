#include "CTime.h"
//Hàm constructor mặc định
CTime::CTime() {};
//Hàm constructor truyền tham số là giờ, phút, giây
CTime::CTime(int iGio, int iPhut, int iGiay)
{
	this->iGio = iGio;
	this->iPhut = iPhut;
	this->iGiay = iGiay;
}
//Hàm constructor sao chép
CTime::CTime(const CTime& x)
{
	this->iGio = x.iGio;
	this->iPhut = x.iPhut;
	this->iGiay = x.iGiay;
}
//Hàm bạn nạp chồng toán tử nhập và kiểm tra dữ liệu nhập
istream& operator >>(istream& is, CTime& x)
{
	cout << "Nhap gio: ";
	cin >> x.iGio;
	while (cin.fail() || x.iGio < 0 || x.iGio > 23)
	{
		cin.clear();
		cin.ignore();
		cout << "Vui long nhap lai!" << endl;
		cout << "Nhap gio: ";
		cin >> x.iGio;
	}
	cout << "Nhap phut: ";
	cin >> x.iPhut;
	while (cin.fail() || x.iPhut < 0 || x.iPhut > 60)
	{
		cin.clear();
		cin.ignore();
		cout << "Vui long nhap lai!" << endl;
		cout << "Nhap phut: ";
		cin >> x.iPhut;
	}
	cout << "Nhap giay: ";
	cin >> x.iGiay;
	while (cin.fail() || x.iGiay < 0 || x.iGiay > 60)
	{
		cin.clear();
		cin.ignore();
		cout << "Vui long nhap lai!" << endl;
		cout << "Nhap gio: ";
		cin >> x.iGiay;
	}
	return is;
}
//Hàm bạn nạp chồng toán tử xuất đúng chuẩn giờ phút giây
ostream& operator<<(ostream& os, CTime x)
{
	if (x.iGio < 10) cout << 0;
	cout << x.iGio << ":";
	if (x.iPhut < 10) cout << 0;
	cout << x.iPhut << ":";
	if (x.iGiay < 10) cout << 0;
	cout << x.iGiay;
	return os;
}
//Hàm nạp chồng toán tử cộng một số nguyên giây 
CTime CTime::operator+(int x)
{

	CTime result = *this;
	int tong_giay = iGio * 3600 + iPhut * 60 + iGiay + x;

	tong_giay = (tong_giay % (24 * 3600) + (24 * 3600)) % (24 * 3600);

	result.iGio = tong_giay / 3600;
	tong_giay %= 3600;

	result.iPhut = tong_giay / 60;
	result.iGiay = tong_giay % 60;

	return result;
}
//Hàm nạp chông toán tử trừ 1 số nguyên giây
CTime CTime::operator-(int x)
{
	CTime result = *this;
	int tong_giay = iGio * 3600 + iPhut * 60 + iGiay - x;


	if (tong_giay < 0)
	{
		tong_giay = (24 * 3600 + tong_giay) % (24 * 3600);
	}

	result.iGio = tong_giay / 3600;
	tong_giay %= 3600;

	result.iPhut = tong_giay / 60;
	result.iGiay = tong_giay % 60;

	return result;
}
//Hàm nạp chồng toán tử cộng trước
CTime CTime::operator++()
{
	*this = *this + 1;
	return *this;
}
//Hàm nạp chồng toán tử cộng sau
CTime CTime::operator++(int)
{
	CTime temp = *this;
	*this = *this + 1;
	return temp;
}
//Hàm nạp chồng toán tử trừ trước
CTime CTime::operator--()
{
	*this = *this - 1; 
	return *this;
}
//Hàm nạp chồng toán tử trừ sau
CTime CTime::operator--(int)
{	
	CTime temp = *this;
	*this = *this - 1; 
	return temp;
}