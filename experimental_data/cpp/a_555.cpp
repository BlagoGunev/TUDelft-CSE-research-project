#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

inline int fast_input(void)
{
	char t;
	int x=0;
	int neg=0;
	t=getchar();
	while((t<48 || t>57) && t!='-')
		t=getchar();
	if(t=='-')
		{neg=1; t=getchar();}
    while(t>=48 && t<=57)
    {
        x=(x<<3)+(x<<1)+t-48;
        t=getchar();
    }
	if(neg)
		x=-x;
	return x;
}

inline void fast_output(int x)
{
	char a[20];
	int i=0,j;
	a[0]='0';
	if (x<0) {putchar('-'); x=-x;}
	if (x==0) putchar('0');
	while(x)
	{
		a[i++]=x%10+48;
		x/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		putchar(a[j]);
	}
	putchar('\n');
}

int main()
{
int n,k,a[100001],i,j,m,dis=0,c,moves=0;
n=fast_input();
k=fast_input();
for(i=0;i<k;i++)
{
	dis++;
	m=fast_input();
	a[0]=fast_input();
	m--;
	if (a[0]==1) c=0;
	else
	{
		c=1;
		moves+=m;
		dis+=m;
	}
	for(j=1;j<=m;j++)
	{
		a[j]=fast_input();
		if (a[j]!=a[j-1]+1&&c==0) 
		{
			dis+=m-j+1;
			moves+=m-j+1;
			c=1;
		}
	}
}
fast_output(dis+moves-1);
return 0;
}