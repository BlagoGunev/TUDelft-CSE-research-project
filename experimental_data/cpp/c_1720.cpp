#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define nl '\n'

#define MAXN   10000

#define fast ios_base::sync_with_stdio(0); cin.tie(0);

const ll int N = 1e9;

/*

vector<ll> getFactorization(ll x)

{

    vector<ll> ret;

    while (x != 1)

    {

        ret.push_back(spf[x]);

        x = x / spf[x];

    }

    return ret;

}

int computeXOR(int n)

{



    // If n is a multiple of 4

    if (n % 4 == 0)

        return n;



    // If n%4 gives remainder 1

    if (n % 4 == 1)

        return 1;



    // If n%4 gives remainder 2

    if (n % 4 == 2)

        return n + 1;



    // If n%4 gives remainder 3

    return 0;

}



ll length(ll z)

{

    ll a=0;

    while(z)

    {

        a++;

        z/=10;

    }

    return a;

}



int setBitNumber(int n)

{

    if (n == 0)

        return 0;



    int msb = 0;

    n = n / 2;

    while (n != 0) {

        n = n / 2;

        msb++;

    }



    return (1 << msb);

}



int prime(int z)

{

    for (int i = 2; i*i<=z;i++)

    {

        if(z%i==0)

        {

            return 1;

        }

    }

    return 0;

}





ll fastpow(ll a,ll b,ll mod)

{

    if(b==0)

    {

        return 1;

    }

    ll res= fastpow(a,b/2,mod);

    res=(res*res)%mod;

    if(b%2==1)

    {

        res=(res*a)%mod;

    }

    return res;

}



ll spf[N];





void sieve()

{

    spf[1] = 1;

    for (int i=2; i<N; i++)



        spf[i] = i;





    for (int i=4; i<N; i+=2)

        spf[i] = 2;



    for (int i=3; i*i<N; i++)

    {



        if (spf[i] == i)

        {



            for (int j=i*i; j<N; j+=i)





                if (spf[j]==j)

                    spf[j] = i;

        }

    }

}

long long nextpowerof2(ll p)

{

    if(!(p&(p-1)))

    {

        return p;

    }

    return 0x8000000000000000>>(__builtin_clzll(p)-1);

}

*/

bool sortbysec(const pair<ll,ll> &a,

               const pair<ll,ll> &b)

{

    return (a.second < b.second);

}



int main() {

    fast;

     int q;

     cin>>q;

    while(q--)

    {

        int n,m;

        cin>>n>>m;

        int counter=0;

        int v[n+1][m+1];

        for(int i=0;i<n;i++)

        {

            for(int j=0;j<m;j++)

            {

                char c;

                cin>>c;

                v[i][j]=c-'0';

                counter+=v[i][j];

            }

        }

        int check=0;

        for(int i=0;i<n-1;i++)

        {

            for(int j=0;j<m-1;j++)

            {

                if(v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1]<=2)

                {

                    check=1;

                }

            }

        }

       if(check==1)

       {

           if(counter==0)

           {

               cout<<0<<endl;

           }

           else

           {cout<<counter<<endl;}

       }

        else if(check==0)

        {

            if(counter==n*m)

            {

                cout<<counter-2<<endl;

            }

           else if(counter==0)

            {cout<<0<<endl;}

            else

            {

                cout<<counter-1<<nl;

            }

        }



    }





}