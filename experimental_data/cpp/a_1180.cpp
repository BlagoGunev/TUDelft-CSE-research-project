#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1;
    int dob = 4;
    for(int i = 1; i < n; i++)
    {
        ans += dob;
        dob+=4;
    }
    cout << ans;

    return 0;
}