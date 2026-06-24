#include <bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>

// #include<ext/pb_ds/tree_policy.hpp>

#define ll long long

const int mod=998244353;

const int maxn=1e6;

const ll INF=9e18;

#define endl "\n"

#define pb push_back

using namespace std;

// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> //(less,less_equal,greater,greater_equal)=(set,multiset,decreasing set,decreasing multiset)

//He who loves to sleep and the folding of hands , poverty will set upon you like a thief in the night.





int main() {

#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    cin.tie(0); 

    cout.tie(0);

    int tc;  

    // cin>>tc;

    tc=1;

    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(tc--){ 

        int m,n;

        cin>>m>>n;

        vector<vector<int> >arr(m,vector<int>(n));

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                cin>>arr[i][j];

                arr[i][j]--;

            }

        }

        int res=0;

        for(int j=0;j<n;j++){

            map<int,int>mp;

            for(int i=0;i<m;i++){

                int real=j+i*n;

                if((arr[i][j]-j)>=0 && (arr[i][j]-j)%n==0){

                    int row=(arr[i][j]-j)/n;

                    if(row>=m) continue;

                    if(row<=i) mp[i-row]++;

                    else mp[i+m-row]++;

                }

            }

            int ans=m;

            for(auto it:mp){

                ans=min(ans,it.first+m-it.second);

            }

            // cout<<ans<<endl;

            res+=ans;

        }

        cout<<res<<endl;

    }

    return 0;

}