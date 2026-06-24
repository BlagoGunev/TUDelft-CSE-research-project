//Burn like amaterasu

//compete 

#include <bits/stdc++.h>

#define ll long long

#define f(i,a,b) for(i=a;i<b;i++)

#define fr(i,a,b) for(i=a;i>=b;i--)

#define Yes cout<<"YES\n"

#define yes cout<<"Yes\n"

#define No cout<<"NO\n"

#define no cout<<"No\n"

#define vll vector<ll>

#define vi vector<int>

#define pb push_back

#define srt(v) sort(v.begin(),v.end())

#define rst(v) sort(v.rbegin(),v.rend())

int mod=1e9+7;

using namespace std;



//**********************************************************************G.C.D***********************************************************************************

ll gcd(ll high,ll low)

{

high=high>low?high:low;

low=high>low?low:high;

while(low!=0)

{

   ll temp=low;

   low=high%low;

   high=temp;

}

return high;

}

//**************************************************************************************************************************************************************



//**********************************************************************x to the power n (Binpow)***************************************************************

ll binpow(ll x,ll n)

{                   

    ll r=1;

    while(n)

    {

        if(n&1)

        r=r*x;

        x=x*x;

        n>>=1;

    }

    return r; 

}

//**************************************************************************************************************************************************************



//**********************************************************************Fenwick Tree/Binary Indexed Tree********************************************************

template<class T>

class fenwick_tree

{ 

 private:

 vector<T> tre;

 public:

 fenwick_tree(T n)

 {

   tre.resize(n+1);

 }

 void add(T index,T value)

 {

    for(;index<=tre.size()-1;index+=(index&(-index)))

    tre[index]+=value;

 }

 T sum_i(T index)

 {

     T ans=0;

     for(;index>0;index-=(index&(-index)))

     ans+=tre[index];

     return ans;

 } 

}; 

//**************************************************************************************************************************************************************



template <typename T>

inline void pr_v(vector<T>& b){ ll i;f(i,0,b.size()){ cout << b[i] <<" ";}cout <<"\n";}

template <typename T>

inline void pr_a(T *arr,ll n){ll i;f(i,0,n){cout<<arr[i]<<" ";}cout<<"\n";}



//**********************************************************************Solution Begins***************************************************************************



void solve_Func()

{

   ll i, j, k, l, n, m;

   cin>>n>>m;

   char a[n][m];



   f(i,0,n)

   f(j,0,m)

   cin>>a[i][j];



   char b[m][n];



   f(i,0,m)

   f(j,0,n)

   b[i][j]=a[j][i];

    

   f(i,0,m)

   {

      int ind=0;

      f(j,0,n)

      { 

         if(b[i][j]=='.')

         {

             fr(k,j,ind+1)

             {   

                 b[i][k]=b[i][k-1];

             }

             b[i][ind]='.';

         }

         else if(b[i][j]=='o')

         ind=j+1;

      }

   }

   f(i,0,n)

   f(j,0,m)

   a[i][j]=b[j][i];



   f(i,0,n)

   {

   f(j,0,m)

    cout<<a[i][j];

    cout<<"\n";

   }

    

}







int main()

{

   ios_base::sync_with_stdio(false);

   cin.tie(NULL);



     ll t;



    cin>>t;

    while(t--)

       solve_Func();



}



//*********end*********//