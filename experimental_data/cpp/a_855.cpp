#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
 using namespace std;

 int main()
 {
 	int n,i,j,cnt=0;
 	cin>>n;
 	string s[100];
 	for(i=0;i<n;i++)
 	{
 		cin>>s[i];
 	}
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<i ;j++)
 		{
 			if(s[i]==s[j])
 				cnt++;
 		}
 		if(cnt>0)
 		cout<<"YES"<<endl;
 	else
 		cout<<"NO"<<endl;
 	cnt=0;
 	}
 	
 	
 	return 0;
 }