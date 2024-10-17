#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int  i, b;
    double a[10];
    for (i = 0; i < 10; i++)
    {
        cout << "vvedite " << i << " element" << endl;
        cin >> a[i];
    }
    b = 1;
    i = 1;
    while ((b = 1) && (i <= 10))
    {
        if (a[i] <= a[i + 1])
            b = 1;
        else if (a[i] > a[i + 1])
            b = 0;
        i++;
    }
    if (b == 1) {
        cout << "posledovatelnost vozrastauchaja";
        cout << endl;
    }
    else if (b != 1) {
        cout << "posledovatelnost ne vozrastauchaja";
        cout << endl;
    }

    return 0;
}
