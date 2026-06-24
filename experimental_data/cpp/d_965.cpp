#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <math.h>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/** In set, multiset ,map etc the concept of index
    does not exist. */

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

/** find_by_order(int k) -> iterator to kth largest element
    order_of_key(int e)  -> position of element with
    value 'e' ie. number of elements less strictly less than e */

int mod=1000000007;

int powmod(int64_t a,int64_t b){
int64_t ans=1;while(b>0){if(b&1){b--;ans=(ans*a)%mod;}
else{a=(a*a)%mod;b=b>>1;}}return ans;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout<<fixed;
    ///learn from your mistakes
    ///read the question properly
    int w,l;
    cin>>w>>l;
    vector <int> arr(w);
    int sum=0;
    for(int i=0;i<w-1;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    arr[w-1]=sum;
    vector <int> dp(w,0);
    int ptr=0;
    for(int i=0;i<l;i++){
        dp[i]=arr[i];
    }
    for(int i=l;i<w;i++){
        if(i-l>ptr){
            ptr=i-l;
        }
        while(ptr<i && dp[i]<arr[i]){
            if(dp[ptr]>=(arr[i]-dp[i])){
                dp[ptr]-=arr[i]-dp[i];
                dp[i]=arr[i];
                break;
            }
            dp[i]+=dp[ptr];
            ptr++;
        }
    }
    cout<<dp[w-1];
    return 0;
}