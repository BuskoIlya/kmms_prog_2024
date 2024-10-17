#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int i; float a[10], b[10], c[10];
    float sa, sb, sc;
    sa = 0;
    sb = 0;
    sc = 0;
    cout << "pervaja posledovatelnost" << endl;
    for (i = 0; i < 10; i++)
    {
        a[i] = rand() % 10;
        cout << a[i];
        cout << ' ';
        sa = sa + a[i];
    }
    cout << ' ' << endl;
    cout << "srednee pervoy posledovatelnocty =" << sa / 10 << endl;
    cout << "vtoraja posledovatelnost" << endl;
    for (i = 0; i < 10; i++)
    {
        b[i] = rand() % 10;
        cout << b[i];
        cout << ' ';
        sb = sb + b[i];
    }
    cout << ' ' << endl;
    cout << "srednee vtoroy posledovatelnocty =" << sb / 10 << endl;
    cout << "tretja posledovatelnost" << endl;
    for (i = 0; i < 10; i++)
    {
        c[i] = rand() % 10;
        cout << c[i];
        cout << ' ';
        sc = sc + c[i];
    }
    cout << ' ' << endl;
    cout << "srednee tretjey posledovatelnocty =" << sc / 10 << endl;

    return 0;
}
