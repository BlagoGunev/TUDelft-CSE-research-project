#include<bits/stdc++.h>
#define f first
#define s second 
#define ll long long
#define u unsigned
#define pb push_back
#define mp make_pair
#define FX fflush(stdin);cout<<fixed,cout.precision(18);
#define iOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ones __builtin_popcount() 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define dl "\n";
#define all(x) x.begin(), x.end()
const long double eps=0.00000001;
const long long MOD=1e9+7;
const double PI=3.141592653589793238463;
using namespace std;
ll ans;
bool check(string s)
{
	 string t=s;
	 reverse(all(t));
	 if(t==s)
	 	return true;
	 return false;
}
int dx[]={-1,-1,1,1};
int dy[]={1,-1,-1,1};
main()
{
	FX iOS
	int i,j,n,m;
	cin>>n;
	for(i=0;i<n;++i)
	{
		string s,t;
		cin>>m>>s;
		if(check(s))
		{
			cout<<"YES\n";
			continue;
		}
		bool can=true;
		for(int q=0,j=m-1;q<m/2;++q,--j)
		{
			int a=s[q]-'a';
			int b=s[j]-'a';
			bool ok=false;
			for(int k=0;k<4;++k)
			{
				if(a+dx[k]==b+dy[k])
				{
					ok=true;
					break;
				}
			}
			if(!ok)
			{
				can=false;
				break;
			}
		}
		if(!can)
			cout<<"NO\n";
		else 
			cout<<"YES\n";
	}
}