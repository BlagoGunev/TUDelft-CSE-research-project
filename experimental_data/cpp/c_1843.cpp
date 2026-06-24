#include <bits/stdc++.h>
using namespace std;
#define ul unsigned long long
int main()
{
    ul t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ul sum = n;
        while (n)
        {
            n = n / 2;
            sum += n;
        }
        cout << sum << endl;
    }
    return 0;
}