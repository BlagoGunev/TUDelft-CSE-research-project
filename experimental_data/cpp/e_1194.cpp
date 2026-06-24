#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<memory.h>
using namespace std;

#define INF 987654321
#define ll long long

struct Line {
	int ty, m, s, e;
	bool operator<(Line &n)
	{
		int y = (ty == 0 ? e : m);
		int ny = (n.ty == 0 ? n.e : n.m);
		if (y == ny) return ty < n.ty;
		return y > ny;
	}
};

int N, ycnt;
ll res;
vector<Line> v;
int fen[10002];

int Sum(int idx)
{
	int ret = 0;
	while (idx)
	{
		ret += fen[idx];
		idx &= (idx - 1);
	}
	return ret;
}

void Add(int idx, int val)
{
	while (idx <= 10001)
	{
		fen[idx] += val;
		idx += (idx&-idx);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		sx += 5001; sy += 5001; ex += 5001; ey += 5001;
		if (sy == ey) //가로
			v.push_back({ 1, sy, min(sx,ex), max(sx,ex) });
		else //세로
			v.push_back({ 0, sx, min(sy,ey), max(sy,ey) });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].ty == 0) continue;

		memset(fen, 0, sizeof(fen));
		for (int j = 0; j < i; j++)
		{
			if (v[j].ty == 0)
			{
				if (v[j].s <= v[i].m)
					Add(v[j].m, 1);
			}
			else
			{
				int L = max(v[i].s, v[j].s), R = min(v[i].e, v[j].e);
				if (L > R) continue;
				int sum = Sum(R) - Sum(L - 1);
				res += sum * (sum - 1) / 2;
			}
		}
	}

	printf("%lld", res);
	return 0;
}