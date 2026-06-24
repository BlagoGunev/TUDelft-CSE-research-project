#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <ctime>

#include <cctype>

#include <cstring>

#include <vector>

#include <map>

#include <set>

#include <stack>

#include <queue>

#include <complex>

#define INF 1<<29

#define LL long long

#define N 100

using namespace std;



void read(int &k)

{

	int x=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}

	k=x*f;

}



int n,m,l,r=INF;



int main()

{

    read(n),read(m);

    if(!m) {printf("%d\n",n-1);return 0;}

    for(int i=1;i<=m;i++)

    {

    	int x,y;

    	read(x),read(y);

    	if(x>y) swap(x,y);

    	l=max(l,x),r=min(r,y);

    }

    if(r-l>=0)

    	printf("%d\n",r-l);

    else 

    	printf("0\n");

    return 0;

}