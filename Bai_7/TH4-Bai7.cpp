#include "CMatrix.h"

int main()
{
	CMatrix x, y;
	CVector v;
	int k;
	cout << "Nhap ma tran thu nhat: " << endl;
	cin >> x;
	cout << "Nhap ma tran thu hai: " << endl;
	cin >> y;
	cout << "Nhap mot so nguyen: ";
	cin >> k;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Vui long nhap lai!" << endl;
		cout << "Nhap mot so nguyen: ";
		cin >> k;
	}
	cout << "Nhap mot vector: " << endl;
	cin >> v;
	if (x.getDong() == 0 && x.getCot() == 0) cout << "Ma tran thu nhat rong!" << endl;
	else
	{
		cout << "Ma tran thu nhat: " << endl;
		cout << x;
	}
	if (y.getDong() == 0 && y.getCot() == 0) cout << "Ma tran thu hai rong!" << endl;
	else
	{
		cout << "Ma tran thu hai: " << endl;
		cout << y;
	}
	cout << "------------Ket qua cua cac phep tinh------------" << endl;
	CMatrix kq;
	if (x.getCot() == y.getCot() && x.getDong() == y.getDong())
	{
		cout << "Ma tran 1 + Ma tran 2: " << endl;
		kq = x + y;
		cout << kq;
	}
	else cout << "Khong the thuc hien phep cong!" << endl;
	if (x.getCot() == y.getCot() && x.getDong() == y.getDong())
	{
		cout << "Ma tran 1 - Ma tran 2: " << endl;
		kq = x - y;
		cout << kq;
	}
	else cout << "Khong the thuc hien phep tru!" << endl;
	if (x.getCot() == y.getDong())
	{
		cout << "Ma tran 1 * Ma tran 2: " << endl;
		kq = x * y;
		cout << kq;
	}
	else cout << "Khong the nhan hai ma tran!" << endl;
	if (x.getCot() == v.getSize())
	{
		cout << "Ma tran 1 * Vector: " << endl;
		kq = x * v;
		cout << kq;
	}
	else
	{
		cout << "Khong the nhan ma tran 1 voi vector!" << endl;
	}
	if (y.getCot() == v.getSize())
	{
		cout << "Ma tran 2 * Vector: " << endl;
		kq = y * v;
		cout << kq;
	}
	else
	{
		cout << "Khong the nhan ma tran 2 voi vector!" << endl;
	}
}