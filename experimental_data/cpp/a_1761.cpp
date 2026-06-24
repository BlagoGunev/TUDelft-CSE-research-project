#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;



using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>pbds;

#define ll long long int

#define vll vector<ll>

#define pb push_back

#define q queue

#define s stack

#define mll map<ll,ll>

#define max_heap priority_queue<int>

#define min_heap max_heap<int,vector<int>,greater<int>>

#define Yes cout<<"YES"<<endl

#define No cout<<"NO"<<endl

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);cout.tie(NULL);

    int t;

    cin>>t;

    while(t--){

        int n,a,b;cin>>n>>a>>b;

        if(a==n && b==n)cout<<"Yes"<<endl;

        else if((a==n && b!=n) || (a!=n && b==n))

        cout<<"No"<<endl;

        else if(a+b<(n-1))cout<<"Yes"<<endl;

        else cout<<"No"<<endl;

    }

    return 0;

}