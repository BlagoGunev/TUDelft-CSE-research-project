#include<cstdio>
int main()
{
	int a;
	scanf("%d",&a);
	int ans=0;
	if(!a)++ans;
	while(a)
	{
		if(a%16==0)++ans;
		else if(a%16==4)++ans;
		else if(a%16==6)++ans;
		else if(a%16==8)ans+=2;
		else if(a%16==9)++ans;
		else if(a%16==10)++ans;
		else if(a%16==11)ans+=2;
		else if(a%16==13)++ans;
		a/=16;
	}
	printf("%d\n",ans);
	return 0;
}