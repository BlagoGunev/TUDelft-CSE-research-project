#ifndef _CRT_SECURE_NO_DEPRECATE

#define _CRT_SECURE_NO_DEPRECATE



#include<bits/stdc++.h>

using namespace std;



#define rep(i,n) for(int i=0;i<int(n);i++)

#define repi(i,a,n) for(int i=int(a);i<int(n);i++)

#define all(x) x.begin(), x.end()

#define fill(x,y) memset(x,y,sizeof x)

#define ll long long 

#define uint unsigned int

#define mp(x,y) make_pair(x,y)

#define eps 2.7182813866740473416770028812239

#define pi acos(-1.)

#define OO 100000

#define pii pair<int,int>

#define TPL pair<ll,pair<int,int> >

#define MTPL(x,y,z) p(x,p(y,z))

#define MAX 105

#define INF 1000000000



ll gcd(ll a, ll b){ return !b ? a : gcd(b, a%b); }

ll lcm(ll a, ll b){ return a*(b / gcd(a, b)); }



vector<vector<int> > ar;



//0 white 1 grey 2 black

int visited[3005];

int p[3005];

int n;

//- int



vector<int>	dist, vis;

void bfs(int node){

	queue<int> Q;

	dist.assign(n + 1, 0), vis.assign(n + 1, 0);

	Q.push(node);

	vis[node] = 1;

	dist[node] = 0;

	while (!Q.empty()){

		int x = Q.front();

		Q.pop();

		for (auto nx : ar[x]){

			if (!vis[nx]){

				Q.push(nx);

				dist[nx] = dist[x] + 1;

				if (visited[nx] == 2)dist[nx] = 0;

				vis[nx] = 1;

			}

		}

	}

}



void build(int node)

{

	if (visited[node]==1)

	{

		visited[node] = 2;

		while (visited[p[node]] != 2)

			visited[node] = 2, node = p[node];

		visited[node] = 2;

		

		bfs(node);

		for (int i = 1; i <= n;i++)

		if (visited[i] == 2)

			cout << 0 << " ";

		else 

			cout << dist[i] << " ";

	

		exit(0);

	}



	if(!visited[node])

		visited[node] = 1;

	

	for (auto i : ar[node])

	{

		if (p[node]!=i)

		{

			p[i] = node;

			build(i);

		}

	}



}







int main()

{



#ifndef ONLINE_JUDGE

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

#endif

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	

	cin >> n;

	ar.assign(n + 1, vector<int>());

	for (int i = 0; i < n;i++)

	{

		int a, b;

		cin >> a >> b;

		ar[a].push_back(b);

		ar[b].push_back(a);

	}

	build(1);



	return 0;

}





#endif