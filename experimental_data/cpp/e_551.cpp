//Archit Rai
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define all(c) (c).begin(),(c).end()
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
#define endl '\n'
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
ll powmod(ll a,ll b)
{
    if(b==0)return 1;
    ll x=powmod(a,b/2);
    ll y=(x*x)%MOD;
    if(b%2)
	return (a*y)%MOD;
    return y%MOD;
}
//Template ends here
ll blockaddval[500010];
ll a[500010];
vector<ll> s[500010];
int main()
{
    ll BLOCK;
    ll n,q;
    sll(n);
    sll(q);
    REP(i,0,n)
	sll(a[i]);
    BLOCK=(ll)(sqrt(n));
    REP(i,0,n)
	s[i/BLOCK].pb(a[i]);
    REP(i,0,(n/BLOCK)+1)
	sort(all(s[i]));
    ll k=BLOCK;
    while(q--)
    {
	ll ans=0;
	ll type;
	scanf("%lld\n",&type);
	if(type==1)
	{
	    ll l,r,x;
	    sll(l);
	    sll(r);
	    l--;
	    r--;
	    sll(x);
	    int p=l;
	    while(l%k!=0 && l<=r)
	    {
		a[l]+=x;
		l++;
	    }
	    for(int i=0;i<sz(s[(p)/BLOCK]);i++)
		s[(p)/BLOCK][i]=a[(p/BLOCK)*BLOCK+i];
	    sort(all(s[(l-1)/BLOCK]));
	    while((l+k-1)<=r)
	    {
		blockaddval[l/BLOCK]+=x;
		l+=k;
	    }
	    p=l;
	    while(l<=r)
	    {
		a[l]+=x;
		l++;
	    }
	    for(int i=0;i<sz(s[(r)/BLOCK]);i++)
		s[(r)/BLOCK][i]=a[(r/BLOCK)*BLOCK + i];
	    sort(all(s[r/BLOCK]));
	}
	else
	{
	    ll y;
	    sll(y);
	    ll mi=-1,ma=-1;
	    ll flag=0;
	    REP(i,0,n)
	    {
		if(s[i].empty())
		    break;
		if(binary_search(all(s[i]),y-blockaddval[i]))
		{
		    for(int j=i*BLOCK;j<i*BLOCK+sz(s[i]);j++)
		    {
			if(a[j]==y-blockaddval[i])
			{
			    mi=(ll)j;
			    break;
			}
		    }
		    break;
		}
	    }
	    for(int i=n/BLOCK+2;i>=0;i--)
	    {
		if(s[i].empty())
		    continue;
		if(binary_search(all(s[i]),y-blockaddval[i]))
		{
		    for(ll j=i*BLOCK+sz(s[i])-1;j>=i*BLOCK;j--)
		    {
			if(a[j]==y-blockaddval[i])
			{
			    ma=(ll)j;
			    break;
			}
		    }
		    break;
		}
	    }/*
	    REP(i,0,n)
	    {
		if(s[i].empty())
		    break;
		ll temp=y-blockaddval[i];
		if(flag==0)
		{
		    ll ind1=(ll)(lower_bound(all(s[i]),mp(temp,0LL))-s[i].begin());
		    if(ind1<sz(s[i]) && s[i][ind1].F==temp)
		    {
			flag++;
			mi=s[i][ind1].S;
		    }
		}
		else if(flag>=1)
		{
		    ll ind2=(ll)(upper_bound(all(s[i]),mp(temp,MOD*1LL))-s[i].begin());
		    ind2--;
		    if(ind2>=0 && s[i][ind2].F==temp)
		    {
			flag++;
			ma=s[i][ind2].S;
		    }
		}
	    }*/
	    if(mi==-1)
		printf("%lld\n",mi);
	    else
		printf("%lld\n",ma-mi);/*
	    if(flag==0)
		printf("-1\n");
	    else if(flag==1)
		printf("0\n");
	    else
		printf("%lld\n",ma-mi);*/
	}
    }
    return 0;
}