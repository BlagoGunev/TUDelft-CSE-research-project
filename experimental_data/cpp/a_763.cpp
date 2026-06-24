//============================================================================
// Author       : Sun YaoFeng
//============================================================================

//#pragma 	comment(linker, "/STACK:100240000,100240000")
//#include	<cstdio>
//#include	<cstdlib>
//#include	<cstring>
//#include	<algorithm>

#include	<bits/stdc++.h>

using	namespace	std;

#define DB		double
#define	lf		else if
#define I64		long long
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

#define	fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	100005

int		N, D, A[n], st[n];

struct	Lin{
		int v, next;
}E[n << 1];

void	Link(int u, int v)	{
		E[++ D]= (Lin){v, st[u]};	st[u]= D;
		E[++ D]= (Lin){u, st[v]};	st[v]= D;
}

int		DFS1(int u, int f)	{
		for (int i= st[u], v; i; i= E[i].next)
			if	((v= E[i].v) != f)	{
				int t= DFS1(v, u);
				if	(t)	return	t;
			}
		
		for (int i= st[u], v; i; i= E[i].next)
			if	((v= E[i].v) != f && A[v] != A[u])	return	u;
		return	0;
}

bool	DFS2(int u, int f, int c)	{
		if	(A[u] != c)	return	0;
		
		for (int i= st[u], v; i; i= E[i].next)
			if	((v= E[i].v) != f)	{
				if	(! DFS2(v, u, c))	return	0;
			}
		
		return	1;
}

int		main(int argc, char* argv[]){
		N= IN();
		For(i, 2, N)	Link(IN(), IN());
		For(i, 1, N)	A[i]= IN();
		
		int	u= DFS1(1, 0);
		if	(! u)	u= 1;
		
		for (int i= st[u]; i; i= E[i].next)	{
			int v= E[i].v;
			if	(! DFS2(v, u, A[v]))	return	puts("NO"), 0;
		}
		
		puts("YES");
		printf("%d\n", u);
		
		return	0;
}