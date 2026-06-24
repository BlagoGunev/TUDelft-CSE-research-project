#include <cstdio>

#include <cctype>

#include <algorithm>

#define repu(i,x,y) for (int i=x; i<=y; ++i)

using namespace std;



typedef unsigned long long ULL;

int n,x;

ULL pow[300100],bit1[300100],bit2[300100];



int getint()

{

    char ch;

    while (!isdigit(ch=getchar()));

    int x=ch-'0';

    for (; isdigit(ch=getchar()); x=x*10+ch-'0');

    return x;

}



void insert(ULL *bit,int x)

{

    for (int t=x; t<=n; t+=t&-t)

        bit[t]+=pow[x];

}



ULL query(ULL *bit,int x)

{

    ULL ret=0;

    for (; x; x-=x&-x)

        ret+=bit[x];

    return ret;

}



ULL query(ULL *bit,int l,int r)

{

    return (query(bit,r)-query(bit,l-1))*pow[n-r];

}



int main()

{

    n=getint(),pow[0]=1;

    repu(i,1,n)

        pow[i]=pow[i-1]*233;

    repu(i,1,n)

    {

        insert(bit1,x=getint()),insert(bit2,n-x+1);

        int t=min(x-1,n-x);

        if (query(bit1,x-t,x)!=query(bit2,n-x+1-t,n-x+1))

        {

            puts("YES\n");

            return 0;

        }

    }

    puts("NO\n");

    return 0;

}