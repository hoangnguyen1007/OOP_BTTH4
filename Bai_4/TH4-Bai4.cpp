#include "CDate.h"
#include <iomanip>
int main()
{
	CDate x, y;
	cin >> x;
	cout << "Ngay thang nam sau khi nhap: " << x << endl;
	cout << "Ngay thang nam sau khi cong 1 ngay: " << ++x << endl;
	cout << "Ngay thang nam sau khi tru 1 ngay: " << --(--x) << endl;
	cout << "Nhap so ngay de cong/tru: " ;
	int k;
	cin >> k;
	cout << "Ngay thang nam sau khi cong " << k << " ngay: " << x + k<<endl;
	cout << "Ngay thang nam sau khi tru " << k << " ngay: " << x - k - k<<endl;
	cout << "Nhap ngay thang nam de tinh khoang cach giua 2 date: "<<endl;
	cin >> y;
	cout << "Khoang cach giua 2 ngay thang nam la: " << x - y << " ngay"<<endl;
	cout << "--------TINH LAI SUAT TIEN GUI NGAN HANG---------" << endl;
	CDate ngay_gui, ngay_rut;
	double so_tien_gui, lai_suat_nam;

	cout << "Nhap ngay gui: "<<endl;
	cin >> ngay_gui;

	cout << "Nhap ngay rut: "<<endl;
	cin >> ngay_rut;

	cout << "Nhap so tien gui: ";
	cin >> so_tien_gui;

	cout << "Nhap lai suat: ";
	cin >> lai_suat_nam;
	double lai = tinh_lai_suat(so_tien_gui, lai_suat_nam, ngay_gui, ngay_rut);
	cout << "So tien lai: " << fixed<<setprecision(0)<< lai << " VND" << std::endl;
}