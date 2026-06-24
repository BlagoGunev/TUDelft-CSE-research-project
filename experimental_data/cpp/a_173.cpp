#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int round;
int n,m;
int yen[150][150];
string str1,str2;
string ystr1,ystr2;
int gcd(int a,int b)
{
	if(!a) return b;
	return gcd(b%a,a);
}
int main()
{
	yen['R']['S']=1;
	yen['P']['R']=1;
	yen['S']['P']=1;
	int i;
	int res1=0;
	int res2=0;
	int ekok;
	scanf(" %d",&round);
	cin >> str1 >> str2;
	ystr1=str1;
	ystr2=str2;
	n=str1.length(); m=str2.length();
	ekok=n*m/gcd(n,m);
	while(str1.length()<ekok)
		str1+=ystr1;
	while(str2.length()<ekok)
		str2+=ystr2;
	n=str1.length(); m=str2.length();
	for(i=0;i<n;i++)
	{
		if(yen[str2[i]][str1[i]])
			res1++;
		if(yen[str1[i]][str2[i]])
			res2++;
	}
	res1*=round/n;
	res2*=round/n;
	
	for(i=0;i<round%n;i++)
	{
		if(yen[str2[i]][str1[i]])
			res1++;
		if(yen[str1[i]][str2[i]])
			res2++;
	}
	printf("%d %d\n",res1,res2);
	return 0;
}