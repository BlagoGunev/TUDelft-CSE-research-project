#include<bits/stdc++.h>
using namespace std;
#define Hello (ios_base::sync_with_stdio(false),cin.tie(NULL))
#define pb push_back
typedef long long ll;
int main(){
	Hello;
	int t=1;
	cin>>t;
	while(t--){
	   int n,m;
	   cin>>n>>m;
	   vector<int> a(n),b(n);
	   a[0]=1;
	   for(int i=1;i<n;i++)
	   	cin>>a[i];
	   for(int i=0;i<n;i++)
	   	cin>>b[i];
	   sort(a.begin(),a.end());
	   sort(b.begin(),b.end());
	   int i=0;
	   for(int i=0;i<n;i++){
	   	auto it=upper_bound(b.begin(),b.end(),a[i]);

	   	if(it==b.end()){
	   		break;
	   	}
	   	//cout<<it-b.begin()<<" ";
	   	b.erase(it);
	   }
	   cout<<b.size()<<endl;
	}
}