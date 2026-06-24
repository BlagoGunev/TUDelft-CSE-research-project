#include <bits/stdc++.h>

#define rep(i, n)    for(ll i = 0; i < (n); ++i)

#define ll long long

#define INF INT_MAX
using namespace std;

int main()
{

	int t;
	cin>>t;int n,a,b,c;
	string s;
	while(t--)
	{
		cin>>n>>a>>b>>c;
		cin>>s;
		int r=0,p=0,sc=0;
		rep(i,n)
		{
			if(s[i]=='R') r++;
			else if(s[i]=='P') p++;
			else sc++;
		}
		int u=a,v=b,w=c;
		int ans=min(a,sc)+min(b,r)+min(c,p);
		char st[105];int cnt=0;
		if(ans>=ceil((float)n/2))
		{
			cout<< "YES\n";
			rep(i,n)
			{ //cout<<"\n"<< w<<"\n";
				if(s[i]=='R'&&v>0)
				{
					v--;
					st[cnt++]='P';
				}
				else if(s[i]=='P'&&w>0)
				{
					w--;
					st[cnt++]='S';
				}
				else if(s[i]=='S'&&u>0)
				{
					u--;
					st[cnt++]='R';
				}
				else
					st[cnt++]='0';
			}
			rep(i,n)
			{
				if(st[i]=='0')
				{
					if(u>0) {u--;cout<< "R";}
					else if(v>0) {v--;cout<< "P";}
					else {w--;cout<< "S";}
				}
				else cout<< st[i];
			}
			cout<< endl;
		}
		else
			cout<< "NO\n";
	}
}