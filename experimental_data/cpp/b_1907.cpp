/// tree bends in youth
/// 05  .12.2023
/// success is doing same thing in every single day!!!
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
const ll N =2e5+ 12;
const ll NN =2e6 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll LG = 18;
void solve(){
    string s;
    cin >> s;
    vector <pair<int,char> > z,x;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'B'){
            if(z.size())z.pop_back();
        }
        else if(s[i] == 'b'){
            if(x.size())x.pop_back();
        }
        else if(s[i] >= 'a' && s[i] <= 'z'){
            x.push_back({i,s[i]});
        }
        else{
            z.push_back({i,s[i]});
        }
    }
    int j = 0,i = 0;
    while(j < z.size() || i < x.size()){
        if(j == z.size()){
            cout << x[i].S;
            i++;
        }
        else if(i == x.size()){
            cout << z[j].S;
            j++;
        }
        else{
            if(z[j].F < x[i].F){
                cout << z[j].S;
                j++;
            }
            else{
                cout << x[i].S;
                i++;
            }
        }
    }
    cout << '\n';
}
main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("haybales.in","r",stdin);
//    freopen("haybales.out","w",stdout);
    ll abd= 1;
    cin >> abd;
    for(int i = 1;i <= abd;i++){
//        cout << "Case " << i << ":\n";
        solve();
    }
}