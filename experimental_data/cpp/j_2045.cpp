#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct FUCK{
	FUCK *child[2];
	int cnt;

	FUCK(){child[0] = child[1] = 0, cnt = 0;}

	void insert(int x, int i){
		cnt++;
		if (i == -1) return;
		int z = (x&(1<<i))>>i;
		if (!child[z]) child[z] = new FUCK;

		child[z]->insert(x, i-1);
	}

	int count(int x, int i, int sibal){
		if (i == -1) return cnt;
		
		int ret = 0, z = (x&(1<<i))>>i;
		if (child[z]){
			if (sibal & (1<<i)) ret = child[z]->count(x, i-1, sibal);
			else ret = child[z]->cnt;
		}
		if (child[z ^ 1]){
			if (!(sibal & (1<<i))) ret += child[z ^ 1]->count(x, i-1, sibal);
		}

		return ret;
	}
}*tree;

int a[200200], b[200200];

vector<int> calc(int x, int y){
	vector<int> ret = {0};
	for (int i=29;i>=0;i--){
		if ((x&(1<<i)) == (y&(1<<i))) ret.back()++;
		else ret.push_back(0);
	}
	return ret;
}

int main(){
	tree = new FUCK;
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=1;i<=n;i++) scanf("%d", a+i);
	for (int i=1;i<=m;i++) scanf("%d", b+i);

	sort(a+1, a+n+1);
	sort(b+1, b+m+1);

	int sibal = 0;
	for (int i=1;i<n;i++){
		int fuck = (a[i] ^ a[i+1]) ^ ((1<<30)-1);
		if (sibal < fuck) sibal = fuck;
	}

	ll ans = 0;

	for (int i=1;i<=m;i++) tree->insert(b[i], 29);

	for (int i=1;i<=m;i++){
		ans += tree->count(b[i], 29, sibal) - 1;
	}

	printf("%lld\n", ans / 2);
}