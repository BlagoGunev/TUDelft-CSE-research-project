#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(),x.end()
#define mp make_pair

#define ll long long
#define ld long double
#define pb push_back

#define mod 1000000007

#define pi 2*acos(0)
#define F first
#define S second

#define fast_io ios_base::sync_with_stdio(0);cin.tie(NULL)
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
int main(){
  ll nb,nd,ns;
  cin>>nb>>nd>>ns;
  if(nb==nd && nd==ns){
    cout<<"0"<<endl;
    return 0;
  }
  ll d = max(nb,max(nd,ns));

  if(d==ns){
    if(nb==ns||nd==ns){
      cout<<3*(d-1)+2-nb-nd-ns<<endl;
    }
    else{
      cout<<3*(d-1)+1-nb-nd-ns<<endl;
    }
    return 0;
  }
  else if(d==nb){
    if(nb==ns||nb==nd){
      cout<<3*(d-1) + 2 - nb - nd - ns<<endl;
    }
    else{
      cout<<3*(d-1)+1-nb-nd-ns<<endl;
    }
  }
  else{
    if(nd==ns||nb==nd){
      cout<<3*(d-1) + 2 - nb - nd - ns<<endl;
    } 
    else{
      cout<<3*(d-1)+1-nb-nd-ns<<endl;
    }
  }
  return 0;
}