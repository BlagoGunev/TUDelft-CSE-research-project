#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

#define ll long long

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;



void solve(){

 ll a,b,c,d; cin >> a >> b >> c >>d;

 if((a+b)%2){

    if(a or d){

    	cout <<"Ya ";

    }

    else cout <<"Tidak ";

    if(b or c)

    	cout <<"Ya ";

    else cout <<"Tidak ";

 	cout <<"Tidak Tidak\n";

 }

 else{

 	cout <<"Tidak Tidak ";

 	if(b or c) cout <<"Ya ";

 	else cout <<"Tidak ";

 	if(a or d) cout <<"Ya ";

 	else cout <<"Tidak ";



 	cout <<'\n';

 }





}



int main(){

  ios_base::sync_with_stdio(0);

  cin.tie(0);

 

  ll t = 1;  cin >> t;

  while(t--){

    solve();

  }

}