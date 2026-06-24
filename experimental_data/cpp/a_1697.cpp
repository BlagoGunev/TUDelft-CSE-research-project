#include <bits/stdc++.h>

using namespace std;

#define start int main(){

#define finish return 0;}

#define vi vector<int>

#define pii pair<int,int>

#define pb push_back

#define all(X) (X).begin(), (X).end()

#define spc " "

typedef long long int lli;

int factorial(lli n) {

      if(n == 0)

      return 1;

    lli factorial = 1;

    for (int i = 2; i <= n; i++)

        factorial = factorial * i;

    return factorial;

}

 

long long int nCr(int n, int r) {

    return factorial(n) / (factorial(r) * factorial(n - r));

}



void solve(){

        int n,m;

        cin>>n>>m;

        int a[n];

        for(int i=0;i<n;i++){

                cin>>a[i];

        }

        int sum=0;

        sum=accumulate(a,a+n,sum);

        if(sum>m){

                cout<<sum-m<<endl;

        }

        else

                cout<<"0"<<endl;

        

}

        start;

        int t;

        cin>>t;

        while(t--)

        solve();

        

      finish ;