#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;
typedef vector<pair<ll, ll>> vpl;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;

bool vis[20000];

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	int n, k;
	cin >> n >> k;

	vi a(n);
	for (auto& i : a)
		cin >> i;

	if (k == 1){
		cout << *max_element(a.begin(), a.end()) << '\n';
		cout << n;
		return 0;
	}

	vi b = a;
	sort(b.rbegin(), b.rend());

	vi c;
	int suma = 0;
	for (int i = 0; i < k; ++i){
		c.push_back(b[i]);
		suma += b[i];
	}

	vi pos;
	for (auto& i : c){
		for (int j = 0; j < n; ++j){
			if (i == a[j] && !vis[j]){
				pos.push_back(j);
				vis[j] = 1;
				break;
			}
		}
	}

	cout << suma << '\n';
	sort(pos.begin(), pos.end());
	cout << pos[0] + 1 << ' ';
	int l = pos.size();
	for (int i = 1; i < l - 1; ++i){
		cout << pos[i] - pos[i - 1]<< ' ';
	}

	cout << n - pos[l - 2] - 1;
}