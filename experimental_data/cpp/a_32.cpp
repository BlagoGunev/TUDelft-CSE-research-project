#include <bits/stdc++.h>

using namespace std;



#define rep(i,b,e) for(int i=b; i<e; i++)

#define pc(i) cout<<"Case "<<i<<": "  ///  Case 1: bla bla bla



///data type

typedef unsigned long long int ull;

typedef long long int ll;

typedef long double ld;



///constant

#define PI acos(-1)



///container

typedef pair<int, int> P;

#define F first

#define S second

#define R real

#define I imag

#define ST set<int>

#define V vector<int>

#define C complex<int>

#define M map<int,int>

#define MP map<P,int>

#define SI ST::iterator

#define MI M::iterator

#define VI V::iterator



///funcction

#define max3(a,b,c) max(a,max(b,c))



ll pow(ll x,ll y){

    ll pod = 1;

    for(ll myrala=0; myrala<y; myrala++)pod*=x;

return pod;}



struct name{

    int v, p;

}a [105];





int binary_search(name A [],int lo,int hi,int target){

   while (lo <= hi){

      int mid = (lo + hi)/2;

      if (A[mid].v == target)

         return A[mid].p+1;

      else if (A[mid].v < target)

         lo = mid+1;

      else

         hi = mid-1;

   }

   return 0;

}















bool sad (name a,name b){

    return a.v<b.v;

}



int main (){

    ///freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    ios_base :: sync_with_stdio(false);

    ll n, d, cnt=0;

    cin>>n>>d;

    ll a[n];

    rep(i,0,n)cin>>a[i];

    rep(i,0,n-1)rep(j,i+1,n){



        if(abs(a[i]-a[j])<=d)cnt++;

    }

    cout<<2*cnt<<endl;

return 0;}