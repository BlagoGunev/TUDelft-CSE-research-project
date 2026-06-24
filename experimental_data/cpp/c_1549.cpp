#include<bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long

#define all(x) x.begin(), x.end()

#define endl '\n'

#define T  ll t ; cin >> t; while(t--)

//const ll mod=1e9+7;

const int N=2e5+5;;

//ll fc[N],inv[N];

//ll mul(ll a,ll b)

//{

//    return (a*b)%mod;

//}

//ll add(ll a,ll b)

//{

//    return (a+b)%mod;

//}

//ll fp(ll b,int p)

//{

//    if(p==0)return 1;

//    ll x=fp(b,p>>1);

//    x=mul(x,x);

//    if(p&1)x=mul(x,b);

//    return x;

//}

//ll modInverse(ll n){

//    return fp(n,mod-2);

//}

//ll ncr(ll c,ll r){

//    return mul(fc[c], modInverse(mul(fc[c - r], fc[r])));

//}

//void pre(){

//    fc[0]=1;

//    inv[0]=1;

//    for (int i = 1; i <N; ++i)

//    {

//        fc[i]=mul(fc[i-1],i);

//    }

//}

//int bs(int s,int e,int k)

//{

//    int c=0;

//    while(e>=s)

//    {

//        int mid = s+(e-s)/2;

//        if(mid>k)

//            e=mid;

//        else if (mid<k)

//            s=mid+1;

//        else

//            break;

//        c++;

//    }

//    return c;

//}

int fr[N];

int main() {

    fast

    int n,r;

    cin>>n>>r;

    int ans=n;

    for (int i = 0; i < r; ++i)

    {

        int v,u;

        cin>>v>>u;

        if(v<u)

        swap(u,v);



            if(fr[u]>-1)

            {

                fr[u] = -1; ans--;

            }

            else

                fr[u]--;



    }

    int q;

    cin>>q;

    while(q--)

    {

        int c;

        cin>>c;

        if(c==1)

        {

            int v,u;

            cin>>v>>u;

            if(v<u)

                swap(u,v);



            if(fr[u]>-1)

            {

                fr[u] = -1; ans--;

            }

            else

                fr[u]--;

        }

        else if (c==2)

        {

            int v,u;

            cin>>v>>u;

           fr[min(v,u)]++;

           if(!fr[min(v,u)])

               ans++;

        }

        else

        {

            cout<<ans<<endl;

        }

    }

}