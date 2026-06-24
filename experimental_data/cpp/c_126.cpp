#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define S second
#define F first

typedef long long ll;
typedef double ld;

using namespace std;

int n, res;
char s[3000][3000];
int sum[3000];

void solve ()
{
	memset (sum, 0, sizeof (sum));
	for (int i = 0, cur; i < n; i++)
	{
		cur = 0;
	 	for (int j = n-1; j > i; j--)
	 	{
	 	 	int col = (s[i][j]-'0') ^ sum[j] ^ cur;
//	 	 	printf ("here i = %d j = %d col = %d\n", i, j, col);
	 	 	if (!col) continue;
			cur ^= 1;
			sum[j] ^= 1;
			res++;
	 	}
		s[i][i] = ((s[i][i]-'0')^sum[i]^cur)+'0';
	}
}

int main ()
{
	#ifndef ONLINE_JUDGE
		freopen ("input", "r", stdin);
		freopen ("output", "w", stdout);
	#endif

	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%s", s[i]);

	solve ();
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			swap (s[i][j], s[j][i]);
	solve ();

	for (int i = 0; i < n; i++)
		if (s[i][i] == '1')
			res++;
	printf ("%d\n", res);

	return 0;
}