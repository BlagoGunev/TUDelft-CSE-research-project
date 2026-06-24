#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,

                tree_order_statistics_node_update> indexed_set;

 

const int mxm=1e9+7;

const int mx=2e3+5;

indexed_set s;

vector<int> adj[mx];

vector<int> ans(mx);

int a[mx];

int d[mx];

void dfs(int r){

	if(d[r]<a[r]){

		cout<<"NO\n";

		exit(0);

	}

	auto y=s.find_by_order(a[r]);

	int e=*y;

	s.erase(y);

	ans[r-1]=e;

	for(auto x:adj[r]){

		dfs(x);

	}

}

int dfs1(int s){

	for(auto x:adj[s]){

		d[s]+=dfs1(x);

	}

	return d[s]+1;

}



int main(){

	ios_base::sync_with_stdio(false);

    cin.tie(NULL);

	int n;cin>>n;

	int root=0;

	for(int i=0;i<n;i++){

		int x,y;

		cin>>x>>y;

		if(x==0){

			root=i+1;

		}

		else{

			adj[x].push_back(i+1);

		}

		a[i+1]=y;

	}

	for(int i=1;i<=n;i++){

		s.insert(i);

	}

	dfs1(root);

	dfs(root);

	for(int i=0;i<n;i++){

		if(ans[i]==0){

			cout<<"NO\n";

			exit(0);

		}

	}

	cout<<"YES\n";

	for(int i=0;i<n;i++){

		cout<<ans[i]<<" ";

	}

}