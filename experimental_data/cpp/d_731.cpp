#include <stdio.h>

#define min(a , b) (a < b ? a : b)

const int MAXBUF = 1<<22; char B[MAXBUF] , *S = B , *T = B;

#define getch() (S == T && (T = (S = B) + fread(B,1,MAXBUF,stdin) , S == T ) ? EOF : *S ++)

inline int F() { register int aa , bb , ch;

	while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);

	while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;

}

const int Maxn = 500010;

#define R register

int a[2][Maxn] , sum[1000001];

int main() {

	R int n = F() , m = F() , l[2]; ++sum[0] , --sum[m];

	for(R int i=1 , p = 1; i<=n; ++i , p ^= 1) {

		l[p] = F();

		for(R int j=1; j<=l[p]; ++j)

			a[p][j] = F();

		if(i == 1) continue;

		R int lim = min(l[0],l[1]); R bool flag = 1;

		for(R int j=1; j<=lim; ++j) {

			if(a[0][j] != a[1][j]) {

				if(a[p][j] > a[p^1][j]) {

					++sum[0];

					--sum[m - a[p][j] + 1];

					++sum[m - a[p^1][j]+1];

					--sum[m];

				}

				else {

					++sum[m - a[p^1][j]+1];

					--sum[m - a[p][j] + 1];

				}

				flag = 0;

				break;

			}

		}

		if(flag)

			if(l[p] < l[p^1]) --sum[0] , ++sum[m];

			else ++sum[0] , --sum[m];

	}

	bool flag = 1;

	for(R int i=0; i<m; ++i) {

		if(sum[i] == n) {

			printf("%d",i);

			flag = 0;

			break;

		}

		sum[i+1] += sum[i];

	}if(flag) puts("-1");

}