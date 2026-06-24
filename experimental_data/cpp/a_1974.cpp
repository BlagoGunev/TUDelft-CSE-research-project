#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

using LL = long long;
using LD = long double;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;

const LL M = 1e9 + 7;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        int ans = b + 1 >> 1;
        a -= ans * 7;
        if(b&1) a -= 4;
        if(a>0){
            ans += (a + 14) / 15;
        }
        cout<<ans<<endl;
        if(0) yes: cout<<"YES"<<endl;
        if(0) no:  cout<<"NO"<<endl;
    }
}
/*

*/