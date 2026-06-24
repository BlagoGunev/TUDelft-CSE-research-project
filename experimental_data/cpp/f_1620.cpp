#include<bits/stdc++.h>

//#include<iostream>

//#include<string>

//#include<cmath>

//#include<cstdio>

//#include<cctype>

//#include<cstring>

//#include<iomanip>

//#include<cstdlib>

//#include<ctime>

//#include<set>

//#include<map>

//#include<utility>

//#include<queue>

//#include<vector>

//#include<stack>

//#include<sstream>

//#include<algorithm>

using namespace std;

/*=====================================================================*/

#define ll long long

//#define int ll

#define pii pair<int,int>

#define vi vector<int>

#define vii vector<pii>

#define pb push_back

#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define all(s) (s).begin(),(s).end()

#define repd(i,n) for(int i=n-1;i>=0;--i)

#define forr(i,a,b,c) for(int i=a;i<=b;i+=c)

#define forn(i,p,n) for(int i=p;i<=n;++i)

#define ford(i,p,n) for(int i=n;i>=p;--i)

#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)

#define INF 1e9

#define PI acos(-1)

/*=====================================================================*/

string int_to_string(ll n)

{

	string s="";

	while(n)

	{

		ll now=n%10;

		s+=now+'0';

		n/=10;

	}

	reverse(s.begin(),s.end());

	return s;

}

ll string_to_int(string s)

{

	ll n=0;

	rep(i,s.size())

	{

		n*=10;

		n+=s[i]-'0';

	}

	return n;

}

/*======================================================================*/

const int dx[]={-1,0,1,0};

const int dy[]={0,-1,0,1};

const int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};

//think twice,code once

//think once,debug forever

const int MAXN=1e6+10,zero=1e6;

int n;

int a[MAXN];

int dp[MAXN][2][2];

int lst[MAXN][2][2][2];

int Op;

void dfs(int n,int i,int j)

{

	if(n==0)

	{

		return;

	}

	dfs(n-1,lst[n][i][j][0],lst[n][i][j][1]);

	Op=(i==0)?-1:1;

	cout<<Op*a[n]<<" ";

}

void solve()

{

	cin>>n;

	forn(i,1,n)

	{

		cin>>a[i];

	}

	forn(i,0,n)

	{

		rep(j,2)

		{

			rep(k,2)

			{

				dp[i][j][k]=INF;

			}

		}

	}

	dp[1][0][0]=-INF;

	dp[1][1][0]=-INF;

	forn(i,2,n)

	{

		rep(j,2)

		{

			int op=(j==0)?(-1):(1);

			rep(k,2)

			{

				int x,y;

				if((!k))

				{

					x=op*a[i-1],y=dp[i-1][j][k];

				}

				else

				{

					x=dp[i-1][j][k],y=op*a[i-1];

				}

				rep(o,2)

				{

					int nop=(o==0)?(-1):(1);

					if(nop*a[i]>x)

					{

						if(y<dp[i][o][0])

						{

							dp[i][o][0]=y;

							lst[i][o][0][0]=j;

							lst[i][o][0][1]=k;

						}

					}

					else

					{

						if(nop*a[i]>y)

						{

							if(x<dp[i][o][1])

							{

								dp[i][o][1]=x;

								lst[i][o][1][0]=j;

								lst[i][o][1][1]=k;

							}

						}

					}

				}

			}

		}

	}

	rep(i,2)

	{

		rep(j,2)

		{

			if(dp[n][i][j]!=INF)

			{

				cout<<"YES\n";

				dfs(n,i,j);

				cout<<"\n";

				return;

			}	

		}

	}

	cout<<"NO\n";

}

/*======================================================================*/

signed main()

{

    cin.tie(0);

    cout.tie(0);

	std::ios::sync_with_stdio(false);

//#define Hank2007

#ifdef Hank2007

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

#endif

  	/*====================================================================*/

  	int TEST_CASE=1;

	cin>>TEST_CASE;

  	while(TEST_CASE--)

  	{

  		solve();

  	}

  	return 0;

}