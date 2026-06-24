#include <stdio.h>
int main()
{
	char a[100002];
	scanf ("%s",&a);
	int i=0,len=0;
	int aba=0,ab=0,ba=0;
	while (a[len]!='\0')
	{
		len++;
	}

	for(i=0;i<len;i++)
	{
		if(i<=len-3)
		{
			if(a[i]=='A'&&a[i+1]=='B'&&a[i+2]=='A')
			{
				aba++;
				i+=2;
			
			continue;
			}
			
			if(a[i]=='B'&&a[i+1]=='A'&&a[i+2]=='B')
			{
				aba++;
				i+=2;
			
			continue;
			}
		}
		if(i<=len-2)
		{
			if(a[i]=='A'&&a[i+1]=='B')
			{
				ab++;
				i++;
				continue;
			}
			
			if(a[i]=='B'&&a[i+1]=='A')
			{
				ba++;
				i++;
				continue;
			}
		}
	}
	if((aba>=2)||(aba==1 &&ab>=1)||(aba==1&&ba>=1)||(ab>=1&&ba>=1))
		printf ("YES\n");
	else
		printf ("NO\n");
	return 0;
}