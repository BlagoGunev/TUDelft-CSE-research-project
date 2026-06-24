#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n, m,q=1, k=1, p,l, r,LAST=200001, mi = 0;
    cin >> q;
    string S="MEOW";
    while(q--){
        cin>>n;
        vll a(n);
        multiset<ll> se;
        p=0;
        for(int i=0; i<n; ++i) {
            cin >> a[i];
            if(a[i]>0)
                se.insert(-a[i]);
            else if(!se.empty()){
                p-=*se.begin();
                se.erase(se.begin());
            }
        }
        cout<<p<<'\n';
    }


}