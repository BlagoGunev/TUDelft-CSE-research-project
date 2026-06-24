#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <deque>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep( i , a , b )  for( int i = (a) ;   i <= (b) ; ++i)
#define foreach(c , itr) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
#define SZ(x) (int)x.size()
#define LEN(x) (int)x.length()

typedef long long int64 ;  
typedef pair<int,int>  pii ;  

int64 dp[ 1<<16 ]  ;  
int p[ 20 ];  
int  adj[20 ]  ;
bool used[ 20 ] ;    
int mat[ 20 ][ 20 ] ;  
int n ,  m ; 
int64 y ;    

#define two(x)   ((1)<<(x))
int64 gao() {  
    memset(dp, 0,sizeof(dp)) ; 
    dp[0]= 1 ;  

    for( int i = 0 ;  i < (1<<n) ; ++i) {  
            
        if( dp[ i ] == 0 ) continue ;      
        int t = __builtin_popcount( i )  ;   
        if( dp[ i ] == 0 ) continue ;  
        for( int j=0 ;  j < n ;  ++j) {      
            if(   two(j) &i ) continue ;    
            
            if( p[ j ] == t ) {   
                int c = (i&adj[j]) ;        
                if( c != 0) continue ;
                dp[ i^ two(j)] += dp[ i ] ;   
            } else if( p[ j ] ==-1) {    
                int c = ( i&adj[j] ) ;  
                if( c !=0 ) continue  ;  
                dp[ i^ two(j)] += dp[ i ]; 
            }  
        }   
                    
            
        
    }  
    return dp[(1<<n) -1] ; 
}


int main () {     
    
    for( ; cin >> n >> y >> m ;  ) {  
            memset( mat, 0 , sizeof(mat)) ;   
            for( int i=0 ; i < n ; ++i) {  
                adj[ i ] = 0  ; 
            }   
            for( int  i = 1; i <= m ; ++i) {   
                 
                int u, v ; 
                cin >> u >> v ; 
                --u, --v ;        
                mat[ u ][ v ] =1 ;  
            }     
            y -= 2000;   
            for( int k=0 ;k <n  ; ++k) { 
            for( int i= 0 ; i < n  ; ++i) { 
                for( int j=0 ; j < n  ;  ++j) {  
                    
                  mat[ i ][j] |=(  mat[ i ][ k] && mat[ k ][j] ) ; 
                }  
            }
            }  
            bool f= 0 ; 
            for( int i= 0; i <n  ; ++i){ 
                for( int j=0; j <n ; ++j) {   
                   if( mat[ i ][ j ]  ==1 && mat[ j][i] == 1) {  
                        f=1 ; 
                   } 
                } 
            } 
            if( f ) {  
                cout <<"The times have changed"<<endl ; 
                continue; 
            }     
           // cout <<"bug"<<endl;   
            for( int i=0 ; i < n  ; ++i){  
                for( int j=0; j <n  ; ++j) {   
                    if(mat[i][j] ) { 
                        adj[i]|= (1<<j) ; 
                    }  
                } 
            }   
            memset( p , 0xff, sizeof(p) );   
            memset( used, 0 , sizeof(used)) ;   
            for( int i=0 ; i < n ; ++i) {  
                int64 tot = 0  ;          
                
                for ( int j= 0 ;  j < n ;  ++j ) {  
                    if( used[ j ] ) continue ;  
                    p[ i ] = j  ;   
                    int64 xx = gao() ; 
                    if(tot +xx   >= y ){ 
                        f= 1;   
                        y-=tot; 
                        used[ j ] = 1 ; 
                        break ; 
                    }       
                    tot+=xx; 
                    //y -=tot ;      
                //  if( f == 0 ) break ;    
                }   
                if( f == 0 ) break ;    
            }    
            if( f == 0 ) {  
                cout <<"The times have changed"<<endl ; 
                continue; 
            }   
            for( int i=0 ; i < n ; ++i) {  
                if( i == n-1 ) {  
                    cout<< p[i] + 1 <<endl ; 
                } else {  
                    cout << p[i] + 1 <<" " ; 
                } 
            }     
    }  
    return 0 ; 
}