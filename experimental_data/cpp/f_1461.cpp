#include <iostream>

#include <vector>

using namespace std;

int a[100005],QWQ[5];

char ans[100005];

int dp[100005],qzh[100005],lst[100005];

vector <pair<int,int> > v;

inline void solve(int l,int r)

{

	//cout << l << "***" << r << '\n';

	if(l>r) return ;

	if(a[l]==1)

	{

		ans[l]='+';

		solve(l+1,r);

		return ;

	}

	if(a[r]==1)

	{

		ans[r-1]='+';

		solve(l,r-1);

		return ;

	}

	int p=1;

	for(int i=l;i<=r;i++)

	{

		p*=a[i];

		if(p>1e7)

		{

			for(int j=l;j<r;j++)

				ans[j]='*';

			return ;

		}

	}

	qzh[l-1]=1;

	qzh[l]=a[l];

	for(int i=l+1;i<=r;i++)

		qzh[i]=qzh[i-1]*a[i];

	v.clear();

	int cnt=0;

	for(int i=l;i<=r;i++)

	{

		if(a[i]==1) ++cnt;

		else

		{

			v.push_back({i-cnt-1,cnt});

			cnt=0;

			for(auto t:v)

			{

				dp[i]=max(dp[i],t.second+dp[t.first]+qzh[i]/qzh[t.first]);

				if(dp[i]==t.second+dp[t.first]+qzh[i]/qzh[t.first])

					lst[i]=t.first;

			}

		}

	}

	//cout << dp[r] << "\n";

	int now=r;

	while(1)

	{

		int t=lst[now],flag=0;

	//	cout << now << " " << t << "\n";

		if(t<l)

		{

			for(int i=t+1;i<now;i++) ans[i]='*';

			break;

		}

		for(int i=t;i<now;i++)

		{

			if(flag) ans[i]='*';

			else ans[i]='+';

			if(a[i+1]>1) flag=1;

		}

		now=t;

	}

}

int main(int argc, char** argv) {

	int n;

	cin >> n;

	for(int i=1;i<=n;i++)

		cin >> a[i];

	string s;

	cin >> s;

	for(auto t:s)

	{

		if(t=='+') QWQ[0]=1;

		if(t=='-') QWQ[1]=1;

		if(t=='*') QWQ[2]=1; 

	}

	if(QWQ[0]==1) QWQ[1]=0;

	if(!QWQ[0]&&!QWQ[1])

	{

		cout << a[1];

		for(int i=2;i<=n;i++)

			cout << "*" << a[i];

		return 0;

	}

	if(!QWQ[0]&&!QWQ[2])

	{

		cout << a[1];

		for(int i=2;i<=n;i++)

			cout << "-" << a[i];

		return 0;

	}

	if(!QWQ[1]&&!QWQ[2])

	{

		cout << a[1];

		for(int i=2;i<=n;i++)

			cout << "+" << a[i];

		return 0;

	}

	if(QWQ[1]&&QWQ[2])

	{

		int flag=0;

		if(!a[1])

		{

			cout << a[1];

			for(int i=2;i<=n;i++)

				cout << "*" << a[i];

			return 0;

		}

		cout << a[1];

		for(int i=2;i<=n;i++)

		{

			if(flag||a[i]) cout << "*" << a[i];

			else

			{

				flag=1;

				cout << "-" << a[i];

			}

		}

		return 0;

	}

	int lst=1;

	for(int i=1;i<=n;i++)

	{

		if(!a[i])

		{

			ans[i-1]=ans[i]='+';

			solve(lst,i-1),lst=i+1;

		}

	}

	solve(lst,n);

	ans[n]=' ';

	for(int i=1;i<=n;i++)

	{

		cout << a[i];

		if(i!=n) cout << ans[i];

	}

	return 0;

}