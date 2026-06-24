#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=4000;

ll a[N],d[N],p[N];

ll n,k;

int main(){

    ios::sync_with_stdio(0);

    cin.tie(0),cout.tie(0);

    cin>>n>>k;

    for(int i=1;i<=n;i++) {

        cin>>a[i];

        d[i]=d[i-1]+(a[i]==0);

        p[i]=p[i-1]+a[i];

    }

    if(abs(p[n])>d[n]*k){

        puts("-1");

        return 0;

    }

    ll ma=-1;

    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){

            ll sum=p[j]-p[i-1],cnt=d[j]-d[i-1];

            ll lsum=p[n]-sum,lcnt=d[n]-cnt;

            ma=max(ma,min(abs(sum+cnt*k),abs(lsum-lcnt*k)));

            ma=max(ma,min(abs(sum-cnt*k),abs(lsum+lcnt*k)));

        }

    }

    cout<<ma+1<<endl;



}