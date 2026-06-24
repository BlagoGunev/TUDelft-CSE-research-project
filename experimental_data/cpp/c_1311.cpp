#include <bits/stdc++.h>

using namespace std;
int main(){
ios::sync_with_stdio(0); cin.tie(0);
int t; cin>>t;
while(t--){
int x,k; string s;cin>>x>>k>>s;
int a[k];
for(int i=0;i<k;i++)cin>>a[i];
sort(a,a+k);
map<char,int>mp;
int j=k-1;
for(int i=x-1;i>=0;i--){
while(a[j]>=i+1&&j>=0)j--;
mp[s[i]]+=k-j;
}
for(char p='a';p<='z';p++)cout<<mp[p]<<" ";
cout<<"\n";
}
return 0;
}