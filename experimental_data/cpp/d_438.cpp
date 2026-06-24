#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#define ms(x) memset(x,0,sizeof(x)) 
#define For(a,b,c) for(int a = b ; a <= c ; a ++ )
#define int64 long long 
#define real long double
#define SZ size()

int getint(){
    char ch = getchar() ; int ret = 0 ; bool flag = true ; 
    while(( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar() ; 
    if( ch == '-' ) flag = false , ch = getchar() ; 
    while( ch >= '0' && ch <= '9' ) ret = ret * 10 + ch - '0' , ch = getchar() ;  
    return flag ? ret : - ret ; 
}

using namespace std ; 

int64 sum[1000000] ;
int Max[1000000] ; 
int a[200000] , n , m ; 
int id[200000] ;

void build(int x , int L , int R){
    if(L == R) return (void)(id[L] = x , sum[x] = a[L] , Max[x] = a[L]) ;
   int mid = (L + R) >> 1 ;  
   build(x << 1 , L , mid) ; 
   build(x << 1 | 1 , mid + 1 , R) ; 
   sum[x] = sum[x << 1] + sum[x << 1 | 1] ; 
   Max[x] = max(Max[x << 1] , Max[x << 1 | 1]) ; 
}


void update(int x){
  Max[x] = max(Max[x << 1] , Max[x << 1 | 1]) ; 
  sum[x] = sum[x << 1] + sum[x << 1 | 1] ; 
}

void put(int x , int L , int R , int mo){
  if(L == R) return (void)(Max[x] = sum[x] = sum[x] % mo); 
  int mid = (L + R) >> 1 ; 
  if(Max[x << 1] >= mo) put(x << 1 , L , mid , mo) ; 
  if(Max[x << 1 | 1] >= mo) put(x << 1 | 1 , mid + 1 , R , mo) ; 
  update(x) ; 
}

void mod(int x , int L , int R , int Ls , int Rs , int mo){
   if(L > Rs || R < Ls) return ; 
   if(L >= Ls && R <= Rs){
     put(x , L , R , mo) ; 
     return ; 
   } 
   int mid = (L + R) >> 1 ; 
   mod(x << 1 , L , mid , Ls , Rs , mo) ; 
   mod(x << 1 | 1 , mid + 1 , R , Ls , Rs , mo) ; 
     update(x) ; 
}

void modify(int x , int V){
  x = id[x] ; 
  sum[x] = Max[x] = V ; 
  for(x = x >> 1 ; x ; x >>= 1) update(x) ; 
}

int64 query(int x , int L , int R , int Ls , int Rs){
   if(L > Rs || R < Ls) return 0 ; 
   if(L >= Ls && R <= Rs) return sum[x] ; 
   int mid = (L + R) >> 1 ; 
   int64 res = 0 ; 
   res += query(x << 1 , L , mid , Ls , Rs) ; 
   res += query(x << 1 | 1 , mid + 1 , R , Ls , Rs) ; 
   return res ; 
}

int main(){

     
   cin >> n >> m ; 
   for(int i = 1 ; i <= n ; i ++ ) scanf("%d",a + i) ; 
   build(1 , 1 , n) ; 
   int x , y , z ; 
   for(int i = 1 ; i <= m ; i ++ ){
     int cmd = getint() ;
     if(cmd == 1){
             scanf("%d %d",&x,&y) ; 
             printf("%I64d\n",query(1 , 1 , n , x , y)) ;
         }else if(cmd == 2){
             int x , y , z ; 
             scanf("%d %d %d",&x,&y,&z) ; 
             mod(1 , 1 , n , x , y , z) ;
         }else{
             scanf("%d %d",&x,&y) ; 
             modify(x , y) ;
         }    
   }
   return 0 ; 
}