#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return ((a > b) ? (a) : (b));
}
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        string a;
        cin >> n;
        cin >> a;
        int s = 0;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (c == 3)
            {
                break;
            }
            if (a[i] == '.')
            {
                s += 1;
                c += 1;
            }
            else
                c = 0;
        }
        cout << ((c == 3) ? (2) : (s)) << endl;
    }
    return 0;
}