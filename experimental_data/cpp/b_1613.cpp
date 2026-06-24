/*
        Author ::  _mak_ 
*/

#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define pb            push_back
#define eb            emplace_back
#define rep(i,a,n )   for( int i=a;i<n;i++)
#define all(v)        v.begin() , v.end()
#define gcd(a,b)      __gcd(a,b);
#define lb            lower_bound
#define ub            upper_bound
#define cnu           continue
#define ss             second
#define ff             first
#define MM            1000000007
#define PI            3.1415926535
typedef pair < int , int  > pii ;
typedef pair < ll , ll >  pll ;  
typedef vector < int >   vi ; 
typedef vector < ll >    vl ; 




int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);      
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t ; cin>>t;
    while( t-- ){
        int n ; cin>>n;
        vector < int > a(n,0);
        rep( i , 0 , n ){
            cin>>a[i];
        }
        sort(all(a)); 
        int c = n/2;
        
        for( int i = 1 ; i <= c ; i++ ){
            cout<<a[i]<<' '<<a[0]<<'\n'; 
        }

    }


    
return 0;
}