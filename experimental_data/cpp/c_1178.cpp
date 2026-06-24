#include<bits/stdc++.h>
#define ll long long
#define max 998244353
using namespace std;

int main(){
   ll int w,h;
   cin>>w>>h;
   ll int pw = w + h,prod = 1;
   for(ll int i=0; i< pw; i++){
      prod = prod*2;
      prod = (prod%max);
   }
   cout<<prod;


return 0;
}