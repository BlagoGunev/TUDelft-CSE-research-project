/*--------------------- Author - Akshit ----------------------*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<cstdlib>
#include<numeric>
#include<set>
#include<map>
#include<deque>
#include<climits>
#include<cassert>
#include<cctype>
#include<ctime>
#include<iterator>
#include<iomanip>
#include<functional>
#include<fstream>
#include<ostream>
#include<istream>

using namespace std;

#define sf(n)                scanf("%d",&n) 
#define pf(n)                printf("%d",n)          
#define pfln(n)              printf("%d\n",n)         

#define vi                   vector <int > 
#define pb                   push_back()
#define debug(in)             printf("n = %d\n",n)
#define PI 3.14159265358979
int main(){
	int n,k;
	cin >>n>>k;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=0
		}
	}*/
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				cout <<k<<" ";
			else
				cout<<"0 ";
		}
		cout<<"\n";
	}
	return 0;
}