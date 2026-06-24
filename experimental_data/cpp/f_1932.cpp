#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<iomanip>
#include<stack>
#include<deque>
using namespace std;

#define ll long long 
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define in insert
#define ld long double

long double pi=3.141592653589793238;
const ll mod=1e9+7;
const ll infl=8e18+7;
const int inf=2e9+7;
const int N=1000200;
string yes="YES",no="NO";
int T,n,m,cnt,ans,mn,mx,a[N],r[N],l[N],dp[N];
vector<int>str[N],fin[N];
set<int>sy_mn,sy_mx;
map<int,int>fr_mn,fr_mx;

void clean()
{
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        str[i].clear();
        fin[i].clear();
        dp[i]=0;
    }
    sy_mn.clear();
    fr_mn.clear();
    sy_mx.clear();
    fr_mx.clear();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	T=1;
	cin>>T;//
	while(T--)
	{
	    cin>>n>>m;
	    clean();
	    for(int i=1;i<=m;i++)
	    {
	        cin>>l[i]>>r[i];
	        str[l[i]].pb(i);
	        fin[r[i]].pb(i);
	    }
	    for(int i=1;i<=n;i++)
	    {
	        dp[i]=max(dp[i],dp[i-1]);
	        for(auto x:str[i])
	        {
	            fr_mn[l[x]]++;
	            sy_mn.in(l[x]);
	             fr_mx[r[x]]++;
	            sy_mx.in(-1*r[x]);
	            cnt++;
	        } 
	        if(sy_mn.size()!=0)
	        {
	            mn=*sy_mn.begin();
	            mx=-1*(*sy_mx.begin());
	            a[i]=cnt;
	            dp[mx]=max(dp[mx],dp[i-1]+a[i]);
	        }
	        for(auto x:fin[i])
	        {
	            fr_mn[l[x]]--;
	            if(!fr_mn[l[x]])sy_mn.erase(l[x]);
	             fr_mx[r[x]]--;
	            if(!fr_mx[r[x]])sy_mx.erase(-1*r[x]);
	            cnt--;
	        }
	    }
	    //for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
	    cout<<dp[n]<<endl;
	}	
	return 0;
}