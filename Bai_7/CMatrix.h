#pragma once
#include <iostream>
#include <vector>
#include "CVector.h"
using namespace std;
class CMatrix
{
private:
	int dong, cot;
	vector<vector<double>> a;
public:
	CMatrix();
	CMatrix(const vector<vector<double>>);
	int getDong();
	int getCot();
	friend istream& operator >>(istream&, CMatrix&);
	friend ostream& operator <<(ostream&, CMatrix);
	CMatrix operator+(CMatrix);
	CMatrix operator-(CMatrix);
	CMatrix operator*(CMatrix);
	CMatrix operator*(double);
	CMatrix operator*(CVector);
};

