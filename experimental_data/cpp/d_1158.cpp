#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p;
struct node
{
	int id;
	double x, y, val;
	node() {}
	node(double _x, double _y):x(_x), y(_y) {}
	double len() const {return sqrt(x * x + y * y);}
}po[2005], ls, st;
struct node operator - (const node & u, const node & v) {return node(u.x - v.x, u.y - v.y);}
double dot(const node & u, const node & v) {return u.x * v.x + u.y * v.y;}
double cross(const node & u, const node & v) {return u.x * v.y - u.y * v.x;}
char s[2005];
bool cmp(const node & u, const node & v) {return u.val < v.val;}
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &po[i].x, &po[i].y);
		po[i].id = i;
	}
	p = 1;
	for (int i = 2; i <= n; i++)
		if (po[i].x < po[p].x || (po[i].x == po[p].x && po[i].y < po[p].y))
			p = i;
	swap(po[p], po[n]);
	scanf("%s", s + 1);
	for (int i = 1; i < n - 1; i++)
	{
		st = po[n - i + 1];
		if (s[i] == 'L')
		{
			p = 1;
			for (int j = 2; j + i <= n; j++)
				if (cross(po[j] - st, po[p] - st) > 0)
					p = j;
		}
		else
		{
			p = 1;
			for (int j = 2; j + i <= n; j++)
				if (cross(po[j] - st, po[p] - st) < 0)
					p = j;
		}
		swap(po[p], po[n - i]);
	}
	for (int i = n; i >= 1; i--) printf("%d%c", po[i].id, " \n"[i == 1]);
	return 0;
}