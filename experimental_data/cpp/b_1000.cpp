#include<bits/stdc++.h>
 
using namespace std;
 
#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<n;i++)
#define pr pair<int,int>
#define pll pair<long long,long long>
#define ll long long
#define ull unsigned long long
#define v vector
#define all(a) a.begin(),a.end()
#define ina(a,i,n) for(i=0;i<n;i++)cin>>a[i]
#define mmst(a) memset(a,0,sizeof(a))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

int a[100050];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif
    ios_base::sync_with_stdio(false);
    int i,j,k,n,m,t,y,temp;

    cin>>n>>m;
    for(i=1;i<=n;i++) {
        cin>>a[i];
    }
    a[0]=0;
    a[n+1]=m;

    ll on=0;
    ll off=0;
    int pre=0;
    for(i=1;i<=n+1;i++) {
        if(pre==0) {
            on+=a[i]-a[i-1];
            pre=1;
        }
        else {
            off += a[i]-a[i-1];
            pre=0;
        }
    }
    pre=0;
    ll mon=on;
    ll lon=0;
    ll loff=0;
    ll roff,ron;
    for(i=1;i<=n+1;i++) {
        
        roff = off - loff;
        if(pre==0) {
            if(a[i]-a[i-1]==1) {
                lon += 1;
                pre=1;
                continue;
            }
            ll t = lon + roff + (a[i]- a[i-1] -1);
            lon += a[i] - a[i-1];
            mon = max(mon,t);
            pre=1;
        }
        else {
            if(a[i]-a[i-1]==1){
                loff+=1;
                pre=0;
                continue;
            }
            roff -= (a[i]-a[i-1]);
            ll t = lon + roff + (a[i]- a[i-1] -1);
            loff += a[i] - a[i-1];
            mon = max(mon,t);
            pre=0;
        }
    }
    cout<<mon;
    return 0;
}