#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>



#define ll long long

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;



ll x[200001], p[200001];

int main()

{

	fastIO;

	int t, n;

	ll m;

	cin >> t;

	while (t--)

	{

		cin >> n >> m;

		m *= 2;

		vector<pair<ll, ll>> speed;



		for (int i = 0; i < n; i++)

		{

			cin >> x[i] >> p[i];

			x[i] *= 2;

			p[i] *= 2;

			speed.push_back({x[i] - p[i], 1});

			speed.push_back({x[i], -2});

			speed.push_back({x[i] + p[i], 1});

		}

		sort(speed.begin(), speed.end());



		pair<ll, ll> above = { -1, -1};

		ll sum = 0, velocity = 1;

		for (ll i = 1; i < speed.size(); i++)

		{

			sum += velocity * (speed[i].first - speed[i - 1].first);

			velocity += speed[i].second;

			if (sum > m)

			{

				if (above.first == -1 || sum - m - above.second > speed[i].first - above.first)

				{

					above.first = speed[i].first;

					above.second = sum - m;

				}

				else if (sum - m - above.second >= above.first - speed[i].first)

				{

					above.first = (speed[i].first + sum - m + above.first - above.second) / 2;

					above.second = sum - m + speed[i].first - above.first;

				}

			}

		}



		for (int i = 0; i < n; i++)

		{

			if (above.first == -1)

				cout << 1;

			else if (p[i] - above.second >= abs(above.first - x[i]))

				cout << 1;

			else

				cout << 0;

		}

		cout << endl;

	}

}