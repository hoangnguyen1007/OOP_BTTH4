#pragma once
#include <iostream>
using namespace std;
class SoPhuc
{
private:
	double ao, thuc;
public:		
	SoPhuc();
	SoPhuc(double, double);
	double getThuc();
	double getAo();
	friend istream& operator>>(istream& is, SoPhuc&);
	friend ostream& operator<<(ostream& os, SoPhuc);
	friend SoPhuc operator+(SoPhuc, SoPhuc);
	friend SoPhuc operator+(SoPhuc, double);
	friend SoPhuc operator+(double, SoPhuc);
	friend SoPhuc operator-(SoPhuc, SoPhuc);
	friend SoPhuc operator-(SoPhuc, double);
	friend SoPhuc operator-(double, SoPhuc);
	friend SoPhuc operator*(SoPhuc, SoPhuc);
	friend SoPhuc operator*(SoPhuc, double);
	friend SoPhuc operator*(double, SoPhuc);
	friend SoPhuc operator/(SoPhuc, SoPhuc);
	friend SoPhuc operator/(SoPhuc, double);
	friend SoPhuc operator/(double, SoPhuc);
	friend bool operator==(SoPhuc, SoPhuc);
	friend bool operator!=(SoPhuc, SoPhuc);
};

