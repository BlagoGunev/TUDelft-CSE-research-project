#include <cstdio>

#include <cstring>

#define dmax(a, b) ((a) > (b) ? (a) : (b))

#define IL __inline__ __attribute__((always_inline))

#define RG register



const int MaxN = 20010;

int N, M, mod, A[MaxN], B[MaxN];



IL int F()

{

	static const int MaxBuff = 1 << 15; static char b[MaxBuff], *S = b, *T = b;

	#define getc() (S == T && (T = (S = b) + fread(b, 1, MaxBuff, stdin), S == T) ? 0 : *S++)

	RG char ch; RG int ans = 0;

	while(ch = getc(), ch < '0' || ch > '9') ; ans = ch - '0';

	while(ch = getc(), '0' <= ch && ch <= '9') ans = ans * 10 + ch - '0';

	return ans;

}



char pace[MaxN << 1], *iter = pace;

int ans, L[MaxN], R[MaxN];



#define val(i, j) ((A[i] + B[j]) % mod)



void divide(RG int l, RG int r, RG int s, RG int t)

{

	if(l == r)

	{

		//printf("[%d, %d]\n", s, t);

		while(s <= t) *++iter = 'S', ans += val(l, s++);

		return;

	}

	RG int m = (l + r) >> 1;

	RG int i, j;

	memset(L + 1, 128, M << 2);

	memset(R + 1, 128, M << 2);

	L[s] = R[t] = 0;

	for(i = l; i <= m; ++i) for(j = s; j <= t; ++j)

		L[j] = dmax(L[j], L[j - 1]) + val(i, j);

	for(i = r; i != m; --i) for(j = t; j >= s; --j)

		R[j] = dmax(R[j], R[j + 1]) + val(i, j);

	RG int cho = 0, max = -1;

	for(i = s; i <= t; ++i) if(L[i] + R[i] > max)

		cho = i, max = L[i] + R[i];

	divide(l, m, s, cho);

	*iter = 'C';

	divide(m + 1, r, cho, t);

}



int main()

{

	N = F(), M = F(), mod = F();

	for(RG int i = 1; i <= N; ++i) A[i] = F();

	for(RG int i = 1; i <= M; ++i) B[i] = F();

	divide(1, N, 1, M);

	printf("%d\n", ans);

	*iter = '\n';

	//fprintf(stderr, "%d\n", iter - pace);

	fwrite(pace + 1, 1, iter - pace, stdout);

}