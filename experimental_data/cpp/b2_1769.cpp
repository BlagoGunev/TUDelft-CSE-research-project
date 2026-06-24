#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long loint;
typedef unsigned long long unlo;
void solve(){
    int n;cin>>n;
    vector<loint> a(n+1),pre(n+1);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    set<int> aws;
    for(int j = 1;j<=n;j++){
        for(int i = 0;i<=100;i++){
            if(aws.count(i))continue;
            loint lo = 0,hi = a[j],x = -1;
            while(lo<=hi){
                loint mid = lo+(hi-lo)/2;
                loint res1 = 100*mid/a[j];
                loint res2 = 100*(pre[j-1]+mid)/pre[n];
                if(res1<i||res2<i)lo = mid+1;
                else if(res1>i||res2>i)hi = mid-1;
                else{
                    x = mid;
                    break;
                }
            }
            if(x!=-1)aws.insert(i);
        }
    }
    for(auto res:aws){
        cout<<res<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("", "r", stdin);
//    freopen("", "w", stdout);
    solve();
    return 0;
}