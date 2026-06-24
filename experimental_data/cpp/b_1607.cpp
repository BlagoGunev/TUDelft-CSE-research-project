#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define NL "\n"
#define all(x) (x).begin(), (x).end()
#define tc(x)  int x; cin >> x; while(x--)
#define forv(x,v) for(int i=0;i<x;i++) int y; cin>>y; v.push_back(y);
#define mp make_pair
#define pb push_back
#define forn(x) for(int i=0;i<x;i++)
#define vii vector<int>
#define vLL vector<long long>
using LL = long long;
using ull = unsigned long long int;
const int Monke = 0;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;}

void solve(){
  LL x0,n,ans=0,temp;
  cin>>x0>>n;
  ans=x0;
  if(n==0) {
   cout<<x0<<NL;
   return;
  }
  if(x0%2==0){
   if(n%2==0){
    if((n/2)%2==0)
    ans = x0;
    else ans= x0+1;
   }
   else {
      temp = n-1;
      if(n==1) ans -=1;
   else if((temp/2)%2==0 && temp!=0)
    ans = x0;
    else ans= x0+1;

    if(temp%4==0 && temp!=0) ans-=n;
    else if(n!=1) ans+=n;
   }
  }

  else {
    if(n%2==0){
    if((n/2)%2==0)
    ans = x0;
    else ans= x0-1;
   }

   else {
      temp = n-1;
       if(n==1) ans +=1;
      else if((temp/2)%2==0 && temp!=0)
    ans = x0;
    else ans= x0-1;

    if(temp%4==0 && temp!=0) ans+=n;
    else if(n!=1) ans-=n;
   }
  }
  cout<<ans<<NL; 
}

int main()
{
   fastio;
   tc(x)
   solve();
   return Monke;
}