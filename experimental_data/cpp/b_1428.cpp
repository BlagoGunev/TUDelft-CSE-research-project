/**

 * Surly

 * 09.08.2022

**/



#include<bits/stdc++.h>

 

#define pb push_back

#define nw cout<<"\n";

#define all(v) v.begin(),v.end()

#define allr(v) v.rbegin(),v.rend()

#define srt(v) sort((v).begin(),(v).end())

#define rvrs(v) reverse((v).begin(),(v).end())

#define mpr make_pair

#define mt make_tuple

#define loop(i,j,n) for (int i = j; i < n; ++i)

#define loop1(i,j,n) for(int i=j;i<=n;++i) 

#define wis(x) std::cerr << #x << " is " << x << std::endl;





using namespace std;

  

typedef int_fast64_t ll; 

typedef vector<int> vi;

typedef vector<ll> vll;

typedef deque<int> dqi;

typedef deque<ll> dqll;

 

#ifndef ONLINE_JUDGE

#include "debug.hpp"

#endif

 

template<typename type>

istream& operator>>(istream& istream , deque<type> &v) {

  if(v.size()) {

   for(auto &i : v)

    cin>> i;

  }

  else {

    char c;

    cin>> c;

    if(c!=10)

     cin.unget();

     

   string str;

  getline(cin , str);

  

  stringstream stream(str);

  type x;

  while(stream>>x) {

    v.pb(x);

   }

  }

   return istream;

} 



template<typename type>

ostream& operator <<(ostream& ostream , deque<type> &v) {
  for(auto i : v)

   cout<<i<<" ";

return ostream;
}







int main ( void )

{                 

                         time_t Time;

                          time(&Time);

                   cerr<<ctime(&Time);

             ios_base::sync_with_stdio(false);

               cin.tie(NULL),cout.tie(NULL);

               cout<<fixed<<setprecision(9);

    auto starttime=chrono::steady_clock::now();

    

   int t;

   cin>> t;

   

   auto sol = [&](){
    int n;

    cin>> n;

    string str;

    cin>> str;

    str+=str[0];

    bool cw = false , ccw = false;

    int res =0;

    for(int i=0;i<n;i++) {
     if(str[i]=='<')

      cw = true;

     if(str[i]=='>')

      ccw=true;
    }

    if(cw and ccw) {
     for(int i=0;i<n;i++) {
      if(str[i]=='-' or str[i+1]=='-')

       res++;
     }

     cout<< res;
    }

    else

     cout<< n;
   };

   

   while(t--) {
    sol();

    nw;
   } 

    

    auto endtime=chrono::steady_clock::now(); 

    cerr<<endl<<"Elapsed Time: "

       	 <<chrono::duration_cast<chrono::milliseconds> (endtime-starttime).count()

	      <<" milliseconds"<<endl;

    return 0;

 }