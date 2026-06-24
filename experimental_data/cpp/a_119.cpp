#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
# define si size
# define er erase
# define sc scanf
# define be begin
# define pr printf
# define pb push_back
# define INF 100000000.0
# define fori(x,y) for(int i=(x);i<(y);i++)
# define forj(l,r) for(int j=(l);j<(r);j++)
using namespace std;
int nod(int a,int b)
{
    if(a==0)return b;
    return nod(b%a,a);
}
main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int a,b,n;
sc("%d%d%d",&a,&b,&n);
while(1)
{
    n-=nod(a,n);
    if(n<0){pr("1");return 0;}
    n-=nod(b,n);
    if(n<0){pr("0");return 0;}
}
return 0;
}