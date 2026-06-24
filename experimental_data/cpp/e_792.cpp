#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<list>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<cmath>
#include<string>

#define sd(a) scanf("%d", &a);
#define sld(a) scanf("%lld", &a);
#define pd(a) printf("%d ", a);
#define pld(a) printf("%lld", a);

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;

int xx[4] = { 0, 0, -1, 1 };
int yy[4] = { -1, 1, 0, 0 };

int N;
lli mini;
vector<lli> ve;

lli cal(lli large, lli value) {
	lli ret = 0;
	lli small = large - 1;
	if (value >= (large - 2) * (large - 1)) {
		ret = (value + large - 1) / large;
	}
	else {
		if (value / small < value % small) {
			ret = -1;
		}
		else {
			ret = (value + large - 1) / large;
		}
	}
	return ret;
}

int main(void) {
	sd(N);
	mini = 2000000000;
	for (int i = 1; i <= N; i++) {
		lli temp;
		sld(temp);
		ve.push_back(temp);
		mini = min(mini, temp);
	}

	lli ind = 1;
	while (1) {
		lli cur = mini / ind;
		lli cou = 0;
		cur++;
		for (int i = 0; i < ve.size(); i++) {
			lli temp = cal(cur, ve[i]);
			if (temp == -1) {
				break;
			}
			cou += temp;
			if (i == ve.size() - 1) {
				printf("%lld", cou);
				return 0;
			}
		}
		cou = 0;
		cur--;
		for (int i = 0; i < ve.size(); i++) {
			lli temp = cal(cur, ve[i]);
			if (temp == -1) {
				break;
			}
			cou += temp;
			if (i == ve.size() - 1) {
				printf("%lld", cou);
				return 0;
			}
		}
		cou = 0;
		cur--;
		for (int i = 0; i < ve.size(); i++) {
			lli temp = cal(cur, ve[i]);
			if (temp == -1) {
				break;
			}
			cou += temp;
			if (i == ve.size() - 1) {
				printf("%lld", cou);
				return 0;
			}
		}
		ind++;
	}

	return 0;
}