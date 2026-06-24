#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int t[n];
    fill(t, t + n, 0);
    while (t[0] < 2)
    {
        int c = 0;
        for (int i = 0; i < n; ++i)
            c += a[i] * (t[i] ? 1 : -1);
        if (c % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
        t[n-1]++;
        for (int i = n-1; i; --i)
            if (t[i] == 2)
                t[i] = 0, t[i-1]++;
    }
    cout << "NO";
    return 0;
}