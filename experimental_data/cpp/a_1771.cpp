#include <bits/stdc++.h>

typedef long long ll;

typedef long double ld;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,

tree_order_statistics_node_update> indexed_set;

//freopen("slingshot.in", "r", stdin);

//freopen("slingshot.out", "w", stdout);



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        int c[n];

        map<int,ll> m;

        for(int i=0;i<n;i++){

            cin>>c[i];

            m[c[i]]++;

        }

        auto it=m.end();

        it--;

        int a=m.begin()->first;

        int b=it->first;

        if(a==b){

            cout<<m[a]*(m[a]-1)<<endl;

        }

        else{

            cout<<m[a]*m[b]*2<<endl;

        }

    }

}