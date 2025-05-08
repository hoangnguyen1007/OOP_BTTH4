#include "CTime.h"
int main()
{
	CTime x;
	cin >> x;
	cout << "Thoi gian vua nhap: " << x << endl;
	cout << "Thoi gian sau khi tru 1 giay: " << --x << endl;
	cout << "Thoi gian sau khi cong 1 giay: " << ++(++x) << endl;
	cout << "Nhap so giay muon cong/tru: ";
	int k;
	cin >> k;
	cout << "Thoi gian sau khi tru " << k << " giay: " << x - k << endl;
	cout << "Thoi gian sau khi cong " << k << " giay: " << x + k + k << endl;
}