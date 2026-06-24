#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d",&a)
#define MAX 100005
#define f first
#define s second
#define mp(a,b) make_pair(a,b)

long long inv[MAX],S[4*MAX];
vector<pair<int,int> > all;
int n,tot[4*MAX];

void modify(int pos,int val,int id=1,int l=0,int r=n)
{
    if(r-l<2){
        S[id]=val;
        tot[id]=1;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<mid)modify(pos,val,2*id,l,mid);
    else modify(pos,val,2*id+1,mid,r);
    S[id]=S[2*id]+S[2*id+1];
    tot[id]=tot[2*id]+tot[2*id+1];
}

long long sum(int b,int e,int id=1,int l=0,int r=n)
{
    if(b>=r || e<=l)return 0;
    if(l>=b && r<=e)return S[id];
    int mid=(l+r)>>1;
    return sum(b,e,2*id,l,mid)+sum(b,e,2*id+1,mid,r);
}

int nowtot(int b,int e,int id=1,int l=0,int r=n)
{
    if(b>=r || e<=l)return 0;
    if(l>=b && r<=e)return tot[id];
    int mid=(l+r)>>1;
    return nowtot(b,e,2*id,l,mid)+nowtot(b,e,2*id+1,mid,r);
}

int main()
{
    //freopen("input.txt","r",stdin);
    int i,j;
    inv[0]=0;
    for(i=1;i<MAX;i++)inv[i]=inv[i-1]+i;
    double res=0;
    si(n);
    long long ttt=n;
    ttt*=(n+1);ttt/=2;
    for(i=0;i<n;i++){
        si(j);
        all.push_back(mp(j,i));
    }
    for(i=1;i<n;i++){
        double tmp;
        tmp=(double)(n-i)*(double)inv[i];
        tmp/=ttt;
        res+=tmp;
    }
    res*=.5;
    sort(all.begin(),all.end());
    for(i=n-1;i>=0;i--){
        double p=n-all[i].s;
        p*=sum(0,all[i].s);
        p/=ttt;
        p=nowtot(0,all[i].s)-p;
        res+=p;
        modify(all[i].s,all[i].s+1);
    }
    cout<<fixed<<setprecision(15)<<res<<endl;
    return 0;
}