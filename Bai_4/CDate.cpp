#include "CDate.h"
// Hàm tính lãi suất bằng cách nhận vào số tiền gửi, lãi suất, ngày gửi và ngày rút
// Sau đó tính toán bằng công thức tính lãi suất và trả về kết quả
double tinh_lai_suat(double so_tien_gui, double lai_suat_nam, CDate ngay_gui, CDate ngay_rut)
{
	int so_ngay_gui = ngay_rut - ngay_gui;
	if (so_ngay_gui < 0)
	{
		std::cerr << "Ngay rut phai lon hon ngay gui!" << endl;
		return 0.0;
	}
	double lai = so_tien_gui * (lai_suat_nam / 100) * so_ngay_gui / 365;
	return lai;
}
// Hàm kiểm tra và trả về giá trị bool của phép kiểm tra xem năm đó có phải năm nhuận không
bool nam_nhuan(int nam)
{
	return(nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
// Hàm nhận vào tháng và năm và trả về số ngày trong tháng năm đó
int so_ngay_trong_thang(int thang, int nam)
{
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (nam_nhuan(nam)) return 29;
		else return 28;
	}
}
// Hàm kiểm tra và trả về giá trị bool xem dữ liệu ngày, tháng, năm có hợp lệ không
bool CDate::ktra_hop_le()
{
	return ngay > 0 && thang > 0 && nam > 0 && thang <= 12 && ngay <= so_ngay_trong_thang(thang, nam);
}
// Hàm khởi tạo mặc định của lớp CDate gán giá trị mặc định là thời điểm hiện tại
CDate::CDate()
{
	ngay = ltm->tm_mday;
	thang = ltm->tm_mon + 1;
	nam = ltm->tm_year + 1990;
}
//Hàm khởi tạo truyền tham số ngày. Tháng và năm sẽ là thời điểm hiện tại
CDate::CDate(int ngay) : ngay(ngay)
{
	thang = ltm->tm_mon + 1;
	nam = ltm->tm_year + 1990;
	if (!ktra_hop_le()) ngay = ltm->tm_mday;
}
//Hàm khởi tạo truyền tham số ngày, tháng. Năm sẽ là thười điểm hiện tại
CDate::CDate(int ngay, int thang) : ngay(ngay), thang(thang)
{
	nam = ltm->tm_year + 1990;
	if (!ktra_hop_le())
	{
		ngay = ltm->tm_mday;
		thang = ltm->tm_mon;
	}
}
//Hàm khởi tạo truyền tham số ngày, tháng, năm. Nếu không hợp lệ sẽ là thời điểm hiện tại
CDate::CDate(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam)
{
	if (!ktra_hop_le())
	{
		ngay = ltm->tm_mday;
		thang = ltm->tm_mon;
		nam = ltm->tm_year;
	}
}
//Hàm bạn nạp chồng toán tử nhập và kiểm tra dữ liệu nhập
istream& operator>>(istream& is, CDate& x)
{
	cout << "Nhap ngay thang nam: ";
	is >> x.ngay >> x.thang >> x.nam;
	while (!x.ktra_hop_le() || cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Nhap ngay thang nam: ";
		is >> x.ngay >> x.thang >> x.nam;
	} 
	return is;
}
//Hàm bạn nạp chồng toán tử xuất, xuất theo chuẩn ngày tháng năm
ostream& operator<<(ostream& os, CDate x)
{
	if (x.ngay < 10) cout << 0;
	cout << x.ngay<<"/";
	if (x.thang < 10) cout << 0;
	cout << x.thang << "/";
	cout << x.nam;
	return os;
}
//Hàm cộng ngày tháng năm với một số nguyên và đảm bảo ngày tháng năm hợp lệ
CDate CDate::operator+(int x)
{
	ngay += x;
	while (ngay > so_ngay_trong_thang(thang, nam))
	{
		ngay -= so_ngay_trong_thang(thang, nam);
		thang++;
		if (thang > 12)
		{
			thang = 1;
			nam++;
		}
	}
	return CDate(ngay, thang, nam);
}
//Hàm trừ ngày tháng năm với một số nguyên và đảm bảo ngày tháng năm hợp lệ
CDate CDate::operator-(int x)
{
	ngay -= x;
	while (ngay <= 0)
	{
		thang--;
		if (thang <= 0)
		{
			thang = 12;
			nam--;
		}
		ngay = so_ngay_trong_thang(thang, nam) - abs(ngay);
	}
	return CDate(ngay, thang, nam);
}
//Hàm tính số ngày từ đàu năm tới thời điểm hiện tại
int CDate::so_ngay_toi_ht()
{
	int res = 0;
	for (int i = 1; i < thang; i++)
	{
		res += so_ngay_trong_thang(i, nam);
	}
	res += ngay;
	return res;
}
//Hàm tính khoảng các giữa hai thời điểm, đảm bảo có thể trừ qua lại
int CDate::operator-(CDate x)
{
	int res = 0;
	CDate earlier = *this, later = x;
	if (this->nam > x.nam || (this->nam == x.nam && this->thang > x.thang) ||
		(this->nam == x.nam && this->thang == x.thang && this->ngay > x.ngay))
	{
		earlier = x;
		later = *this;
	}
	for (int i = earlier.nam; i < later.nam; i++)
	{
		if (nam_nhuan(i)) res += 366;
		else res += 365;
	}
	res += later.so_ngay_toi_ht() - earlier.so_ngay_toi_ht();
	return res;
}
//Hàm cộng trước, cho phép cộng thêm 1 ngày vào thời điểm hiện tại và đảm bảo 
//ngày tháng năm nằm hợp lệ
CDate CDate::operator++()
{
	ngay++;
	if (ngay > so_ngay_trong_thang(thang, nam))
	{
		ngay = 1;
		thang++;
		if (thang > 12)
		{
			nam++;
			thang = 1;
		}
	}
	return *this;
}
//Hàm cộng sau, cho phép cộng thêm 1 ngày vào thời điểm hiện tại và đảm bảo 
//ngày tháng năm nằm hợp lệ
CDate CDate::operator++(int)
{
	CDate tmp = *this;
	++*this;
	return tmp;
}
//Hàm trừ trước, cho phép trừ đi 1 ngày vào thời điểm hiện tại và đảm bảo 
//ngày tháng năm nằm hợp lệ
CDate CDate::operator--()
{
	ngay--;
	if (ngay < 1)
	{
		ngay = so_ngay_trong_thang(thang, nam);
		thang--;
		if (thang < 1)
		{
			nam--;
			thang = 12;
		}
	}
	return *this;
}
//Hàm trừ sau, cho phép trừ đi 1 ngày vào thời điểm hiện tại và đảm bảo 
//ngày tháng năm nằm hợp lệ
CDate CDate::operator--(int)
{
	CDate tmp = *this;
	--*this;
	return tmp;
}

