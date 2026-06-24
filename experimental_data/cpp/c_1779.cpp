#include<bits/stdc++.h>

using namespace std;



#define pb push_back

#define fi first

#define se second

#define mk make_pair

#define endl "\n"

#define enld "\n"

#define fastio {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}



#define For(i, n, m) for(ll (i)=(m);(i)<(n);++(i))

#define rep(i, n) For(i,n,0)



#define  LCM(a,b)    a*b/__gcd(a,b)

#define  GCD(a,b)    __gcd(a,b)



#define sz 100010

#define mod 1000000007

#define inf 100000000000000ll



typedef long long int ll;

typedef pair<ll, ll>  pl;



void solve()

{

	ll n, k;

	cin >> n >> k;

	vector<ll> v(n);

	rep(i, n) cin >> v[i];



	k--;



	priority_queue<ll> pq;



	ll sum = 0, cnt = 0;



	for (int i = k; i > 0; i--)

	{

		sum += v[i];

		pq.push(v[i]);



		while (sum > 0)

		{

			sum -= 2 * pq.top();

			pq.pop();

			cnt++;

		}



	}



	while (!pq.empty())

	{

		pq.pop();

	}



	sum = 0;



	for (int i = k + 1; i < n; i++)

	{

		sum += v[i];

		pq.push(-v[i]);



		while (sum < 0)

		{

			sum += 2 * pq.top();

			pq.pop();

			cnt++;

		}

	}



	cout << cnt << endl;

}



int main()

{

	fastio

	int t = 1;

	cin >> t;

	while (t--) solve();

}