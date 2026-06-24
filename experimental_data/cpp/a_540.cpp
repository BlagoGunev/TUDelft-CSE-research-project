#include<bits/stdc++.h>

using namespace std;

int main()

 {

 	int n,x,ans=0,i;

 	string s1,s2;

 	cin>>n;

 	cin>>s1>>s2;

 	for(i=0;i<n;i++)

 	 {

 	 	x=abs((int (s1[i])-48)-(int(s2[i])-48));

 	 	if(x<=(10-x))

 	 	  ans=ans+x;

 	 	 else

 	 	 ans=ans+(10-x);

	  }

	cout<<ans;

	return 0;

 }