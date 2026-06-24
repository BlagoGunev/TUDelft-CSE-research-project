#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=int(s); i<int(t); i++)
#define mst(A,k) memset(A,k,sizeof(A))

int n, m;
int a[100005], b[100005];
int fst[100005], nxt[100005], v[100005], tol;
int deg[100005];
int order[100005];
int pa[100005], vispa[100005];

void init()
{
	tol = 0;
	mst(fst, -1);
}
void edge(int a, int b)
{
	v[tol] = b;
	nxt[tol] = fst[a];
	fst[a] = tol++;
}
int main() {
	//freopen("in.txt","r",stdin); 

	scanf("%d%d", &n, &m);
	init();
	rep(i, 0, m)
	{
		scanf("%d%d", a + i, b + i);
		edge(a[i], b[i]);
		deg[b[i]]++;
	}
	int o = 0, pos = -1, ans = -1;
	rep(i, 1, n + 1) if(deg[i] == 0)
	{
		if(pos == -1) pos = i;
		else
		{
			pos = -1;
			break;
		}
	}
	while(~pos)
	{
		order[o++] = pos;
		int nxtpos = -1;
		for(int e = fst[pos]; ~e; e = nxt[e])
		{
			deg[v[e]]--;
			if(deg[v[e]] == 0)
			{
				if(nxtpos == -1) nxtpos = v[e];
				else
				{
					nxtpos = -1;
					break;
				}
			}
		}
		pos = nxtpos;
	}
	if(o == n)
	{
		rep(i, 1, n) pa[order[i]] = order[i-1];
		int cnt = 0;
		rep(i, 0, m) if(a[i] == pa[b[i]])
		{
			cnt++;
			if(cnt == n - 1)
			{
				ans = i + 1;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}