#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


#define MP make_pair
typedef pair<int,int> pii;
typedef long long LL;
const int MAX=1004;
int v[MAX][MAX];
LL s[MAX][MAX];
int minv[MAX][MAX];
int mv[MAX][MAX];
bool vis[MAX][MAX];
int n,m,a,b;

LL get_sum(int x0, int y0, int x1, int y1) {
	LL v = s[x0][y0];
	if (x1+1<n) v -= s[x1+1][y0];
	if (y1+1<m) v -= s[x0][y1+1];
	if (x1+1<n && y1+1<m) v += s[x1+1][y1+1];
	return v;
}

pair<LL, pii> sites[MAX*MAX];
pii output[MAX*MAX];
LL am[MAX*MAX];

int main() {
	while (2==scanf("%d %d", &n, &m)) {
		scanf("%d %d", &a, &b);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				scanf("%d", &v[i][j]);

		for (int i=n-1;i>=0;--i) {
			for (int j=m-1;j>=0;--j) {
				s[i][j] = v[i][j];
				if (i+1<n) s[i][j] += s[i+1][j];
				if (j+1<m) s[i][j] += s[i][j+1];
				if (i+1<n && j+1<m) s[i][j] -= s[i+1][j+1];
			}
		}

		for (int i=0;i<n;++i) {
			deque<pii> s;
			for (int j=0;j<m;++j) {
				while (!s.empty() && s.front().second < j-(b-1)) s.pop_front();
				while (!s.empty() && s.back().first > v[i][j]) s.pop_back();
				s.push_back(MP(v[i][j],j));
				if (j >= b-1) {
					minv[i][j-(b-1)] = s.front().first;
				}
			}
		}

		for (int j=0;j<m-b+1;++j) {
			deque<pii> s;
			for (int i=0;i<n;++i) {
				while (!s.empty() && s.front().second < i-(a-1)) s.pop_front();
				while (!s.empty() && s.back().first > minv[i][j]) s.pop_back();
				s.push_back(MP(minv[i][j],i));
				if (i >= a-1) {
					mv[i-(a-1)][j] = s.front().first;
				}
			}
		}

		typedef pair<LL,pii> elem_t;
		int cnt = 0;
		for (int i=0;i<n-a+1;++i) {
			for (int j=0;j<m-b+1;++j) {
				vis[i][j] = 0;
				LL sum = get_sum(i,j,i+a-1,j+b-1);
				sites[cnt] = MP(sum - LL(a)*LL(b)*mv[i][j], MP(i,j));
				++cnt;
			}
		}
		sort(sites,sites+cnt);

		int res = 0;
		for (int i=0;i<cnt;++i) {
			int x = sites[i].second.first;
			int y = sites[i].second.second;
			LL now = sites[i].first;
			if (vis[x][y]) continue;
			output[res].first = x;
			output[res].second = y;
			am[res] = now;
			++res;

			for (int i=max(0, x-a+1); i < min(n, x+a); ++i) {
				for (int j=max(0,y-b+1);j < min(m, y+b); ++j) {
					vis[i][j] = 1;
				}
			}

		}
		cout << res << endl;
		for (int i=0;i<res;++i) {
			printf("%d %d %I64d\n", output[i].first+1, output[i].second+1, am[i]);
		}
	}
}