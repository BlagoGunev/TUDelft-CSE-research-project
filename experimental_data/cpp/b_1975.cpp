#include<bits/stdc++.h>
#define MAXN 1000007
using namespace std;

int t,n,a[MAXN],sc;

void solve(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    sort(a+1,a+n+1);

    int sc=-1;
    for(int i=2;i<=n;i++){
        if(a[i]%a[1]!=0){
            sc=a[i]; break;
        }
    }

    for(int i=1;i<=n;i++){
        if(a[i]%a[1]!=0 and a[i]%sc!=0){
            cout<<"No\n";
            break;
        }else if(i==n){
            cout<<"Yes\n";
        }
    }
}

int main(){

    cin>>t;
    while(t>0){
        solve();
        t--;
    }

    return 0;
}