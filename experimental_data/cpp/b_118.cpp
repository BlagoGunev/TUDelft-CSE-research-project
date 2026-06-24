#include <bits/stdc++.h>

using namespace std;



#define sc(a) scanf("%d",&a)

#define scll(a) scanf("%I64d",&a)

#define scs(a) scanf(" %s",a)

#define scc(a) scanf(" %c",&a)



const int MAX = 1e5+6;

const int INF = 2e9+3;

const long long MOD = 1e9+7;



long long power (long long a ,long long e ,long long mod)

{

	if (e == 0)

		return 1ll;

	if (e == 1)

		return a % mod;

	if (e%2 == 1)

		return ((a%mod) * power(a,e-1,mod))%mod;

	else

	{

		long long tmp = power(a,e/2,mod);

		return (tmp*tmp)%mod;

	}

}



long long gcd(long long x,long long y)

{

    return __gcd(x,y);

}



long long lcm(long long x,long long y)

{

    return (x*y)/gcd(x,y);

}



int arr[MAX];



int main()

{

    int n;

    sc(n);



    int mx = 2*n+1;



    for(int i=0;i<2*n+1;++i)

    {

        int x = i;

        if(x > n)

            x = 2*n-i;



        for(int j=0;j<(mx-(2*x+1))/2;++j)

            putchar(' '),putchar(' ');



        for(int j=0;j<2*x+1;++j)

        {

            int y = j;

            if(y > x)

                y = 2*x-j;

            printf("%d",y);

            if(j+1 < 2*x+1)

                putchar(' ');

        }

        puts("");

    }



    return 0;

}