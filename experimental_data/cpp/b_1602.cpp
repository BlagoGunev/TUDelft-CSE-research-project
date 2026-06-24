#include <bits/stdc++.h>
using namespace std;

char *__abc147, *__xyz258, __ma369[100000];
#define __hv007() ((__abc147==__xyz258) && (__xyz258=(__abc147=__ma369)+fread(__ma369,1,100000,stdin),__abc147==__xyz258) ? EOF : *__abc147++)

int getInt(){
	int sgn = 1;
	char ch = __hv007();
	while( ch != '-' && ( ch < '0' || ch > '9' ) ) ch = __hv007();
	if ( '-' == ch ) {sgn = 0;ch=__hv007();}

	int ret = (int)(ch-'0');
	while( '0' <= (ch=__hv007()) && ch <= '9' ) ret = ret * 10 + (int)(ch-'0');
	return sgn ? ret : -ret;
}

#ifndef ONLINE_JUDGE
int const SIZE = 21;
#else 
int const SIZE = 2100;
#endif

typedef vector<int> vi;

int N;
int A[SIZE], B[SIZE];
int Q;
int X, K;

int Cnt[2010] = {0};
vector<vi> Vec;

void preproc(){
	while(1){
		bool flag = true;
		for(int i=1;i<=N;++i)if(Cnt[i]&&Cnt[i]!=i){
			flag = false;
		}
		if(flag) break;

		Vec.push_back(vi(N+1, 0));
		vi &pre = *----Vec.end();
		vi &vec = *--Vec.end();

        fill(B, B+N+1, 0);
		for(int i=1;i<=N;++i){
            ++B[vec[i] = Cnt[pre[i]]];
		}
		copy(B, B+N+1, Cnt);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.txt", "r", stdin);
#endif
    int nofkase = getInt();
	while(nofkase--){
		fill(Cnt, Cnt+N+1, 0);		
		Vec.clear();

		N = getInt();
		Vec.push_back(vi(N+1, 0));
        for(int i=1;i<=N;++i) ++Cnt[Vec[0][i] = getInt()];

		preproc();
		int n = Vec.size();

		Q = getInt();
		for(int i=1;i<=Q;++i){
            X = getInt();
			K = getInt();
			
			if(K>=n) K = n - 1;
			printf("%d\n", Vec[K][X]);
		}
	}
	return 0;
}