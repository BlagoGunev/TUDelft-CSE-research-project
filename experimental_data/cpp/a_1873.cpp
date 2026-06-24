#include <bits/stdc++.h>
using namespace std;
typedef long long i32;
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        if (s[0] == 'a' || (s[0] == 'b' && s[1] == 'a') || (s[0] == 'c' && s[1] == 'b'))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }   

    return 0;
}