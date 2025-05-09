#pragma once
#include <iostream>
#include <vector>
using namespace std;
class cDaThuc
{
private:
	int n;
	vector<double> he_so;
public:
	cDaThuc();
	cDaThuc(const vector<double>);
	friend istream& operator>>(istream&, cDaThuc&);
	friend ostream& operator<<(ostream&, cDaThuc);
	cDaThuc operator+(cDaThuc);
	cDaThuc operator-(cDaThuc);
	cDaThuc operator*(cDaThuc);
	int getN();
};

