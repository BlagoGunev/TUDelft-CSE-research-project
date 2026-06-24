#include <bits/stdc++.h>
#define endl "\n"
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAX = 5e5 + 5;

int main()
{
    IOS;
    int test = 1;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long ans = 0;
        vector<long long> memo(n + 10);
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(s[i] == '1')
            {
                memo[i] = memo[i + 3] + n - i;
            }
            else
            {
                memo[i] = memo[i + 1];
            }
            ans += memo[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}