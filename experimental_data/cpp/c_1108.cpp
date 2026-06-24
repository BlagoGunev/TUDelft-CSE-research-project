#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vii;
typedef vector<pair<ll, ll>> vll;
#define fastio ios::sync_with_stdio(false);cin.tie(0);
#define all(x) x.begin(), x.end()
ll gcd(ll a, ll b) { if (a < b)return gcd(b, a); else if (!b)return a; else return gcd(b, a%b); }
ll lcm(ll a, ll b) { if (!a || !b)return 0; else return a * b / gcd(a, b); }

vector<tuple<ll, ll, ll>> vc;

ll uf[200005];

int find(ll a)
{
	if (uf[a] < 0)return a;
	return uf[a] = find(uf[a]);
}

bool merge(ll a, ll b)
{
	a = find(a);
	b = find(b);
	if (a == b)return false;
	uf[b] = a;
	return true;
}

vector<char> list = {'B','G','R' };
int main()
{
	fastio;

	int n;
	cin >> n;

	string a, b, c;
	cin >> b;
	int mini = 0x7FFFFFF;
	do
	{
		a.resize(n);
		for (int j = 0; j < n && j < 3; j++)
		{
			for (int k = 0; k + j < n; k += 3)
			{
				a[j + k] = list[j];
			}
		}
		int cnt = 0;
		for (int i=0;i<a.size();i++)
		{
			if (a[i] != b[i])++cnt;
		}
		if (mini > cnt)
		{
			mini = cnt;
			c = a;
		}
	} while (next_permutation(all(list)));
	cout << mini << '\n';
	cout << c;
	return 0;
}