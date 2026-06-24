#include <set>

#include <map>

#include <cmath>

#include <queue>

#include <cstdio>

#include <vector>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <unordered_map>



#define x first

#define y second

#define endl '\n'

#define int long long



using namespace std;



typedef long long ll;

typedef pair<int, int> PII;



const int N = 1e6 + 10, INF = 1e18; 



int n, m; 

//int p[N], s[N];

//int sx, sy, ex, ey;

//queue<int> q;

//bool st[N];

//map<int, int> mp;

//int h[N], ne[N], w[N], e[N], idx, dist[N];

int a[N],b[N],cnt[N];

void solve()

{

	cin>>n;

	for(int i=1;i<=n;i++)cin>>a[i],cnt[i]=0;

	for(int i=1;i<=n;i++)cin>>b[i];

	for(int j=n,i=n;j>=1&&i>=1;)

	{

		while(b[j]==b[j-1])

		{

			cnt[b[j]]++;

			j--;

		}

		if(b[j]==a[i])

		i--,j--;

		else if(cnt[a[i]])cnt[a[i]]--,i--;

		else

		{

			cout<<"NO"<<endl;

			return ;

		}

	}

	cout<<"YES"<<endl;

	return;

}



signed main()

{

	ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

	int t = 1;

	cin >> t;

	

	while(t -- ) solve();

	

	return 0;

}