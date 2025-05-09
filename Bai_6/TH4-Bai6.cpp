#include "CVector.h"

int main()
{
	CVector x, y;
	cout << "Nhap thong tin vector thu nhat: " << endl;
	cin >> x;
	cout << "Nhap thong tin vector thu hai: " << endl;
	cin >> y;
	if (x.getSize() != y.getSize()) cout << "Hai vector phai cung so chieu moi co the cong!" << endl;
	else cout << "Ket qua phep cong 2 vector: " << x + y << endl;
	if (x.getSize() != y.getSize()) cout << "Hai vector phai cung so chieu moi co the tru!" << endl;
	else cout << "Ket qua phep tru 2 vector: " << x - y << endl;
	cout << "Nhap vector vo huong de nhan: ";
	int k;
	cin >> k;
	cout << "Vector thu nhat * vector vo huong la: " << x * k<<endl;
	cout<<"Vector thu nhat * vector vo huong la : " << y * k;
}