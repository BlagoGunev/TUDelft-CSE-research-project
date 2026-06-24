#include <bits/stdc++.h>

using namespace std;

vector<bool> p(100001, 0);

vector<int> primes;

void sieve()

{

    primes.push_back(2);

    for (int i=3; i<100001; i+=2)

    {

 

        if (p[i]==0)

        {

            primes.push_back(i);

            for (int j=i*2; j<100001; j+=i)

            {

                p[j]=1;

 

            }

        }

    }

}

 

int main()

{

    sieve();

 

    int T;

    scanf("%d", &T);

 

    int t=0;

 

    while (t<T)

    {

        int n; scanf("%d",&n);

        map <int, int> cnt;

        bool fnd=false;

        for (int i=0; i<n; i++)

        {

            int u;

 

            scanf("%d",&u);

 

            int next=1;

            for (int j=2; j*j<=u && fnd==0;)

            {

                if (u%j==0) {cnt[j]++; if(cnt[j]>1) fnd=true;}

                while (u%j==0) u/=j;

                j=primes[next++];

 

            }

            if (u>1){ cnt[u]++; if(cnt[u]>1) fnd=true;}

        }

        if (fnd) cout <<"YES\n";

        else cout <<"NO\n";

 

 

 

 

        t++;

 

    }

 

 

}