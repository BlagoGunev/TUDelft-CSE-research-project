#include <bits/stdc++.h>

#include <string>

#include <sstream>

#include <cctype>

using namespace std;



#define ll long long

#define MOD 1000000007

#define vi vector<int>

#define vll vector<ll>

#define pii pair<ll, ll>

#define mii map<ll, int>

#define pb push_back

#define mk make_pair

#define fi first

#define se second

#define all(a) (a).begin(), (a).end()

#define rall(a) (a).rbegin(), (a).rend()

#define sz(x) (int)x.size()

#define pi (3.141592653589)

#define min3(a, b, c) min(c, min(a, b))

#define _sum(v) accumulate(all(v), 0ll)

#define min4(a, b, c, d) min(d, min(c, min(a, b)))

#define fo(i, a, b) for (int i = a; i < b; i++)

#define rfo(i, a, b) for (int i = a - 1; i >= b; i--)

#define to_lower(s) transform(all(s), s.begin(), ::tolower)

//#define endl "\n"

bool is2(ll n)

{

	if (n == 0)

	return false;

	return (ceil(log2(n)) == floor(log2(n)));

}

ll pw(ll a, ll b, ll n = 1000000007)

{

	ll res = 1;

	while (b > 0)

	{

		if ((b & 1) != 0)

		{

			res = (res % n * a % n) % n;

		}

		a = (a % n * a % n) % n;

		b = b >> 1;

	}

	return res;

}

bool is_prime(ll n)

{

	if (n == 1)

		return false;

	if (n == 2)

		return true;

	fo(i, 2, sqrt(n) + 1)

	{

		if (n % i == 0)

			return false;

	}

	return true;

}

ll gcd(ll a, ll b)

{



	while (b)

	{

		ll x = b;

		b = a % b;

		a = x;

	}

	return a;

}



int lower(vector<int> &v, int x)

{

	int l = 0, h = v.size() - 1, mid;

	while (h - l > 1)

	{

		mid = (h + l) / 2;

		if (v[mid] < x)

		{

			l = mid + 1;

		}

		else

			h = mid;

	}

	if (v[l] >= x)

		return v[l];

	if (v[h] >= x)

		return v[h];



	return -1;

}



bool iscube(long long n)

{

	long long x = cbrt(n);

	return n == x * x * x;

}



int upper(vector<long long> &v, long long x)

{

	long long l = 0, h = v.size() - 1, mid;

	while (h - l > 1)

	{

		mid = (h + l) / 2;

		if (v[mid] <= x)

		{

			l = mid + 1;

		}

		else

			h = mid;

	}

	if (v[l] > x)

		return l;

	if (v[h] > x)

		return h;



	return -1;

}

ll mod_exp(ll x, ll y, ll m)

{

	long long res = 1;

	x = x % m;

	if (x == 0)

		return 0;

	while (y > 0)

	{



		if (y % 2)

			res = ((res % m) * (x % m)) % m;

		y = y >> 1;

		x = ((x % m) * (x % m)) % m;

	}

	return res;

}

long long dig_sum(long long n)

{

	long long sum = 0;

	while (n)

	{

		sum += n % 10;

		n /= 10;

	}

	return sum;

}



int dig(ll n)

{

	ll x = 0;

	while (n)

	{

		x += n % 2;

		n /= 2;

	}

	return x;

}

ll rev(ll n)

{

	ll x = 0;

	while (n)

	{

		x = x * 10 + n % 10;

		n /= 10;

	}

	return x;

}

ll sot(string s)

{

	ll x = 0;

	fo(i, 0, s.size())

	{

		x = x * 10 + (int)(s[i]) - (int)'0';

	}

	return x;

}

bool cmp(string a, string b)

{

	return sz(a) < sz(b);

}



void solve()

{



	long long n, l = 0, m = 0, k = LLONG_MAX, ans = 0, sum = 0, r = -1, x = 0, y = 0, z = 0;

    set<int> st;

	cin>>n>>k;

	fo(i,0,n)

	{

		cin>>x;

		st.insert(x);

	}

	if(k>=sz(st))cout<<1<<endl;

	else

	{

		if(st.count(0))

		{

			if(k>1)cout<<ceil((sz(st)-1)/(k-1.0))<<endl;

			else cout<<-1<<endl;

		}

		else

		{

			if(k>1)cout<<1+ceil((sz(st)-k)/(k-1.0))<<endl;

			else cout<<-1<<endl;

		}

	}    

 }

int main()

{



	ios_base::sync_with_stdio(false);

	cin.tie(NULL);



			  int t;

			  cin>>t;

		      while(t--)

	solve();

	return 0;

}