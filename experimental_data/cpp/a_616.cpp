#include <cstdio>
//------------------------------------------------------------
int  i;
int  la;
char a[1000010];
int  lb;
char b[1000010];
//------------------------------------------------------------
int  main( )
{
	for (; (a[1]=getchar())=='0'; ); la=1;
	if (a[1]>='0'&&a[1]<='9')
	for (; ; )
	{
		a[++la]=getchar();
		if (a[la]<'0'||a[la]>'9') break;
	}
	for (; (b[1]=getchar())=='0'; ); lb=1;
	if (b[1]>='0'&&b[1]<='9')
	for (; ; )
	{
		b[++lb]=getchar();
		if (b[lb]<'0'||b[lb]>'9') break; 
	}
	if (la>lb) printf(">"); else
	if (la<lb) printf("<"); else
	{
		for (i=1; i<la&&b[i]==a[i]; i++);
		if (i==la) printf("="); else
		if (a[i]>b[i]) printf(">");
			else	   printf("<");
	}
}