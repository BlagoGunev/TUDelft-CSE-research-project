#include <iostream>
#include <cstdio>
#include<map>
#include<cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include<string>
#include<utility>
#include<sstream>
#include<set>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Общий файл. 
#include <ext/pb_ds/tree_policy.hpp> // Содержит класс tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
#define MIN(X,Y) ((X) < (Y) ?  (X) : (Y))

#define MAX(X,Y) ((X) > (Y) ?  (X) : (Y))
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
}
const int MOD=1e9+7;
int m,n,k,q;
string s;
vector<vector<int>> dirs  = {{-1,0},{1,0},{0,-1},{0,1}};
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

using namespace std;
 
typedef long long int ll;
 
#define inf 1000000000
 
ll st_sum[800006];
ll st_seg[800006];
ll st_suf[800006];
ll st_pre[800006];


void build_sum(int at, int l, int r ,ll* arr){
    if (l==r){
        st_sum[at] = arr[l];
        st_seg[at] = arr[l];
        st_suf[at] = arr[l];
        st_pre[at] = arr[l];
    }
    else{
        int mid = l + (r-l)/2;
        build_sum(2*at + 1, l, mid ,arr);
        build_sum(2*at + 2, mid+1, r ,arr);
        st_sum[at] = st_sum[2*at + 1] + st_sum[2*at + 2];
        st_seg[at] = max(max(st_seg[2*at + 1], st_seg[2*at + 2]), st_suf[2*at + 1] + st_pre[2*at + 2]);
        st_suf[at] = max(st_suf[2*at + 2],st_suf[2*at + 1] +  st_sum[2*at + 2]);
        st_pre[at] = max(st_pre[2*at + 1], st_pre[2*at + 2] + st_sum[2*at + 1]);
    }


}

void update_single(int at, int l, int r, int idx, int val){
    if (l==r && l==idx){
        st_sum[at] = val;
        st_seg[at] = val;
        st_suf[at] = val;
        st_pre[at] = val;
    }
    else{
        int mid = l + (r-l)/2;
        if (idx <= mid)
            update_single(2*at + 1, l,mid,idx,val);
        else
            update_single(2*at + 2, mid+1, r,idx,val);
        st_sum[at] = st_sum[2*at + 1] + st_sum[2*at + 2];
        st_seg[at] = max(max(st_seg[2*at + 1], st_seg[2*at + 2]), st_suf[2*at + 1] + st_pre[2*at + 2]);
        st_suf[at] = max(st_suf[2*at + 2],st_suf[2*at + 1] +  st_sum[2*at + 2]);
        st_pre[at] = max(st_pre[2*at + 1], st_pre[2*at + 2] + st_sum[2*at + 1]);  
    }
}

// ll query_sum(int at, int l, int r, int ql, int qr){
//     if (l==r && l >= ql && r <= qr)
//         return st_sum[at];
//     else if (l>r || l > qr || r < ql)
//         return 0;
//     else if (qr>=r && ql <= l)
//         return st_sum[at] ;        
//     else {
//         int mid = l + (r-l)/2;
        
//         return query_sum(2*at+1, l, mid, ql, qr) + query_sum(2*at + 2, mid+1,  r, ql, qr);
//     }
    

//     }
 
 
int main() {
	//setIO("max_01");
    int total;
    
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> total;
    int x;
    for (int iii =0; iii < total; iii ++){
    cin >>n >> k>>x;
    ll arr[n];

    if (x < 0){
        k = n-k;
        x = -x;
    }
    
    for (int i =0; i < n; i++)
        cin >> arr[i];
    build_sum(0, 0, n-1 ,arr);


    for  (int i =0; i < k; i++)
        update_single(0,0,n-1,i,arr[i] + x);
    for  (int i =k; i < n; i++)
        update_single(0,0,n-1,i,arr[i] - x);
            
    
    ll mx = 0;
    mx = max(st_seg[0],mx);
    for (int i =k; i < n; i++)
        {
            
            update_single(0,0,n-1,i,arr[i] + x);
            update_single(0,0,n-1,i-k,arr[i-k] - x);
            mx = max(st_seg[0],mx);
 
      
        }
    cout << mx << endl;
    }
}