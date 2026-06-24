#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
typedef int64_t ll;
//using mint=modint998244353;

typedef long double ld;
const ll MOD=1000000007;
const ll MODA=998244353;
ll vx[4]={0,1,0,-1};
ll vy[4]={1,0,-1,0};
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
long long gcd(long long a,long long b){
    a=abs(a);
    b=abs(b);
    ll gcdmax=max(a,b);
    ll gcdmin=min(a,b);
    if(gcdmin==0)return gcdmax;
    while(true){
        if(gcdmax%gcdmin==0)break;
        else gcdmax%=gcdmin;
        swap(gcdmin,gcdmax);
    }
    return gcdmin;
}
ll pow(ll N,ll P,ll M){
    if(P==0)return 1;
    else if(P%2==0){
        ll t=pow(N,P/2,M);
        return t*t%M;
    }
    else return N*pow(N,P-1,M)%M;
}
ll pow(ll N,ll P){
    if(P==0)return 1;
    else if(P%2==0){
        ll t=pow(N,P/2);
        return t*t;
    }
    else return N*pow(N,P-1);
}

vector<ll> fac;
vector<ll> finv;
vector<ll> inv;
void COMinit(ll N,ll P){
    rep(i,N+1){
        if(i==0){
            fac.push_back(1);
            finv.push_back(1);
            inv.push_back(1);
        }
        else if(i==1){
            fac.push_back(1);
            finv.push_back(1);
            inv.push_back(1);
        }
        else{
            fac.push_back(fac.at(i-1)*i%P);
            inv.push_back(P-inv.at(P%i)*(P/i)%P);
            finv.push_back(finv.at(i-1)*inv.at(i)%P);
        }
    }
}

ll COM(ll n,ll k,ll P){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac.at(n)*(finv.at(k)*finv.at(n-k)%P)%P;
}

pair<ll,ll> dist(ll x,ll y){
    ll retx=0;
    ll rety=0;
    while(y!=x){
        if(y<x)x/=2,retx++;
        else y/=2,rety++;
    }
    return {retx,rety};
}

int main(){
    ll T;
    cin>>T;
    vector<vector<ll>> Ans(T);
    rep(t,T){
        ll n;
        cin>>n;
        vector<ll> a(n);
        rep(i,n)cin>>a[i];
        vector<pair<ll,ll>> P;
        rep(i,n){
            if(a[i]!=-1)P.push_back({a[i],i});
        }
        ll sz=P.size();
        vector<ll> b(n,-1);
        if(sz==0){
            rep(i,n){
                b[i]=1+(i%2==0);
            }
            Ans[t]=b;
            continue;
        }
        rep(i,sz-1){
            pair<ll,ll> dd=dist(P[i].first,P[i+1].first);
            ll d=dd.first+dd.second;
            ll id=P[i+1].second-P[i].second;
            if(id<d||(id%2!=d%2)){
                b.assign(1,-1);
                break;
            }
            ll dx=dd.first;
            ll dy=dd.second;
            ll ix=P[i].second;
            ll iy=P[i+1].second;
            b[ix]=P[i].first;
            b[iy]=P[i+1].first;
            rep(j,dx)b[ix+1+j]=b[ix+j]/2;
            rep(j,dy)b[iy-j-1]=b[iy-j]/2;
            for(ll j=ix+dx+1;j<iy-dy;j++){
                if(j==ix+dx+1)b[j]=b[j-1]*2;
                else b[j]=b[j-2];
            }
        }
        if(b.size()==1){
            Ans[t]=b;
            continue;
        }
        ll i0=P[0].second;
        b[i0]=P[0].first;
        rep(i,i0){
            if(i==0)b[i0-1]=b[i0]*2;
            else b[i0-1-i]=b[i0+1-i];
        }
        ll in=P[sz-1].second;
        b[in]=P[sz-1].first;
        for(ll i=in+1;i<n;i++){
            if(i==in+1)b[i]=b[i-1]*2;
            else b[i]=b[i-2];
        }
        Ans[t]=b;
    }
    for(vector<ll> b:Ans){
        for(ll x:b)cout<<x<<" ";
        cout<<endl;
    }
}