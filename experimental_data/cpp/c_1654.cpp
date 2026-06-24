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



void solve()

{

	priority_queue<int>p,q;

	cin>>n;

	int sum=0;

	for(int i=1;i<=n;i++)

	{

		int x;

		cin>>x;

		p.push(x);

		sum+=x;

	}

	q.push(sum);

	while(q.size())

	{

		while(q.size()&&p.size())

		{

			if(q.top()==p.top())q.pop(),p.pop();

			else break;

		}

		if(q.empty()||p.empty())break;

		auto t=q.top();

		q.pop();

		q.push(t/2);

		q.push((t+1)/2);

	    if(q.size()>p.size())break;	

	}

	if(p.size()==0)cout<<"YES"<<endl;

	else cout<<"NO"<<endl;

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