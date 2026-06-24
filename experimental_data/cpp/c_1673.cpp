#include<bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long

#define rep(i,n) for (ll i = 0; i < n; i++)

#define frev(i, x, y) for (ll i = x - 1; i >= y; i--)

#define feach(x, y) for (auto &x : y)

#define fsq(i, x, y) for (ll i = x; i*i<=y; i++)

#define vl vector<ll>

#define vp vector<pair<ll,ll>>

#define mapl map<ll,ll>

#define mapc map<char,ll>

#define all(v) v.begin(), v.end()

#define backk(v) v.rbegin(), v.rend()

#define pb push_back

#define pf push_front



#define fr first

#define sc second

#define maxv(v) *max_element(v.begin(), v.end())

#define minv(v) *min_element(v.begin(), v.end())

#define mod 1000000007

#define  pie 3.141592653589793238

#define endl "\n"

const int N=4e4+10;

int dp[40010][502];

int arr[502];

ll binpow(ll a,  ll b,ll m) {

    ll res = 1;

    while (b > 0) {

        if (b & 1)

            res = (res * a)%m;

        a = (a * a)%m;

        b >>= 1;

    }

    return res;

}

int reverse(int n)

{

    int r=0;

    while(n>0)

    {

        r=r*10+n%10;

        n/=10;

    }

    return r;

}

bool palindrome(int n)

{

    return (reverse(n)==n); 

}











// int func(int index,int amount){

//     if(amount==0) return 1;

//     if(index<0) return 0;

    

// if(dp[index][amount]!=-1) return dp[index][amount];

// int ways=0;

//     for(int no_used=0;no_used<=amount;no_used+=arr[index]){

//       ways=(ways+(func(index-1,amount-no_used))%mod)%mod;

//     }

//    return  dp[index][amount]=ways%mod;





// }







void solve(){



int amount;

cin>>amount;

cout<<dp[amount][499]%mod<<endl;







    

       

















}









































int main(){

 ios_base::sync_with_stdio(false);

   cin.tie(NULL);



int k=0;

arr[0]=0;

k++;

for(int i=1;i<N;i++){

      if(palindrome(i)){

            arr[k]=i;

            k++;

      }

}



for(int j=1;j<=500;j++){

    dp[0][j]=1;

}

for(int i=1;i<N;i++){

    dp[i][0]=0;

}



    for(int i=1;i<N;i++){

        for(int j=1;j<500;j++){

        if(i-arr[j]>=0)

        dp[i][j]=((dp[i][j-1])+(dp[i-arr[j]][j]))%mod;

    

    else{

        dp[i][j]=dp[i][j-1];

    }

}

}







 int t;

cin>>t;

while(t--){

  

solve();

}

return 0;

}