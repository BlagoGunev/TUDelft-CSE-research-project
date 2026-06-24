#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int,int> pi;

int n;

int arr[55];

int tmp[55];

int loc[55];

vector<vector<int>>ans;

void update(){

	vector<int>v = ans.back();

	int fin = n+1;

	int idx = 0;

	

	while(v.size()){

		int sz = v.back();

		v.pop_back();

		for(int i=fin-sz; i<fin; i++) tmp[++idx] = arr[i];

		fin-=sz;

	}

	for(int i=1; i<=n; i++) arr[i] = tmp[i];

	for(int i=1; i<=n; i++) loc[arr[i]] = i;

}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin>>n;

	for(int i=1; i<=n; i++) cin>>arr[i];

	for(int i=1; i<=n; i++) loc[arr[i]] = i;

	

	if(loc[1]!=1){

		ans.push_back({loc[1]-1,n - (loc[1]-1)});

		update();

	}

	for(int i=2; i<=n; i++){

		vector<int>v;

		if(loc[1]==1){

			if(loc[i]==i) continue;

			for(int j=1; j<i; j++) v.emplace_back(1);

			v.emplace_back(loc[i] - (i-1));

			if(n!=loc[i]) v.emplace_back(n-loc[i]);

		}

		else{

			if(loc[i]+(i-1)==n) continue;

			if(loc[i]!=1) v.emplace_back(loc[i]-1);

			v.emplace_back(n - (loc[i] - 1) - (i-1));

			for(int j=1; j<i; j++) v.emplace_back(1);

		}

		ans.push_back(v);

		update();

	}

	if(loc[1]!=1){

		vector<int>v;

		for(int i=1; i<=n; i++) v.emplace_back(1);

		ans.push_back(v);

		update();

	}

	cout<<ans.size()<<'\n';

	for(auto it : ans){

		cout<<it.size()<<" ";

		for(int x : it) cout<<x<<" ";

		cout<<'\n';

	}

}