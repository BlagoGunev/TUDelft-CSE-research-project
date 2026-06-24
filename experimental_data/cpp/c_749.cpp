#include<stdio.h>

int main()
{
	int n, i,fd=0,fr=0,d=0, r=0;
	char s[200010];
	scanf("%d", &n);
	scanf("%s", s);
	for(i=0; i<n; i++)
	{
			if(s[i]=='D')
				fd++;
			else if (s[i]=='R')
				fr++;
	}
	while(fd>0&&fr>0)
	{
		for(i=0; i<n; i++)
		{
			if(s[i]=='D')
			{
				if(r>0)
				{
					s[i]='O';
					r--;
					fd--;
				}
				else 
					d++;
			}

			else if (s[i]=='R')
			{
				if(d>0)
				{
					s[i]='O';
					d--;
					fr--;
				}
				else
					r++;
			}
		}	
	}
	for(i=0; i<n; i++)
	{
			if(s[i]=='D')
			{
				printf("D");
				break;
			}
			else if (s[i]=='R')
			{
				printf("R");
				break;
			}
	}

	return 0;
}