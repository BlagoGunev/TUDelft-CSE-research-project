#include<bits/stdc++.h>
#define ne change[{int(mid.first-(double(x)-mid.first)),int(mid.second-(double(y)-mid.second))}]
using namespace std;
int n,q;
string s;
map<int,pair<int,int> >mp;
map<pair<int,int>,vector<int> >change;
int nowx,nowy;
int x,y,l,r;
int main(){
	cin>>n>>q;
	cin>>s;
	change[{0,0}].emplace_back(-1);
	for(int i=0;i<n;i++){
		if(s[i]=='U'){
			nowy++;
		}
		if(s[i]=='D'){
			nowy--;
		}
		if(s[i]=='L'){
			nowx--;
		}
		if(s[i]=='R'){
			nowx++;
		}
		mp[i]={nowx,nowy};
		change[{nowx,nowy}].emplace_back(i);
	}
	while(q--){
		cin>>x>>y>>l>>r;
		l--;r--;
		bool flag=0;
		if(change[{x,y}].size()!=0){
			if(change[{x,y}][0]<l||change[{x,y}][change[{x,y}].size()-1]>=r){
				flag=1;
			}
		}
		if(flag==1){
			cout<<"YES"<<endl;
			continue;
		}
		for(int i : change[{int(mp[l-1].first+mp[r].first-x),mp[l-1].second+mp[r].second-y}]){
			if(i>=l&&i<r){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}