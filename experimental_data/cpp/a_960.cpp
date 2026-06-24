#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define intl long long
int main(){
	string s;
	cin>>s;
	int n=s.size();
	int counta=0,countb=0,countc=0;
	for(int i=0;i<n;i++){
		if(s[i]=='a'){
			counta++;
		}
		else if(s[i]=='b'){
			countb++;
		}
		else{
			countc++;
		}
	}
	if(counta==0||countb==0){
		cout<<"NO"<<endl;
		return 0;
	}
	if(countc!=countb&&countc!=counta){
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<counta;i++){
		if(s[i]!='a'){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=counta;i<counta+countb;i++){
		if(s[i]!='b'){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=counta+countb;i<n;i++){
		if(s[i]!='c'){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	
	
	cout<<"YES"<<endl;
	return 0;
}