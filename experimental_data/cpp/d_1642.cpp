#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>

#define ld long double
#define ll long long
#define ull unsigned long long
#define inf 1e9

using namespace std;

vector<int> segs;
vector<pair<int,int>> ans;

int go(int base, vector<int>& s){
    // cout<<base<<endl;
    // for(auto a:s){
    //     cout<<a;
    // }
    // cout<<endl;
    int n = s.size();
    if(n==0){
        return base;
    }
    for(int i=1;i<n;i++){
        if(s[i]==s[0]){
            for(int j=1;j<i;j++){
                ans.emplace_back(s[j],base+i+j-1);
            }
            segs.push_back(base);
            vector<int> next;
            for(int k=i-1;k>=1;k--){
                next.push_back(s[k]);
            }
            for(int k=i+1;k<n;k++){
                next.push_back(s[k]);
            }
            return go(base+2*i,next);
        }
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> counts;
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        counts[arr[i]]++;
    }
    for(auto a:counts){
        if(a.second&1){
            cout<<-1<<"\n";
            return;
        }
    }
    int total = go(0,arr);
    cout<<ans.size()<<"\n";
    for(auto a:ans){
        cout<<a.second+1<<" "<<a.first<<"\n";
    }
    cout<<segs.size()<<"\n";
    segs.push_back(total);
    for(int i=1;i<segs.size();i++){
        cout<<segs[i]-segs[i-1]<<" ";
    }
    cout<<"\n";
    segs.clear();
    ans.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}