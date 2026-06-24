#include<bits/stdc++.h>

using namespace std;



int kmm(int x,int y){

	int ans=x;

	while(ans%x!=0 || ans%y!=0){

//		cerr<<ans;

		ans++;

	}

	return ans;

}



int main(){

	int x,y,a,b;

	cin>>x>>y>>a>>b;

	int k=kmm(x,y);

//	cerr<<k<<endl;

	a--;

	cout<<b/k-a/k;

}