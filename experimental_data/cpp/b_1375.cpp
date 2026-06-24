#include "bits/stdc++.h"
//#include <functional>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define PI 2 * acos(0)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif
#define LOOP printf("LOOP!!")
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define TIME cerr << "\nTime:" << 1000 * clock() / CLOCKS_PER_SEC << '\n';
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define endl "\n"
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//#define PQ priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

void show(vector<int> &v)
{
    for (auto &it : v)
        cout << it << " ";

    cout << '\n';
}

//............................//


int main()
{

     FAST;
     int t;
     cin>>t;
     while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m));
        bool ok=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(v[i][j]>4)ok=true;
            }
        }
        cout<<endl;
        if(ok){
            NO;
            continue;
        }
        else{

           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 and i<n-1 and j>0 and j<m-1)v[i][j]=4;
                else if(i==0 and j==0 or i==n-1 and j==0 or i==0 and j==m-1 or i==n-1 and j==m-1){
                    if(v[i][j]>2){ok=true;break;}
                    v[i][j]=2;
                }
                else {
                    if(v[i][j]>3){ok=true;break;}
                    v[i][j]=3;
                }
            }
           } 
        }

        if(ok){
            NO;
            continue;
        }  
        YES;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<v[i][j]<<" ";
                cout<<endl;
        }
     }
     
  
 
     return 0;
}

/// sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
///  is_sorted(all(v))
// always formulate your equation in multiplication form not div
/// fflush(stdin)
// are you using same variable inside another if or else ?