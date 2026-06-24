#include<bits/stdc++.h>
#define re(a, b, c) for (int a = b; a <= c; a ++)
#define de(a, b, c) for (int a = c; a >= b; a --)
#define wh(a) while (a --)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double d;
typedef long double ld;
inline int read()
{
	register int s=0,f=0;
	register char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return f?-s:s;
}
inline void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int t;
int x, y;
int main()
{
	t = read ();
	while (t --)
	{
		x = read ();
		y = read ();
		printf ("%d %d\n", x - 1, y);
	} 
	return 0;
}