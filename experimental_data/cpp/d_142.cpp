#include <cstdio>

#include <algorithm>

using namespace std;



const int maxn=100+5, maxm=100+5, maxk=100+5;

int n, m, k;

char rd_t[maxm];

int cnt[10];



inline int abs(int x) { return x<0 ? -x : x; }



inline int calc_nim_k() {

	for(int p=0; p<10; ++p) if(cnt[p]%(k+1)) return 1;

	return -1;

}



int main() {

	scanf("%d%d%d", &n, &m, &k);

	

	bool only_g=false, only_r=false;

	

	for(int i=1; i<=n; ++i) {

		scanf("%s", rd_t+1);

		int g=-1, r=-1;

		for(int j=1; j<=m; ++j) {

			if(rd_t[j]=='G') g=j;

			else if(rd_t[j]=='R') r=j;

		}

		if(g==-1 || r==-1) {

			if((g!=-1 || r!=-1) && !(m==2 && rd_t[1]==rd_t[2]) && !(m==1)) {

				if(~r) only_r=true;

				else if(~g) only_g=true;

			}

		} else {

			int c=abs(r-g)-1;

			for(int p=0; p<10; ++p) if(c&(1<<p)) ++cnt[p];

		}

	}

	

	int ans=calc_nim_k();

	if(only_g) ans=max(ans, -ans);

	if(only_r) ans=min(ans, -ans);

	if(only_g && only_r) ans=0;

	

	if(ans==-1) puts("Second");

	else if(ans==0) puts("Draw");

	else puts("First");

	

	return 0;

}