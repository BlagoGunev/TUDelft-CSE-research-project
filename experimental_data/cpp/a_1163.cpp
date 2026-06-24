#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    n-=m;

    if(n==0)
    {
        cout << "0" << endl;
        return 0;
    }

    if(m==0)
    {
        cout << "1" << endl;
        return 0;
    }

    cout << min(n, m) << endl;    


    return 0;
}