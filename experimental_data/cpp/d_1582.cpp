#include <bits/stdc++.h>

using namespace std;

#define nn "\n"

#define x_x ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define intt int t; cin>>t; while(t--)

#define emp emplace_back

#define mod 1000000007

#define all(v) v.begin(), v.end()

typedef long long ll;



int main()

{

   x_x

intt

{

   int n; cin>>n; ll ar[n],sm=0;

   for(ll&i:ar)cin>>i;

   if(n%2==0)

   {

       for(int i=0; i<n; i+=2)

       {

           cout<<ar[i+1]<<' '<<-ar[i]<<' ';

       }

       cout<<nn;

   }

   else

   {

     for(int i=0; i<(n-3); i+=2)

       {

           cout<<ar[i+1]<<' '<<-ar[i]<<' ';

       }

       if((ar[n-3]+ar[n-2])!=0)cout<<-ar[n-1]<<' '<<-ar[n-1]<<' '<<ar[n-3]+ar[n-2]<<nn;

       else if((ar[n-3]+ar[n-1])!=0)cout<<-ar[n-2]<<' '<<ar[n-1]+ar[n-3]<<' '<<-ar[n-2]<<nn;

    else cout<<ar[n-1]+ar[n-2]<<' '<<-ar[n-3]<<' '<<-ar[n-3]<<nn;

   }

}

    return 0;

}

/*

mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());



int genRand(int l, int r) {

    return uniform_int_distribution <int> (l, r) (rng);

}*/