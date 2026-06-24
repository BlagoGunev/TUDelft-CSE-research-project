#include <bits/stdc++.h>

#define X first

#define Y second

#define FI(i,a,b) for(int i=(a);i<=(b);i++)

#define FD(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;

using LL = long long;

using PII = pair<int,int>;



const int N = 105;

int n, m;

char a[N][N];

int level[N];



int main() {

	scanf("%d%d", &n, &m);

	FI(i,1,n) scanf("%s", &a[i]);

	int ans = 0;

	FI(j,0,m-1) {

		bool ok = true;

		FI(i,2,n) {

			if (level[i]>level[i-1]) continue;

			else if (a[i][j]<a[i-1][j]) { ok=false; break; }

		}

		if (!ok) { ans++; continue; }

		FI(i,2,n) {

			if (level[i]>level[i-1]) continue;

			else if (level[i]==level[i-1]) {

				if (a[i][j]>a[i-1][j]) FI(k,i,n) level[k]++;

			} else if (level[i]<level[i-1]) printf("No\n");

		}

	}

	printf("%d\n", ans);

}