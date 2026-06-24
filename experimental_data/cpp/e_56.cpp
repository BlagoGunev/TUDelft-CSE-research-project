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



pair<int,pair<int,int> > arr[MAX];

vector<pair<int,int > > vec;

int res[MAX];



int main()

{

    int n;

    sc(n);



    for(int i=0;i<n;++i)

        sc(arr[i].first),sc(arr[i].second.first),arr[i].second.second = i+1;



    sort(arr,arr+n);



    vec.push_back({INF,0});



    for(int i=n-1;i>=0;--i)

    {

        int tmp = arr[i].first + arr[i].second.first;

        int cur = 1;

        while(vec.back().first < tmp)

            cur += vec.back().second,vec.pop_back();

        res[arr[i].second.second] = cur;

        vec.push_back({arr[i].first,res[arr[i].second.second]});

    }



    for(int i=1;i<=n;++i)

        printf("%d ",res[i]);





    return 0;

}