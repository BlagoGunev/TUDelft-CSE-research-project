#include <cstdio>

#include <algorithm>

using namespace std;



const int N=20000+5;



int n, a[N];



int t[N];



int main() {

	scanf("%d", &n);

	for(int i=0; i<n; ++i) scanf("%d", &a[i]);

	int ans=-0x3f3f3f3f;

	for(int i=1; i<=n; ++i) if(n%i==0 && n/i>=3) {

		for(int j=0; j<i; ++j) t[j]=0;

		for(int j=0; j<n; ++j) t[j%i]+=a[j];

		for(int j=0; j<i; ++j) ans=max(ans, t[j]);

	}

	printf("%d\n", ans);

	return 0;

}