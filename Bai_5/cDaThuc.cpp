#include "cDaThuc.h"
//Hàm constructor mặc định của lớp đa thức
cDaThuc::cDaThuc()
{
	n = 0;
}
//Hàm constructor sao chép của lớp đa thức
cDaThuc::cDaThuc(const vector<double> x)
{ 
	n = x.size();
	for (int i = 0; i < n; i++)
	{
		he_so.push_back(x[i]);
	}
}
//Hàm bạn nạp chồng toán tử nhập, cho phép nhập và kiểm tra dữ liệu nhập
istream& operator>>(istream& is, cDaThuc& x)
{
	x.he_so.clear();
	cout << "Nhap so phan tu: ";
	cin >> x.n;
	while (x.n < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so phan tu: ";
		cin >> x.n;
	}
	if (x.n == 0) return is;
	cout << "Nhap lan luot he so cua da thuc: ";
	for (int i = 0; i < x.n; i++)
	{
		double tmp;
		cin >> tmp;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Vui long nhap lai: ";
			cin >> tmp;
		}
		x.he_so.push_back(tmp);
	}
	return is;
}
//Hàm bạn nạp chồng toán tử xuất, xuất đa thức đúng chuẩn logic
ostream& operator<<(ostream& os, cDaThuc x)
{
	for (int i = 0; i < x.n; i++)
	{
		if (x.he_so[i] < 0) cout << x.he_so[i];
		else if (i != 0 && x.he_so[i] > 0) cout << "+ " << x.he_so[i];
		else if (x.he_so[i] != 0) cout << x.he_so[i];
		if (x.n - i - 1 == 0 || x.he_so[i] == 0) continue;
		else if (x.n - i - 1 == 1) cout << "x ";
		else cout << "x^" << x.n - i - 1 << " ";
	}
	return os;
}
//Hàm nạp chồng toán tử cộng, cho phép cộng hai đa thức theo công thức
cDaThuc cDaThuc::operator+(cDaThuc x)
{
	int largest = max(this->n, x.n);
	vector<double> a, b;
	a = this->he_so;
	b = x.he_so;
	while (a.size() < largest) a.insert(a.begin(), 0);
	while (b.size() < largest) b.insert(b.begin(), 0);
	vector<double> kq;
	for (int i = 0; i < largest; i++)
	{
		kq.push_back(a[i] + b[i]);
	}
	return cDaThuc(kq);
}
//Hàm nạp chồng toán tử trừ, cho phép trừ hai đa thức theo công thức
cDaThuc cDaThuc::operator-(cDaThuc x)
{
	int largest = max(this->n, x.n);
	vector<double> a, b;
	a = this->he_so;
	b = x.he_so;
	while (a.size() < largest) a.insert(a.begin(), 0);
	while (b.size() < largest) b.insert(b.begin(), 0);
	vector<double> kq;
	for (int i = 0; i < largest; i++)
	{
		kq.push_back(a[i] - b[i]);
	}
	return cDaThuc(kq);
}
//Hàm getter cho phép lấy và trả về giá trị của bậc của đa thức
int cDaThuc::getN()
{
	return n;
}
//Hàm nạp chồng toán tử nhân, cho phép nhân hai đa thức với nhau theo công thức
cDaThuc cDaThuc::operator*(cDaThuc x) 
{
	if (n == 0 || x.n == 0) {
		return cDaThuc(); // Trả về đa thức rỗng
	}
	vector<double> kq(n + x.n - 1, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < x.n; j++)
			kq[i + j] += he_so[i] * x.he_so[j];
	return cDaThuc(kq);
}