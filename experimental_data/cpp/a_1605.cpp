#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define pq priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
#define graph1 vector<vector<pair<ll,ll>>>
#define graph vector<vector<ll>>
#define pq1 priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define loop(i,a,b) for (ll i = a; i < b; i++)
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
     ll a,b,c;
     cin >> a >> b >> c;
     if((a+b+c)%3 ==0 )
     {
         cout << 0 << endl;
     } else
     {
         cout << 1 << endl;
     }
    }
}