#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1.length()!=s2.length()){
		cout<<"No"<<endl;
		return 0;
		}
		int c1=0,c2=0;
		vector<int>v1,v2;
		int t=s1.length();
		for(int i=0;i<t;i++){
	     if(s1[i]=='a' || s1[i]=='i' || s1[i]=='o' ||s1[i]=='u' || s1[i]=='e'){
	     	v1.push_back(i);
			 c1++;	
	     }
	     if(s2[i]=='a' || s2[i]=='i' || s2[i]=='o' ||s2[i]=='u' || s2[i]=='e'){
	     	v2.push_back(i);
			 c2++;	
	     }
	}
bool flage=false;
if(c1!=c2){
	cout<<"No"<<endl;
}
else{
	for(int i=0;i<v1.size();i++)
	if(v1[i]!=v2[i])
		flage=true;
	if(flage)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}
	return 0;
}