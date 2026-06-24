#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#define s(n) scanf("%d", &n)
#define s2(a,b) scanf("%d %d",&a, &b)
#define ss(n) scanf("%s",n)
#define pb push_back
#define vi vector<int>
using namespace std;
int n,m,k,x,flag,res,mark[10004];
int main()
{
	s2(n,m);
	while(m--)
	{
		s(k);
		flag=0;
		while(k--)
		{
			s(x);
			//cout<<x<<" ";
			if(x<0)
			{
		//	cout<<mark[-x]<<"mark";
				if(mark[-x]==(m+1))
				flag=1;
				mark[-x]=-m-1;
			}
			else
			{
			//cout<<mark[x]<<"mark+";
				if(mark[x]==-(m+1))
				flag=1;
				mark[x]=m+1;
			}
		}
		//cout<<flag<<"\n";
		if(flag==0)
		res=1;
		//cout<<res<<"\n";
	}
	if(res==1)
	printf("YES");
	else
	printf("NO");
	return 0;
}