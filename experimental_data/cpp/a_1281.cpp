#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
	// your code goes here
	int t,i,j,n;
	cin >>t;
	string h="desu";
	string k="masu";
	string m="mnida";
	string l="po";
	string x,y;
	while(t--)
	{
		string s;
		cin >>s;
		n=s.length();
 
		          if(n<5)
				{x=m.substr(max(0,5-n),min(5,n));
				if(x==s)
					{cout <<"KOREAN"<<endl;
		continue;}}
		else 
		{
			x=s.substr(n-5,5);
			if(x==m)
					{cout <<"KOREAN"<<endl;
		continue;}
 
 
		}
		if(n<4)
				{	x=h.substr(max(0,4-n),min(4,n));
				  y=k.substr(max(0,4-n),min(4,n));
		if(x==s||y==s)
					{cout <<"JAPANESE"<<endl;
		continue;}}
		else 
		{
			x=s.substr(n-4,4);
			if(x==h||x==k)
					{cout <<"JAPANESE"<<endl;
		continue;}
		}
 
		if(n<2)
				{	x=l.substr(max(0,2-n),min(2,n));
		if(x==s)
					{cout <<"FILIPINO"<<endl;
		continue;}}
		else 
		{
			x=s.substr(n-2,2);
			if(x==l)
					{cout <<"FILIPINO"<<endl;
		continue;}
		}
 
 
 
	}
	return 0;
}