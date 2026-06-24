#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define maxx LLONG_MAX
#define mod 1000000007
#define PI 3.141592653589793238462643383279
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define trace(x) cerr<<#x<<" : "<<x<<endl;

void solve()
{
    int n;
    vector<char> data, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        data.push_back(x);
    }
    temp = data;
    sort(all(data));
    if(data == temp)
    {
        cy;
    }
    else
    {
        cn;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}