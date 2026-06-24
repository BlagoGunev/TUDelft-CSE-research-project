# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
int t, n, q;
char s[MAXN];
int a[MAXN], s1[MAXN];
int work(int l, int r){
	int lft = l, rgt = r;
	int ans = lft;
	if (s1[r - 1] - s1[l - 1] == 0) return r;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		if (s1[mid - 1] - s1[l - 1] == s1[r] - s1[mid]) return mid;
		int nm = s1[mid - 1] - s1[l - 1] - (s1[r] - s1[mid]);
		if ((nm > 0) ^ (s1[r - 1] - s1[l - 1] > 0)) lft = mid + 1;
		else rgt = mid - 1;
	}
	return ans;
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &q);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++){
			a[i] = ((s[i] == '+') ^ (i & 1)) ? -1 : 1;
			s1[i] = s1[i - 1] + a[i];
		}
		for (int i = 1; i <= q; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			if (s1[v] == s1[u - 1]) printf("0\n");
			else if ((v - u + 1) & 1) printf("1\n%d\n", work(u, v));
			else printf("2\n%d %d\n", work(u, v - 1), v);
		}
	}
	return 0;
}