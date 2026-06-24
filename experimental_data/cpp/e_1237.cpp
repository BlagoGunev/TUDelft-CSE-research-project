#include<bits/stdc++.h>
using namespace std;
const int N = 1<<21;
int n,m;
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("1"),0;
	if(n==2)return puts("1"),0;
	for(int x=1,y=2;x<=n||y<=n;)
	{
		if(x==n||y==n)return puts("1"),0;
		x+=y+1,y+=y+1,swap(x,y);
	}
	puts("0");
	return 0;
}