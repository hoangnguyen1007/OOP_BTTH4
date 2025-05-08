#pragma once
#include <iostream>
using namespace std;
class CTime
{
private:
	int iGio, iPhut, iGiay;
public:
	CTime();
	CTime(int, int, int);
	CTime(const CTime&);
	friend istream& operator >>(istream&, CTime&);
	friend ostream& operator<<(ostream&, CTime);
	CTime operator+(int);
	CTime operator-(int);
	CTime operator++();
	CTime operator++(int);
	CTime operator--();
	CTime operator--(int);
};

