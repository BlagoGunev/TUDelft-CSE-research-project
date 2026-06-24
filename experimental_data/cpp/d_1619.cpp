#include <bits/stdc++.h>
typedef long long int ll;
#define INF 1e9 + 7
#define N (ll)2e5 + 5
using namespace std;

void solve(){
    ll n, m;
    string str;
    getline(cin, str);
    cin >> m >>n;
    ll p[m][n], maxx[n], place[n], minn1=1e9, max2=0;
    bool vv[m];
    memset(vv, 0, m);
    for(int j=0; j<n; j++){maxx[j]=0;}
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> p[i][j];
            maxx[j]=max(maxx[j], p[i][j]);
        }
    }
    for(int j=0; j<n; j++){minn1=min(minn1, maxx[j]);}
    bool bb=0;
    ll temp=0;
    for(int i=0; i<m; i++){
        temp=0;
        for(int j=0; j<n; j++){
            if(p[i][j]==maxx[j]){
                vv[i]=1;
                temp++;
                if(temp>1)bb=1;
            }
        }
    }
    if(bb==1){
        cout<<minn1<<"\n";
        return;
    }
    for(int i=0; i<m; i++){
        temp=0;
        ll max3=0, max4=0;
        for(int j=0; j<n; j++){
            if(p[i][j]!=maxx[j]){
                if(vv[i]){max2=max(max2, p[i][j]);}
                else{
                    if(max3<p[i][j] && max3<max4)max3=p[i][j];
                    else if(max4<p[i][j])max4=p[i][j];
                }
                max2=max(max2, (min(max4, max3)));
            }
        }
    }
    cout<<min(max2, minn1)<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while (T--){
        solve();
    }
}