#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 302345;
int n;
struct Tbit{
	int b[maxn];
	void add(int x){
		for (int i = x; i <= n + 1; i += (i &-i))
			b[i] ++;
	}
	int sum(int x){
		if (x < 0) return 0;
		int ans = 0;
		for (int i = x; i; i -= (i&-i))
			ans += b[i];
		return ans;
	}	
	int sum(int l, int r) { return sum(r) - sum(l - 1); }
}bit;
int a[maxn], q[maxn], id[maxn];
bool cmp(int x, int y){
	return q[x] < q[y];
}
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		id[i] = i;
		if (a[i] > n) a[i] = n + 1;
		q[i] = min(i - 1, a[i]); 
	}
	sort(id + 1, id + n + 1, cmp);
	ll ans = 0;
	int nw = 1;
	for (int i = 1; i <= n; i ++){
		while (nw <= q[id[i]] && nw <= n)
			bit.add(a[nw++]);
		ans += bit.sum(id[i], n + 1);
	}
	cout <<ans <<endl;
	return 0;
}