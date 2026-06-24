#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(v)       ((v).begin()), ((v).end())

#define rall(v)      ((v).rbegin()), ((v).rend())

#define endl "\n"

void Abo_Ghanima() {

    ios::sync_with_stdio(NULL);

    cin.tie(NULL), cout.tie(NULL);

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

}

void Solve(){

    ll n,m;cin>>n>>m;



    if(m > 1) cout << n * (m-1) << '\n';

    else cout << n - 1 << '\n';

}

signed main() {

    Abo_Ghanima();

    int T=1; //cin>>T;

    while (T--){Solve();}

}