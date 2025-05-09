#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
class CDate
{
private:
	int ngay, thang, nam;
	time_t now = time(0);
	tm* ltm = localtime(&now);
public:
	CDate();
	CDate(int ngay);
	CDate(int ngay, int thang);
	CDate(int ngay, int thang, int nam);
	bool ktra_hop_le();
	int so_ngay_toi_ht();
	friend istream& operator>>(istream&, CDate&);
	friend ostream& operator<<(ostream&, CDate);
	CDate operator+(int);
	CDate operator-(int);
	int operator-(CDate);
	CDate operator++();
	CDate operator++(int);
	CDate operator--();
	CDate operator--(int);
};
double tinh_lai_suat(double so_tien_gui, double lai_suat_nam, CDate ngay_gui, CDate ngay_rut);
