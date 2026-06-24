#include<bits/stdc++.h>
#include<string>
using namespace std;
int min0 = INT_MAX , max0 = INT_MIN, tst;
#define Rezvi         cin>>tst;while(tst--)
#define ll            long long int
void solve();
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    Rezvi
    {
        solve();
        cout << endl;
    }
    return 0;
}

void solve()
{
    ll ans = 0;
    ll n;
    cin >> n;
    string str[n];
    for (int i = 0; i < n - 2; i++)
    {
        cin >> str[i];
    }
    cout << str[0][0];
    for (int i = 0; i < (n - 3); i++)
    {
        int j = i + 1;
        if (str[i][1] == str[j][0])
            cout << str[i][1];
        else
        {
            cout << str[i][1];
            cout << str[j][0];
            ans = 1;
        }
    }
    cout << str[n - 3][1];
    if (ans == 0)
        cout << 'a';
    return;
}