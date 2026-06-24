#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
//#define LOCAL 
#define MAXN 105
#define pr pair<int,int>

typedef unsigned long long int ll;

using namespace std;

namespace segtree{
   void build(int arr[],ll *st,int node,int l,int r){
      if(l == r){
         st[node] = arr[l];
         return;
      }
      
      int mid = (l+r)/2;
      int left = (node << 1) + 1;
      int right = (node << 1) + 2;
      build(arr,st,left,l,mid);
      build(arr,st,right,mid+1,r);
      st[node] = st[left] + st[right];
   }
   
   void update(int arr[],ll *st,int node,int l,int r,int index,ll value){
      if(l == r){
         st[node] = value;
         arr[index] = value;
         return;
      }
      
      int mid = (l+r)/2;
      int left = (node << 1) + 1;
      int right = (node << 1) + 2;
      if(index <= mid){
          update(arr,st,left,l,mid,index,value);
      }else{
          update(arr,st,right,mid+1,r,index,value);
      }
      
      st[node] = st[left] + st[right];      
   }
   
   ll query(ll *st,int node,int l,int r,int from,int to){
      if(l > to || r < from){
         return 0;
      }else if(l == r){
         return st[node];
      }else if(l >= from && r <= to){
         return st[node];
      }
      
      int mid = (l+r)/2;
      int left = (node << 1) + 1;
      int right = (node << 1) + 2;
      
      ll sum = query(st,left,l,mid,from,to) + query(st,right,mid+1,r,from,to);      
      return sum;
   }
}

int t,n,k;
ll arr[MAXN];
ll powers[64];
int visited[64],max_power;
const ll MAXX = 1e17;

bool _availble(ll v){
    for(int i = max_power;i >= 0;i--){
       if(v >= powers[i]){
          if(visited[i]){
             return 0;
          }else{
             visited[i] = 1;
             v -= powers[i];
             if(!v){
                break;
             }
          }
       }
    }
    
    return !v;
    
}

int main(){
#ifdef LOCAL
   freopen("in.txt","r",stdin);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
  
   cin >> t;
   while(t--){
      cin >> n >> k;
      for(int i = 0;i < n;i++) cin >> arr[i];
      bool flg = 0;
      max_power = 0;
      ll max_curr = 1;
      memset(visited,0,sizeof(visited));
      memset(powers,0,sizeof(powers));
      while(max_curr <= MAXX){
          powers[max_power] = max_curr;
          max_curr *= k;
          max_power++;
      }
      
      sort(arr,arr+n);
      max_power--;
      for(int i = 0;i < n;i++){
         if(arr[i] && !_availble(arr[i])){
            flg = 1;
            break;
         }
      }

      if(!flg){
        cout  << "YES" << endl;
      }else{
        cout  << "NO" << endl;
      }

   }
   
   
   return 0;
}