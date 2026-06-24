#include <bits/stdc++.h>

using namespace std;



#define iofast() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define ff first

#define ss second

#define all(v) v.begin(),v.end()

#define bipc(x) __builtin_popcountll(x)



#define yes cout << "YES\n"

#define no cout << "NO\n"

#define ccase(t) "Case #" << t << ": "

#define clz(x) __builtin_clz(x);

using ll = long long;



const int N = (int)1e5 + 10;

const int inf = (int)1e9+10;

const int M = (int)1e9 + 7;





int sz;

int fr[N],bk[N];

pair<int,int> a[N];

int val[N];



bool chk(double mid){

  int i = upper_bound(val,val+sz,mid) - val;

  double mx1=0,mx2=0;

  if(i) mx1 = fr[i-1] + mid;

  if(i!=sz) mx2 = bk[i] - mid;

  return mx1 > mx2;

}



double getval(double x){

  int i = upper_bound(val,val+sz,x) - val;

  double mx=0;

  if(i) mx = max(mx,fr[i-1] + x);

  if(i!=sz) mx = max(mx,bk[i] - x);

  return mx;

}



void build(){

  for(int i=1;i<sz;++i) fr[i] = max(fr[i],fr[i-1]);

  for(int i=sz-2;i>=0;--i) bk[i] = max(bk[i],bk[i+1]);

}



void RadheRadhe(int tt,bool kavya2719 = 1){

   cin >> sz;

   for(int i=0;i<sz;++i) cin >> a[i].ff;

   for(int i=0;i<sz;++i) cin >> a[i].ss;

   

   sort(a,a+sz);

   for(int i=0;i<sz;++i) val[i] = a[i].ff;

   for(int i=0;i<sz;++i){

     int t = a[i].ss;

     fr[i] = t-a[i].ff; bk[i] = t+a[i].ff;

   }

   build();

   

   double lo=0,hi=(int)1e8+10;

   double eps = 1e-6;

   while(hi-lo > eps){

     double mid = (hi+lo)/2;

     if(chk(mid)) hi=mid;

     else lo=mid;

   }

   if(getval(lo) > getval(hi)) lo=hi;

   cout << lo << "\n";

}





void phle_ka_kaam(){

   

}





int main()

{

    iofast();

    //phle_ka_kaam();

    cout << fixed << setprecision(6);

    

    int TTTT=1;

    cin >> TTTT;

    for(int i=1;i<=TTTT;i++)

       RadheRadhe(i);

}