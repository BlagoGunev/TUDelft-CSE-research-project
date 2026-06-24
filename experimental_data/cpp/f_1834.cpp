#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int>all(n),revall;
	for(int i=0;i<n;i++){
		cin>>all[i];
		all[i]--;
	}
	revall=all;
	reverse(revall.begin(),revall.end());
	vector<int>ps(n+3),revps(n+3);
	for(int i=0;i<n;i++){
		int z=n-((n+all[i]-i)%n);
		z%=n;
		if(z>i){
			ps[i+1]++;
			ps[z]--;
		}
		else{
			ps[0]++;
			ps[z]--;
			ps[i+1]++;
		}
	}
	for(int i=0;i<n;i++){
		int z=n-((n+revall[i]-i)%n);
		z%=n;
		if(z>i){
			revps[i+1]++;
			revps[z]--;
		}
		else{
			revps[0]++;
			revps[z]--;
			revps[i+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		revps[i]+=revps[i-1];
		ps[i]+=ps[i-1];
	}
	int nowasly=0,nowrev=0;
	int now=0;
	cout<<ps[0]<<"\n";
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int qq;
		cin>>qq;
		if(qq==1){
			int k;
			cin>>k;
			if(now){
				nowrev+=k;
				nowrev%=n;
				nowasly+=n-k;
				nowasly%=n;
			}
			else{
				nowasly+=k;
				nowasly%=n;
				nowrev+=n-k;
				nowrev%=n;
			}	
		}	
		if(qq==2){
			int k;
			cin>>k;
			if(now^1){
				nowrev+=k;
				nowrev%=n;
				nowasly+=n-k;
				nowasly%=n;
			}
			else{
				nowasly+=k;
				nowasly%=n;
				nowrev+=n-k;
				nowrev%=n;
			}	
		}
		if(qq==3){
			now^=1;
		}
		if(now){
			cout<<revps[nowrev]<<"\n";
		}
		else{
			cout<<ps[nowasly]<<"\n";
		}
	}
}