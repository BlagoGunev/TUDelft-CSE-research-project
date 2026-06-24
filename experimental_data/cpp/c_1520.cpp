#include <bits/stdc++.h>
using namespace std;
typedef long long l;
#define  f(n)    for(l i =0; i <n; i++)
#define  f1(m)    for(l j =0; j <m; j++)
#define  newl           cout<<"\n";
#define cases()   l t;cin>>t;while(t--)
#define  ff             first
#define  ss             second
#define  pb             push_back
#define  mp             make_pair
#define  pl           pair<l,l>
#define  vl           vector<l>
#define mll        map<l,l>
#define mlv       map<l,vector<l>>
#define  mvl       map<vl,l>
#define all(a)           a.begin(),a.end()
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define MOD              1000000007
#define ms(a,b)          memset(a, b, sizeof(a))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define maxi(a) *max_element(a,a+n)
#define mini(a) *min_element(a,a+n)
#define no cout << "No" << endl
#define yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define bp(x) __builtin_popcountll(x)
#define mxheap    priority_queue<int>
#define mnheap    priority_queue<int,vector<int>,greater<int>>
#define SPEED ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
//**Akshith Reddy**

int main()
{
    SPEED;
   cases(){
       l n;
       cin>>n;
       if(n==1){
           cout<<"1\n";
       }
       else if(n==2){
           cout<<"-1\n";
       }
       else{
           l a[n][n];
           l x=1,y=2;
           for(l i=0;i<n;i++){
               for(l j=0;j<n;j++){
                   if(x<=n*n){
                       a[i][j]=x;
                       x+=2;
                   }
                   else{
                       a[i][j]=y;
                       y+=2;
                   }
               }
           }
           f(n){
               f1(n){
                   cout<<a[i][j]<<" ";
               }
               cout<<endl;
           }
       }
   	










   }
}