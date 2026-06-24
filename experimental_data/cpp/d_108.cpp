#include <stdio.h>

#include <iostream>

#include <vector>

#include <cmath>

#include <map>

#include <algorithm>

#include <set>

#include <string.h>

#include <queue>

#include <xmmintrin.h>

#include <ctime>

#include <cstdlib>

using namespace std;

#define ll long long

#define pll pair<ll,ll>

#define pii pair<int,int>

inline void read(int &x){char c=getchar();while(c<'0')c=getchar();x=c-'0';c=getchar();while(c>='0'){x=x*10+c-'0';c=getchar();}}

ll powmod(ll a,ll n,ll m){ll r=1;for(;n;a=a*a%m,n>>=1)if(n&1)r=r*a%m;return r;}

int gcd(int a,int b){

return b?gcd(b,a%b):a;

}

#define MD 1000000007





int d[1001];

int main(){

srand(time(0));

 int n,m,h;

 cin>>n>>m>>h;

 int sum=0;



 for(int i=1;i<=m;i++){

  cin>>d[i];

  sum+=d[i];

 }





  if(sum<n){

    cout<<-1<<endl;

    return 0;

  }

  double s=1;

  for (int i=1;i<n;i++) s=s*(sum+1-d[h]-i)/(sum-i);



  cout.precision(8);

  cout<<fixed;

  cout<<1-s<<endl;

	return 0;

}

/*

6

1 0 1 0 1 0

0 1 0 1 0 1

1 0 1 0 1 0

0 1 0 1 0 1

1 0 1 0 1 0

0 1 0 1 0 1

*/