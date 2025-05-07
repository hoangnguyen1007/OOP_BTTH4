#include <iostream>
#include "SoPhuc.h"
int main()
{
    SoPhuc x, y;
    cout << "Nhap so phuc thu nhat: " << endl;
    cin >> x;
    cout << "Nhap so phuc thu hai: " << endl;
    cin >> y;
    cout << "(" << x << ")" << " + " << "(" << y << ")" << " = " << x + y << endl;
    cout << "(" << x << ")" << " - " << "(" << y << ")" << " = " << x - y <<endl;
    cout << "(" << x << ")" << " * " << "(" << y << ")" << " = " << x * y <<endl;
    if (y.getThuc() == 0 && y.getAo() == 0)
    {
        cout << "Phep chia khong hop le!" << endl;
    }
    else
    {
        cout << "(" << x << ")" << " / " << "(" << y << ")" << " = " << x / y<<endl;
    }
    if (x == y)
    {
        cout << "Hai so phuc bang nhau!";
    }
    else
    {
        cout << "Hai so phuc khong bang nhau!";
    }
    return 0;
}

