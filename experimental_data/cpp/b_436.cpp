#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
	#define inject(x)
	#define _ (cin.sync_with_stdio(0), cin.tie(0))
#else
	#define inject(x) (cerr << #x << " = " << (x) << endl)
	#define _
#endif
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
char s[2005];
int Ans[2005];
int main()
{
	int n, m, k;
	scanf("%d%d%d\n", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		gets(s + 1);
		for (int j = 1; j <= m; ++j)
			switch (s[j]) {
				case 'U':
					Ans[j] += (i & 1);
					break;
				case 'L':
					if (j > i - 1)
						++Ans[j - (i - 1)];
					break;
				case 'R':
					if (j + (i - 1) <= m)
						++Ans[j + (i - 1)];
					break;
				default:
					break;
			}
	}
	for (int i = 1; i <= m; ++i)
		printf(i == m ? "%d\n" : "%d ", Ans[i]);
	return 0;
}