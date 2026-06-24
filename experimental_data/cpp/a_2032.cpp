#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(2*n);
        int c0=0, c1=0;
        for(auto &x: a){
            cin>>x;
            if(x==0) c0++;
            else c1++;
        }
        // Calculate min_diff
        int sum_pairs = (c0 /2) + (c1 /2);
        int min_diff = max(n - sum_pairs, 0);
        // Calculate max_diff
        int max_diff = min(c0, c1);
        cout<<min_diff<<" "<<max_diff<<"\n";
    }
}