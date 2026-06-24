#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        for (int i = 0; i < s.length() / 2; i++)
        {
            mp[s[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (mp[i + 97] > 0)
            {
                cnt++;
            }
        }
        if (cnt > 1)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
    return 0;
}