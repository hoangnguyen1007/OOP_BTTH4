#include "cDaThuc.h"

int main()
{
	cDaThuc x, y;
	cout << "Nhap da thuc thu nhat: "<<endl;
	cin >> x;
	cout << "Nhap da thuc thu hai: " << endl;
	cin >> y;
	if (x.getN() == 0) cout << "Da thuc thu nhat rong!" << endl;
	else
	{
		cout << "Da thuc thu nhat: ";
		cout << x<<endl;
	}
	if (y.getN() == 0) cout << "Da thuc thu hai rong!" << endl;
	else
	{
		cout << "Da thuc thu hai: ";
		cout << y<<endl;
	}
	if (x.getN() == 0 && y.getN() == 0) cout << "Ket qua cong hai da thuc: 0" << endl;
	else cout << "Ket qua cong hai da thuc: " << x + y << endl;
	if (x.getN() == 0 && y.getN() == 0) cout << "Ket qua tru hai da thuc: 0" << endl;
	else cout << "Ket qua tru hai da thuc: " << x - y << endl;
	cDaThuc r = x * y;
	if (x.getN() == 0 || y.getN() == 0)
	{
		cout << "Khong co ket qua nhan hai da thuc!" << endl;
	}
	else
	{
		cout << "Ket qua nhan hai da thuc: " << x * y << endl;
	}
}