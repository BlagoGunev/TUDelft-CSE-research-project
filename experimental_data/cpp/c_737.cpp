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

#define n	200005

int		N, S, Ans, A[n], B[n];

int		main(int argc, char* argv[]){
		N= IN();
		S= IN();
		For(i, 1, N)	{
			A[i]= IN();
			if	(i == S && A[i] != 0)	Ans++, A[i]= 0;
			if	(i != S && A[i] == 0)	A[i]= N;
			B[A[i]]++;
		}
		
		for (int i= 1, j= N; ; )	{
			for (; ! B[j]; j--);
			if	(j <= i)	break;
			
			if	(B[i])	i++;
			else	{
				B[j]--;
				B[i]++;
				i++;
				Ans++;
			}
		}
		
		printf("%d\n", Ans);
		
		return	0;
}