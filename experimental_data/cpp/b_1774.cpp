#include<bits/stdc++.h>

using namespace std;

#define ll long long



void solve(){

	  int n,m,k;

	  cin>>n>>m>>k;

	  int x=(n+k-1)/k;

	  int cnt1=0;

	  bool cnt2=false;

	  vector<int> v(m);

	  for(int i=0;i<m;i++){

		cin>>v[i];

		if(v[i]==x)

		cnt1++;

		if(v[i]>x)

		cnt2=true;

	  }

	  if(cnt2){

		cout<<"no\n";

		return;

	  }

	  if(cnt1<=(n%k)){

		cout<<"yes\n";

		return;

	  }

	  if(n%k==0){

		cout<<"yes\n";

		return;

	  }

	  cout<<"no\n";

	  return;

}



int main(){

	  ios::sync_with_stdio(0);

	  cin.tie(0);

	  cout.tie(0);

	  int t;

	  cin>>t;

	  while(t--){

		   solve();

	  }





	  return 0;

}