#include <bits/stdc++.h>
         #define fio             ios_base::sync_with_stdio(false),cin.tie(NULL)
         #define ll              long long int
         #define ld              long double
         #define f(a,b)          for(int i=a;i<b;i++)
         #define in(a,b)         (b.find(a) != string::npos)
         #define X               first
         #define Y               second
         #define fill(a,x)       memset(a,x,sizeof(a))
         #define pb              push_back
         #define pf              push_front
         #define mp              make_pair
         #define all(v)          v.begin(),v.end()
         #define el              "\n"
         const ll M = 1e9 + 7;
    using namespace std;
   int main(){
       fio;
       ll q;
       cin>>q;
       ll n,m,k,mn=INT_MAX,mx=INT_MIN,move,x;
       while(q--){
           cin>>n>>m>>k;
           if((n%2==0 && m%2==0 )||(n%2!=0 && m%2!=0)){
               x=max(n,m);
           }
           else{
               x=max(n,m)-1;
           }
           move=max(n,m);
           if(k<move){
               cout<<-1<<el;
               
           }
           else if(k==move)cout<<x<<el;
           else{
               if((k-move)%2==0)cout<<x+k-move<<el;
               else{
                   if(x==max(n,m))cout<<k-2<<el;
                   else cout<<k-1<<el;
               }
           }
       }
       return 0;
   }