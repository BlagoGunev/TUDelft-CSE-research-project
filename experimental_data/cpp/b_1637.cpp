#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/resize_policy/hash_standard_resize_policy_imp.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define lui long unsigned int


const int N = 5000005;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const ll INF = 1e18;


// sahil will become candidate master in couple of months  and 6* on codechef




long long binpow(long long a, long long b, long long m) {
    a %= m;

    long long res = 1;

    while (b > 0) {

        if (b & 1)

            res = res * a % m;

        a = a * a % m;

        b >>= 1;
    }

    return res;
}



int gcd_equation(int a, int b, int& x, int& y) {

    x = 1, y = 0;

    int x1 = 0, y1 = 1, a1 = a, b1 = b;

    while (b1) {

        int q = a1 / b1;

        tie(x, x1) = make_tuple(x1, x - q * x1);

        tie(y, y1) = make_tuple(y1, y - q * y1);

        tie(a1, b1) = make_tuple(b1, a1 - q * b1);

    }

    return a1;
}

void prime_generator(vector<bool> &is_prime)
{


 int n=N;

 is_prime.resize(n);

 fill(is_prime.begin(),is_prime.end(),true);




is_prime[0] = is_prime[1] = false;

for (int i = 2; i * i <= n; i++) {

    if (is_prime[i]) {

        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;

    }
}

}

void lowest_prime_factor(vector<int> &lp)
{


 int n = 10000000;

 lp.resize(n+1);

 fill(lp.begin(),lp.end(),0);


vector<int> pr;

for (int i=2; i <= n; ++i) {

    if (lp[i] == 0) {

        lp[i] = i;
        pr.push_back(i);
    }


    for (int j=0; j < (int)pr.size() && pr[j] <= lp[i] && i*pr[j] <= n; ++j) {


        lp[i * pr[j]] = pr[j];


    }
}


}

void ncr(int n,vector<ll> &factorial,vector<ll> &facinv)
{



         factorial[0]=1;

         for(ll i=1;i<=n;i++)
         {

              factorial[i]=factorial[i-1]*i;

              factorial[i]%=MOD;
         }

         ll modinv=binpow(factorial[n],MOD-2,MOD);

         facinv[n]=modinv;

         for(ll i=n-1;i>=0;i--)
         {

              facinv[i]=facinv[i+1]*(i+1);

              facinv[i]%=MOD;

         }


}


bool cycle_dectector_dg(int s,vector<int> adj[],vector<int> &vis)
{
       vis[s]=1;
       for(auto child:adj[s])
       {
              if(vis[child]==0)
              {
               if(cycle_dectector_dg(child,adj,vis))return true;
              }
              else if(vis[child]==1)return true;
       }
      vis[s]=2;
      return false;
}

bool cycle_dectector_ug(int s,int par,vector<int>adj[],vector<int> &vis)
{
      vis[s]=1;
      for(auto child:adj[s])
      {
           if(child==par)continue;

           if(vis[child])return true;
           else
           {
            if(cycle_dectector_ug(child,s,adj,vis))return true;
           }
      }
    return false;
}

bool is_bipartite(int s,vector<int> &vis,vector<int> adj[],vector<int> &col,int curr,int &one,int &sz)
{

      col[s]=curr;

      sz+=1;



      if(curr==1)
        one+=1;


      vis[s]=1;

      for(auto child:adj[s])
      {

          if(vis[child])
          {
               if(col[child]==col[s])
                return false;
          }
          else
          {
              if(is_bipartite(child,vis,adj,col,(curr^1),one,sz)==false)
                return false;

          }
      }

       return true;
  }






int solve(vector<int> &arr)
{


       int n=arr.size();





        int ans=0;

        int res=0;



        int mex=0;

        set<int> s;


        for(int i=0;i<n;i++)
        {

              int prev=mex;


              s.insert(arr[i]);

              while(s.count(mex))
              {

                   mex+=1;
              }


             int new_mex;

             if(arr[i]==0)
             {
                new_mex=1;
             }
             else
                new_mex=0;


            int temp1=ans+mex;
            int temp2=ans+prev+1+new_mex;


            if(mex<new_mex+1+prev)
            {
                
                 ans+=prev;

            

                 ans+=1;

                 mex=new_mex;

                 s.clear();

                 s.insert(arr[i]);

              
             }
              

            // cout<<ans+mex<<endl;

             res+=(ans+mex);


            }



            


             // cout<<res<<endl;
            return res;
}



int main()
{
 

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int test;test=1;
cin>>test;  

while(test--)
{    
   
              

   


        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }


       int ans=0;

       for(int i=0;i<n;i++)
       {

           vector<int> v;

           for(int j=i;j<n;j++)
           {
               v.push_back(arr[j]);

        

           }

           ans+=solve(v);
       }

       cout<<ans<<endl;



      




       



     


}

   clock_t time_req = clock();

   // cout<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

return 0;
      
         
     
}