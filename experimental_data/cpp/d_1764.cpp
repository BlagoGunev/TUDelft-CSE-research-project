#include <bits/stdc++.h>

using namespace std;

#define int long long

#define pb push_back

#define ff first

#define ss second

#define pii pair<int,int>

#define vi vector<int>

#define vii vector<pair<int,int>>

int fact[5001],factinv[5001];

long long binexp(long long a,long long b,long long MOD){

    if(b==1)return a%MOD;

    if(b==0)return 1;

    if(b%2==0){

        long long k=binexp(a,b/2,MOD);

        return (k*k)%MOD;

    }else{

        long long k=binexp(a,b/2,MOD);

        return ((k*k)%MOD*a)%MOD;

    }

}

long long bincoeff(long long a,long long b, long long MOD){

    return ((fact[a]*factinv[b])%MOD*factinv[a-b])%MOD;

}

signed main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    fact[0]=1;

    int n,p;

    cin>>n>>p;

    for(int i=1;i<=5000;i++){

        fact[i]=i*fact[i-1];

        fact[i]%=p;

        factinv[i]=binexp(fact[i],p-2,p);

    }

    factinv[0]=factinv[1];

    int ans=0;

    for(int i=1;i<=(n+1)/2;i++){

        int l=1+(n+1)/2;

        int r=i+n/2;

        if(l>r)continue;

        int len=r-l+1;

        int len2=max(0ll,i-2);

        for(int j=0;j<=len2;j++){

            int ans1=len*bincoeff(len2,j,p);

            ans1%=p;

            ans1*=fact[n-1-i+j];

            ans1%=p;

            ans+=ans1;

            ans%=p;

        }

    }

    ans*=n;

    ans%=p;

    cout<<ans<<'\n';

    return 0;

}