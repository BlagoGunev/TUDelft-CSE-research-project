#include<bits/stdc++.h>       

using namespace std;          

#define int long long  

#define fr(i, a, b) for (int i = a; i < b; i++)   

#define frr(i, a, b) for (int i = a; i >= b; i--)  

#define pb push_back      

#define lld long double       

//#define M 1000000007       

#define pr pair<int,int>       

#define timetaken cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n"       

//int oo=999999999999999990;

// prime number finder



vector<int>prime;

void sieve(int n)

{

   prime.resize(n);

   fr(i,0,n)

   prime[i]=i;



    for (int i=2; i*i<n; i++)

    {

        if (prime[i]==i)

        {

            for (int j=i*i; j<n; j+=i)

                if (prime[j]==j)

                    prime[j]=i;

        }

    }

}



void solve()

{

   int n,k;

   cin>>n>>k;



   int arr[n];

   fr(i,0,n)

   cin>>arr[i];

   set<int>s;

   int ans=1;

   for(int i=0;i<n;i++)

   {

      unordered_map<int,int >m;

      int x=arr[i];

      while(x!=1)

      {

         m[prime[x]]++;

         x/=prime[x];

      }



      int pro=1;

      for(auto it:m)

      {

         if(it.second%2)

            pro*=it.first;

      }

      if(s.find(pro)!=s.end())

      {

         ans++;

         s.clear();

      }

      s.insert(pro);

   }

   cout<<ans;

}



int32_t main()

{

    ios_base::sync_with_stdio(false);  cin.tie(NULL);

    sieve(10000001);

    int t;

    cin>>t;

    while(t--)

    {

        solve();

        cout<<"\n";

    }

    timetaken;

}