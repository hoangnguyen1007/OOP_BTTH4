#include "SoPhuc.h"
//Hàm constructor mặc định của lớp số phức
SoPhuc::SoPhuc()
{
	ao = 0;
	thuc = 0;
}
//Hàm constructor truyền tham số của lớp số phức
SoPhuc::SoPhuc(double thuc, double ao)
{
	this->thuc = thuc;
	this->ao = ao;
}
//Hàm getter trả về giá trị phần thực
double SoPhuc::getThuc()
{
	return thuc;
}
//Hàm getter trả về giá trị của phần ảo
double SoPhuc::getAo()
{
	return ao;
}
//Hàm bạn nạp chồng toán tử nhập, cho phép nhập và kiểm tra dữ liệu đầu vào của 1 số phức
istream& operator>>(istream& is, SoPhuc& x)
{
	cout << "Nhap phan thuc: ";
	is >> x.thuc;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap phan thuc: ";
		is >> x.thuc;
	}
	cout << "Nhap phan ao: ";
	is >> x.ao;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap phan ao: ";
		is >> x.ao;
	}
	return is;
}
//Hàm bạn nạp chồng toán tử xuất, xuất định dạng số phức chuẩn theo logic
ostream& operator<<(ostream& os, SoPhuc x)
{
	if (x.thuc == 0)
	{
		cout << "";
		if (x.ao == 0)
		{
			cout << 0;
			return os;
		}
		cout << x.ao << "i";
		return os;
	}
	else
	{
		cout << x.thuc;
		if (x.ao < 0) cout << " - " << -x.ao << "i";
		else if (x.ao > 0) cout << " + " << x.ao << "i";
		else return os;
	}
	return os;
}
//Hàm nạp chồng toán tử cộng 2 số phức, cho phép cộng 2 số phức theo công thức và trả về số phức kết quả
SoPhuc operator+(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = a.thuc + b.thuc;
	kq.ao = a.ao + b.ao;
	return kq;
}
//Hàm nạp chông toán tử cộng số phức với 1 số nguyên, cho phép cộng số phức với 1 số nguyên và trả về số phức kq
SoPhuc operator+(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc + x;
	kq.ao = a.ao;
	return kq;
}
//Hàm nạp chồng toán tử cộng 1 số nguyên với số phức, cho phép cộng 1 số nguyên với số phức và trả về số phức kết quả
SoPhuc operator+(double x, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = x + b.thuc;
	kq.ao = b.ao;
	return kq;
}
//Hàm nạp chồng toán tử trừ 2 số phức, cho phép trừ 2 số phức theo công thức và trả về số phức kết quả
SoPhuc operator-(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = a.thuc - b.thuc;
	kq.ao = a.ao - b.ao;
	return kq;
}
//Hàm nạp chông toán tử trừ số phức với 1 số nguyên, cho phép trừ số phức với 1 số nguyên và trả về số phức kq
SoPhuc operator-(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc - x;
	kq.ao = a.ao;
	return kq;
}
//Hàm nạp chồng toán tử trừ 1 số nguyên với số phức, cho phép trừ 1 số nguyên với số phức và trả về số phức kết quả
SoPhuc operator-(double x, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = x + b.thuc;
	kq.ao = b.ao;
	return kq;
}
//Hàm nạp chồng toán tử nhân 2 số phức, cho phép nhân 2 số phức theo công thức và trả về số phức kết quả
SoPhuc operator*(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = a.thuc * b.thuc;
	kq.ao = a.thuc * b.ao + a.ao * b.thuc;
	return kq;
}
//Hàm nạp chông toán tử nhân số phức với 1 số nguyên, cho phép nhân số phức với 1 số nguyên và trả về số phức kq
SoPhuc operator*(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc * x;
	kq.ao = a.thuc + a.ao * x;
	return kq;
}
//Hàm nạp chồng toán tử nhân 1 số nguyên với số phức, cho phép nhân 1 số nguyên với số phức và trả về số phức kết quả
SoPhuc operator*(double x, SoPhuc a)
{
	SoPhuc kq;
	kq.thuc = a.thuc * x;
	kq.ao = a.thuc + a.ao * x;
	return kq;
}
//Hàm nạp chồng toán tử chia 2 số phức, cho phép chia 2 số phức theo công thức và trả về số phức kết quả
SoPhuc operator/(SoPhuc a, SoPhuc b)
{
	SoPhuc kq;
	kq.thuc = (a.thuc * b.thuc) + (a.ao * b.ao) / (b.thuc * b.thuc) + (b.ao * b.ao);
	kq.ao = (a.ao * b.thuc) - (a.thuc * b.ao) / (b.thuc * b.thuc) + (b.ao * b.ao);
	return kq;
}
//Hàm nạp chông toán tử chia số phức với 1 số nguyên, cho phép chia số phức với 1 số nguyên và trả về số phức kq
SoPhuc operator/(SoPhuc a, double x)
{
	SoPhuc kq;
	kq.thuc = a.thuc / x;
	kq.ao = a.ao / x;
	return kq;
}
//Hàm nạp chồng toán tử chia 1 số nguyên với số phức, cho phép chia 1 số nguyên với số phức và trả về số phức kết quả
SoPhuc operator/(double x, SoPhuc a)
{
	SoPhuc kq;
	kq.thuc = a.thuc / x;
	kq.ao = a.ao / x;
	return kq;
}
//Hàm nạp chồng toán tử so sánh bằng và trả về giá trị bool kết quả của phép so sánh 2 số phức
bool operator==(SoPhuc a, SoPhuc b)
{
	return ((a.thuc == b.thuc) && (a.ao == b.ao));
}
//Hàm nạp chồng toán tử so sánh không bằng và trả về giá trị bool kết quả của phép so sánh 2 số phức
bool operator!=(SoPhuc a, SoPhuc b)
{
	return ((a.thuc != b.thuc) && (a.ao != b.ao));
}