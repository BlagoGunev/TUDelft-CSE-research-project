#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read()
{
	int x=0,t=1,c;
	while(!isdigit(c=getchar()))if(c=='-')t=-1;
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*t;
}
int limits[200020],top=0;
int overtake=0,ans=0,speed=0;
int main()
{
	int n=read();
	while(n--)
	{
		int type=read();
		if(type==1)speed=read();
		else if(type==2)
		{
			ans+=overtake;
			overtake=0;
		}
		else if(type==3)limits[top++]=read();
		else if(type==4)overtake=0;
		else if(type==5)top=0;
		else overtake++;
		while(top)if(limits[top-1]<speed)ans++,top--;
		else break;
	}
	printf("%d",ans);
}