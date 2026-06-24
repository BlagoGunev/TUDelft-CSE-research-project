#include <bits/stdc++.h>

using namespace std;



#define sc(a) scanf("%d",&a)

#define scll(a) scanf("%lld",&a)

#define scs(a) scanf(" %s",a)

#define scc(a) scanf(" %c",&a)



const int MAX = 1e6+5;

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



int main()

{

    int n;

    cin>>n;



    int num7 = n/7;

    int temp = n%7;

    int num4 = temp/4;

    if(temp%4 > 0)

    {

        if(temp%4 <= num7)

        {

            num7 -= temp%4;

            num4 += (temp%4)*2;

        }

        else

        {

            cout<<-1;

            return 0;

        }

    }

    for(int i=0;i<num4;++i)

        printf("%s","4");

    for(int i=0;i<num7;++i)

        printf("%s","7");





    return 0;

}