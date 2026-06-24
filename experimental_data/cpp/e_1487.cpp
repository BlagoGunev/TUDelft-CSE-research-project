#include<bits/stdc++.h>
using namespace std;
typedef long long s64;
#define next nxt
#define size siz
const int ONE = 2000005;
const int INF = 400000001;
const int MOD = 1e9;

int get()
{
	int res = 1, Q = 1; char c;
	while ( (c = getchar()) < 48 || c > 57)
		if (c == '-') Q = -1;
	if (Q) res = c - 48;
	while ( (c = getchar()) >= 48 && c <= 57)
		res = res * 10 + c - 48;
	return res * Q;
}

int n[5], m[5];
struct point
{
	int val, id;
	friend bool operator <(const point &a, const point &b)
	{
		if(a.val != b.val) return a.val < b.val;
		return a.id < b.id;
	}
}A[5][ONE];

struct pi {int a, b;} q[3][ONE];
int id[ONE];
vector <int> E[ONE];
int vis[ONE];

void Deal(int id1, int id2, point *B, pi *q, int n1, int n2, int m)
{
	sort(B + 1, B + n2 + 1);
	B[n2+1].val = INF;
	for(int i = 1; i <= n2; i++) id[B[i].id] = i;
	for(int i = 1; i <= n1; i++) E[i].clear();
	for(int i = 1; i <= m; i++) E[q[i].a].push_back(q[i].b);
	
	for(int i = 1; i <= n1; i++)
	{
		for(int v : E[i]) vis[id[v]] = 1;
		int pos = 0;
		for(int j = 1; j <= n2 + 1; j++)
			if(vis[j] == 0) {pos = j; break;}
		A[id1][i].val += B[pos].val;
		for(int v : E[i]) vis[id[v]] = 0;
	}
}

int main()
{
	for(int t = 1; t <= 4; t++) n[t] = get();
	for(int t = 1; t <= 4; t++)
		for(int i = 1; i <= n[t]; i++)
			A[t][i].val = get(),
			A[t][i].id = i;
	for(int t = 1; t <= 3; t++)
	{
		m[t] = get();
		for(int i = 1; i <= m[t]; i++)
			q[t][i].a = get(), q[t][i].b = get();
	}

	Deal(3, 4, A[4], q[3], n[3], n[4], m[3]);
	Deal(2, 3, A[3], q[2], n[2], n[3], m[2]);
	Deal(1, 2, A[2], q[1], n[1], n[2], m[1]);

	sort(A[1] + 1, A[1] + n[1] + 1);
	if(A[1][1].val >= INF) printf("-1");
	else printf("%d", A[1][1].val);

}