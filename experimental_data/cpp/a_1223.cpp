#include <iostream>
using namespace std;

long int n, i, a[100];

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] < 4)
            cout << 4 - a[i] << endl;
        else
            if (a[i] % 2 > 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
    }
}