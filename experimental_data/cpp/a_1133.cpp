#include<iostream>
#include<string>
using namespace std;

int main(){
	int h1,h2,m1,m2;
	string s1,s2;
	cin>>s1>>s2;

	h1=(s1[0]-'0')*10+s1[1]-'0';
	m1=(s1[3]-'0')*10+s1[4]-'0';	

	h2=(s2[0]-'0')*10+s2[1]-'0';
	m2=(s2[3]-'0')*10+s2[4]-'0';

	int total_min=(h1*60+m1+h2*60+m2)/2;
	int h3=total_min/60;
	int m3=total_min%60;
	if(h3<10){
		cout<<"0"<<h3;
	}
	else cout<<h3;
	cout<<":";
	if(m3<10){
		cout<<"0"<<m3;
	}
	else cout<<m3;
	


	return 0;
}