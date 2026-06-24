#include <bits/stdc++.h>

#define mod 998244353

#define int long long

using namespace std;



int ksm(int x,int y)

{

	int rtn=1;

	while(y)

	{

		if(y&1) rtn=rtn*x%mod;

		x=x*x%mod,y>>=1;

	}

	return rtn;

}

int inv(int x)

{

	return ksm(x,mod-2);

}

int l[55],r[55];

//int dp[55][100005];

int X[55][55];

const int inf=mod-1;

struct poly

{

	vector<int> v;

	void qzh()

	{

		vector<int> rtn;

		rtn.resize(v.size()+1);

		for(int i=0;i<v.size();i++)

		{

			for(int j=0;j<=i+1;j++)

				rtn[j]=(rtn[j]+v[i]*X[i][j])%mod;

		}

		swap(v,rtn);

	}

	int cal(int x)

	{

		int rtn=0;

		for(int i=(int)v.size()-1;i>=0;i--)

			rtn=(rtn*x+v[i])%mod;

		return rtn;

	}

};

struct qujian

{

	int l,r;

	poly f;

};

vector<qujian> dp[55];

void print(vector<qujian> x)

{

	for(auto t:x)

	{

		cout << t.l << "," << t.r << ":\n";

		int c=0;

		for(auto x:t.f.v) cout << x << "x^" << (c++) << "+";

		cout << "\n";

	}

	cout << "\n\n";

}

signed main()

{

	ios::sync_with_stdio(false);

	cin.tie(0);

	int n;

	cin >> n;

	int tot=1;

	for(int i=1;i<=n;i++)

	{

		cin >> l[i] >> r[i];

		++l[i],++r[i];

		tot=(tot*(r[i]-l[i]+1))%mod;

	}

	l[n+1]=0,r[n+1]=inf;

	reverse(l+1,l+n+1);

	reverse(r+1,r+n+1);

	for(int k=0;k<=53;k++)

	{

		int x[60]={},y[60]={};

		for(int i=0;i<=k+2;i++)

			x[i]=i+1,y[i]=((i?y[i-1]:0)+ksm(x[i],k))%mod;

		int b[60][60]={};

		for(int i=0;i<=k+2;i++)

		{

			for(int j=0;j<=k+2;j++) b[i][j]=ksm(x[i],j);

			b[i][k+3]=y[i];

		}

		for(int x=0;x<=k+2;x++)

		{

			int X=inv(b[x][x]);

			for(int y=0;y<=k+3;y++) b[x][y]=(b[x][y]*X)%mod;

			for(int y=0;y<=k+2;y++)

			{

				if(x==y) continue;

				int t=b[y][x];

				for(int z=0;z<=k+3;z++) b[y][z]=(b[y][z]-b[x][z]*t)%mod;

			}

		}

		for(int x=0;x<=k+2;x++) X[k][x]=(b[x][k+3]%mod+mod)%mod;

	}

/*	dp[0][0]=1;

	for(int i=1;i<=n+1;i++)

	{

		for(int j=0;j<=r[i];j++) dp[i][j]=dp[i-1][j];

		for(int j=0;j<=r[i];j++) dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;

		for(int j=0;j<l[i];j++) dp[i][j]=0;

	}*/

	dp[0].push_back({0,0,{{1}}});

	dp[0].push_back({1,inf,{{0}}});

	for(int i=1;i<=n+1;i++)

	{

		dp[i]=dp[i-1];

		for(int j=0;j<dp[i].size();j++)

		{

			dp[i][j].f.qzh();

			int lst=0;

			if(j) lst=dp[i][j-1].f.cal(dp[i][j].l-1);

			int nw=dp[i][j].f.cal(dp[i][j].l-1);

			dp[i][j].f.v[0]+=lst-nw;

		}

		while(dp[i].back().l>r[i]) dp[i].pop_back();

		dp[i].back().r=r[i];

		if(r[i]!=inf) dp[i].push_back({r[i]+1,inf,{{0}}});

		while(dp[i][0].r<l[i]) dp[i].erase(dp[i].begin());

		dp[i][0].l=l[i];

		if(l[i]>0) dp[i].insert(dp[i].begin(),{0,l[i]-1,{{0}}});

	}

/*	print(dp[0]);

	print(dp[1]);

	print(dp[2]);

	print(dp[3]);

	print(dp[4]);*/

//	int ans=0;

//	cout << dp[n+1][inf]*inv(tot)%mod;

	cout << (dp[n+1].back().f.cal(inf)*inv(tot)%mod+mod)%mod;

	return 0;

}