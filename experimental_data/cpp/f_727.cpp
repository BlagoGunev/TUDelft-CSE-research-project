#include <stdio.h>

#include <string.h>

#include <iostream>

#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 1000+5;

const LL inf = 1e14+5;



inline LL read()

{

    LL x=0,f=1;char ch = getchar();

    while(ch < '0' || ch > '9'){if(ch == '-')f=-1;ch = getchar();}

    while(ch >='0' && ch <='9'){x=(x<<1)+(x<<3)+ch-'0';ch = getchar();}

    return x*f;

}



LL f[N][N];

int a[N];

LL tmp[N];



int main()

{



    int n , m;

    cin >> n >> m;

	for(int i=1;i<=n;++i) a[i] = read();



	for(int i=0;i<=n;++i)

	for(int j=0;j<=n;++j)

		f[i][j] = inf;



    f[0][0] = 0;



    for(int i=n;i;--i)

        for(int j=0;j<n-i+1;++j)

			f[n-i+1][j] = min(f[n-i+1][j],max(0ll,f[n-i][j]-a[i])),

			f[n-i+1][j+1] = min(f[n-i+1][j+1],f[n-i][j]);



	tmp[n] = 0;

	for(int i=n;~i;--i)tmp[i] = max(tmp[i+1],f[n][i]);

    

	while(m--)

	{

		LL op = read();

		printf("%d\n",lower_bound(tmp,tmp+n+1,op,greater<LL>()) - tmp);

	}

}