#include<stdio.h>
#include<string.h>
char s[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		int l=strlen(s);
		int o=0;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='0')
			{
				o++;
			}
		}
		if(o==1)
		{
			printf("BOB\n");
		}
		else
		{
			if(o%2==0)
			{
				printf("BOB\n");
			}
			else
			{
				printf("ALICE\n");
			}
		}
	}
	return 0;
}