#include <iostream>
//#include <math.h>
#include <string>
#include <cstdio>
#include <stdlib.h>

using namespace std;


string mass[2][101],s,t;
int main ()
{
//	freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int n;
	
	cin>>n;	
		for(int i=0;i<n;i++)
		{
			cin>>s;
			cin>>t;
			mass[0][i]=s;
			mass[1][i]=t;
		}
	for(int i=0;i<n;i++)
	{
		if( mass[1][i]=="rat") cout<<mass[0][i]<<"\n";
	}
	for(int i=0;i<n;i++)
	{
		if( mass[1][i]=="woman" || mass[1][i]=="child") cout<<mass[0][i]<<"\n";
	}
	for(int i=0;i<n;i++)
	{
		if( mass[1][i]=="man") cout<<mass[0][i]<<"\n";
	}
	for(int i=0;i<n;i++)
	{
		if( mass[1][i]=="captain") cout<<mass[0][i]<<"\n";
	}
	


        return 0;
}