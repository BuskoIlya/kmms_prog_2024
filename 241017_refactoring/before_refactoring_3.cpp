#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a[20], i, b;
    for (i = 0; i < 20; i++)
    {
        a[i] = rand() % 20;
        cout << a[i];
        cout << ' ';
    }
    cout << endl;
    for (i = 0; i < 10; i++)
    {
        b = a[i];
        a[i] = a[19 - i];
        a[19 - i] = b;
    }
    for (i = 0; i < 20; i++)
    {
        cout << a[i];
        cout << ' ';
    }

    return 0;
}
