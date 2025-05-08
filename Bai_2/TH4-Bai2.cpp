#include <iostream>
#include "PhanSo.h"
int main()
{
	PhanSo x, y, r;
	cout << "Nhap phan so thu nhat: " << endl;
	cin >> x;
	cout << "Nhap phan so thu hai: " << endl;
	cin >> y;
	r = x + y;
	cout << x << " + " << y << " = "<<r<<endl;
	r = x - y;
	cout << x << " - " << y << " = "<<r<<endl;
	r = x * y;
	cout << x << " * " << y << " = "<<r<<endl;
	if (y.getTu() == 0)
	{
		cout << "Phep chia khong hop le!" << endl;
	}
	else
	{
		r = x / y;
		cout << x << " / " << y << " = "<<r<<endl;
	}
	if (x > y) cout << "Phan so 1 lon hon phan so 2";
	else if (x < y) cout << "Phan so 2 lon hon phan so 1";
	else cout << "Phan so 1 bang phan so 2";
}
