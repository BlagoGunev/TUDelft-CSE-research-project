#include <cstdio>

#include <vector>

#include <algorithm>

#include <iostream> 

using namespace std;

typedef long long LL;

const int N=200005;

const int mod=1000000007;

LL f[N],rf[N];

int l[N],r[N],m,n,k;

LL inv(int a,int m){return(a==1?1:inv(m%a,m)*(m-m/a)%m);} 

LL C(int n,int m){if(n<m||m<0)return 0;return f[n]*rf[m]%mod*rf[n-m]%mod;}

void init(){

    f[0]=1LL;for(int i=1;i<=200000;i++)f[i]=(LL)f[i-1]*i%mod;

	rf[200000]=inv(f[200000],mod);

	for(int i=200000;i;i--)rf[i-1]=(LL)rf[i]*i%mod;

}

int main(){

    init();

    scanf("%d%d",&n,&k);

    for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);

    vector<pair<int,int> >V; V.clear();

    for(int i=1;i<=n;i++){

        V.push_back(make_pair(l[i]-1,1));

        V.push_back(make_pair(r[i],-1));

    }sort(V.begin(),V.end());

    long long ans=0;

    int cnt=0,pre;

    for(int i=0;i<V.size();i++){

        ans=(ans+C(cnt,k)*(V[i].first-pre))%mod;

        pre=V[i].first;

        cnt+=V[i].second;

    }printf("%lld\n",ans);

    return 0;

}