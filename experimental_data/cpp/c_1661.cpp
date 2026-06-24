/*

���� 

*/

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

int a[N];

int n, m,maxx; 

//int p[N], s[N];

//int sx, sy, ex, ey;

//queue<int> q;

//bool st[N];

//map<int, int> mp;

//int h[N], ne[N], w[N], e[N], idx, dist[N];

int odd_cnt,even_cnt;

bool check(int day)

{

	int has_odd=ceil(day*1.0/2);

	int has_even=day/2;

	if(has_odd<odd_cnt)return false;

	int remain1=has_odd-odd_cnt;

	if(has_even*2+remain1/2*2>=even_cnt)return true;

	return false;

}

void solve()

{

	cin>>n;

	maxx=0;

	int dat_tot=0;

	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]),dat_tot+=a[i];

    odd_cnt=even_cnt=0;

    dat_tot=dat_tot/3*2+dat_tot%3;

	for(int i=1;i<=n;i++)

	{

		if(a[i]<maxx)

		{

			if((maxx-a[i])&1)odd_cnt++;

			even_cnt+=(maxx-a[i]-(maxx-a[i]&1));

		}

		

	}

	//cout<<odd_cnt<<' '<<even_cnt<<endl;

	int l=0,r=1e16;

	while(l<r)

	{

		int mid=l+r>>1;

		if(check(mid))r=mid;

		else l=mid+1;

	}

	int ans=l;

	odd_cnt=even_cnt=0;

	maxx++;

	for(int i=1;i<=n;i++)

	{

		if(a[i]<maxx)

		{

			if((maxx-a[i])&1)odd_cnt++;

			even_cnt+=maxx-a[i]-((maxx-a[i])&1);

		}

		

	}

	//cout<<odd_cnt<<' '<<even_cnt<<endl;

	l=0,r=1e16;

	while(l<r)

	{

		int mid=l+r>>1;

		if(check(mid))r=mid;

		else l=mid+1;

	}

	cout<<min(ans,l)<<endl;

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