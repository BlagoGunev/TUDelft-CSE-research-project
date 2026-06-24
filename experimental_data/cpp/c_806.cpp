#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;

int n,maxK, i, d, bat[60], mat[60];
LL x;

bool ok(int k) {
	int akt = k;
	int rem = 0;
	int loss;
	for (int i=0;i<=maxK;i++) {
		if (bat[i] < akt) {
			loss = akt - bat[i];
			rem = max(rem - loss, 0);
			akt = bat[i];
		}
		rem += (bat[i] - akt);
		rem += mat[i];
		//printf("%d\n", rem);
	}
	//printf("%d %d\n", k, rem);
	return rem <= akt;
}

int main() {
scanf("%d", &n);
maxK = 0;
for (i=0;i<n;i++) {
	scanf("%I64d", &x);
	//cin >> x;
	d = 0;
	while (x > (1LL << d)) {
		d++;
	}
	if (x == (1LL << d)) {
		bat[d]++;
	} else {
		mat[d-1]++;
	}
	maxK = max(maxK, d);
}
bool bOk = false;
for (i=1;i<=bat[0];i++) {
	if (ok(i)) {
		printf("%d ", i);
		bOk = true;
	}
}
if (!bOk) {
	printf("-1\n");
} else {
	printf("\n");
}
return 0;
}