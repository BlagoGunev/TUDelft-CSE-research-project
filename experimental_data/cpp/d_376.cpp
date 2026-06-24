#include <iostream>
#include <iomanip>
#include <set>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
using namespace std;
#define mp make_pair
#define ull unsigned long long
#define ll long long

static ll m1[6000][6000];
static char s[6000][6000];

int main(){
	ios_base::sync_with_stdio(0);
	int n, m, a;
	ll res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		cin >> s[i];
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '1'){
				a = j;
				for (; s[i][a] == '1'; ++a)
					m1[j][a]++;
				j = a;
			}
	}
	for (int i = 1; i < m; ++i)
		for (int j = i; j < m; ++j)
			m1[i][j] += m1[i - 1][j];
	for (int i = 0; i < m; ++i)
		for (int j = i; j < m; ++j)
			res = max(res, m1[i][j] * (j - i + 1));
	cout << res << endl;
	return 0;
}