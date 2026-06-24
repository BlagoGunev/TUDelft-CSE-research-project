#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		long long n;
		cin>>n;
		vector<long long>all(n);
		map<long long ,pair<int,int>>mp;
		for(int i=0;i<n;i++){
			cin>>all[i];
			if(mp.count(all[i])==0){
				mp[all[i]]=make_pair(i,i);
			}	
			mp[all[i]].second=i;
		}	
		int k=0;
		while(mp.count(k)==1){
			k++;
		}
		if(mp.count(k+1)==0){
			if(k==n){
				cout<<"NO\n";
				continue;
			}
			cout<<"YES\n";
			continue;
		}
		set<long long>sta;
		int l=mp[k+1].first,r=mp[k+1].second;
		for(int i=0;i<l;i++){
			sta.insert(all[i]);
		}
		for(int i=r+1;i<n;i++){
			sta.insert(all[i]);
		}
		int kk=0;
		while(sta.count(kk)==1){
			kk++;
		}	
		if(kk==k){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}