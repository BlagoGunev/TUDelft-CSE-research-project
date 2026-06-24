#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
		
#define INF 0x3f3f3f3f
#define sc scanf
#define pf printf
typedef double db;
typedef long long ll;
//typedef long long int;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int dxx[8] = {0, -1, 0, 1, 1, 1, -1, -1};
int dyy[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,l,r) for(int i=l;i>=r;i--)
const int N = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll eqs = 1e-9;
vector <int> vi;
vector <ll> vll;
vector <pll> vpll;
map <string, ll> mpsl;
map <ll, ll> mpll;
		
		
////ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
/////////一川烟草 满城风絮 梅子黄时雨//////////
		
//signed main()
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, d;
		cin >> n >> m >> d;
		vector<int>pos;
		for (int i = 0 ; i < m ;  i++) {
			int num;
			cin >> num;
			pos.push_back(num);
		}
		int cnt = 0;
		int start = 1;
		int ans = 1;
		for (int i = 0 ; i < m - 1; i++) {
			int a = pos[i], b = pos[i + 1];
			if (a == start)
				continue;
			int cnt_a = (a - start - 1) / d + 1 + (b - a - 1) / d + 1;
			int cnt_b = (b - start - 1) / d + 1;
			ans += (a - start - 1) / d + 1;
			if (cnt_a > cnt_b)
				cnt++;
			start = a;
		}
		
		int a = pos[m - 1];
		int cnt_a = (a - start - 1) / d + 1 + (n - a) / d;
		ans += cnt_a;
		int cnt_b = (n - start) / d;
		if (cnt_a > cnt_b)
			cnt++;
		if (cnt)
			cout << ans - 1 << " " << cnt << endl;
		else
			cout << ans << " " << m << endl;
		
	}
	return 0;
}
		
		
//
//       ██████╗ ██╗   ██╗ ██████╗
//       ██╔══██╗██║   ██║██╔════╝
//       ██████╔╝██║   ██║██║  ███╗
//       ██╔══██╗██║   ██║██║   ██║
//       ██████╔╝╚██████╔╝╚██████╔╝
//       ╚═════╝  ╚═════╝  ╚═════╝
//