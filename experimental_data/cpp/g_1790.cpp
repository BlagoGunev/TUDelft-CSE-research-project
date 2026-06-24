#include <bits/stdc++.h>



using namespace std;



#define sz(x) (int)(x).size()

const int INF = 1e9 + 7;

const int mod = 1e9+7;

const int mxN = 2e5 + 1;



void solve()

{

	int n, m;

	cin >> n >> m;

	vector<vector<int>> adj(n);

	vector<int> dist(n, INF), color(n, 0);



	int p, b; cin >> p >> b;

	vector<int> tokens(p);

	for (int i = 0; i < p; ++i)

	{//2,3 := token

		cin >> tokens[i];

		color[--tokens[i]] += 2;

	}

	vector<int> bonuses(b);

	for (int i = 0; i < b; ++i)

	{//1,3 := bonus

		cin >> bonuses[i];

		++color[--bonuses[i]];

	}



	auto isBonus = [&](int node) -> bool

	{

		return (color[node] & 1);

	};

	auto isToken = [&](int node) -> bool

	{

		return (color[node] >= 2);

	};



	for (int i = 0, u, v; i < m; ++i)

	{

		cin >> u >> v;

		--u; --v;

		adj[u].push_back(v);

		adj[v].push_back(u);

	}



	bool goodStart = isToken(0);

	if (!goodStart)

	{

		for (int neig : adj[0])

			if (isToken(neig))

			{

				goodStart = true;

				break;

			}

	}

	if (goodStart)

		cout << "YES\n";

	else

	{	

		queue<int> que; que.push(0);

		dist[0] = 0;

		while(!que.empty())

		{

			int node = que.front();

			que.pop();

			for (int neig : adj[node])

			{

				if (dist[neig] > dist[node] + 1)

				{

					dist[neig] = dist[node] + 1;

					if (isBonus(neig))

						que.push(neig);

				}

			}

		}



		vector<int> canGo; canGo.reserve(2);

		for (int i = 0; i < p && sz(canGo) < 2; ++i)

			if (dist[tokens[i]] != INF)

				canGo.push_back(tokens[i]);



		if (canGo.empty())

			cout << "NO\n";

		else if (sz(canGo) == 2)

			cout <<"YES\n";

		else

		{

			int winner = canGo[0];

			set<int> infMover;

			for (int bonusNode : bonuses)

			{

				if (sz(infMover) >= 2) break;

				vector<int> movers; int bonusNeig = 0;

				if(isToken(bonusNode))

					movers.push_back(bonusNode);

				for (int neig : adj[bonusNode])

				{

					if (isBonus(neig))

						bonusNeig = 1;

					if (isToken(neig))

						movers.push_back(neig);

				}

				if (bonusNeig)

					for (int x : movers)

						infMover.insert(x);

			}



			if (sz(infMover) >= 2 || 

				(sz(infMover) == 1 

				&& infMover.find(winner) == infMover.end())

			)

			{

				cout << "YES\n";

			}

			else

			{

				set<int> movers;

				for (int node : tokens)

				{

					bool run = (node != winner);

					for (int neig : adj[node])

					{

						if (!run) break;

						if (isBonus(neig))

						{

							movers.insert(node);

							run = false;

						}

					}

				}



				cout << (dist[winner] <= 1 + movers.size() ? "YES" : "NO") << "\n";

			}



		}

	}

}



int main()

{

	ios::sync_with_stdio(0); cin.tie(0);

	int test = 1;

	cin >> test;

	while (test--)

		solve();

	return 0;

}