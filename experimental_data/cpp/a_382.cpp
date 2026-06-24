#include<cstdio>

#include<cstring>

#include<math.h>

char s1[200],s2[200];

using namespace std;

int main()

{

	int a,b,i,j,flag,len1,len2,mid;

	scanf("%s",s1);

	len1=strlen(s1);

	a=0,b=0,flag=0;

	for(i=0;i<len1;i++)

	{

		if(s1[i]=='|')

		{

			flag=1;

			continue;

		}

		if(flag) b++;

		else a++;

	}

	scanf("%s",s2);

	len2=strlen(s2);

	if(fabs(a-b)>len2)

		printf("Impossible\n");

	else if((a+b+len2)%2==0)

	{

		mid=(a+b+len2)/2;

		for(i=0;i<a;i++)

			printf("%c",s1[i]);

		for(;i<mid;i++)

			printf("%c",s2[i-a]);

		printf("|");

		for(j=0;j<b;j++)

			printf("%c",s1[a+j+1]);

		for(j=mid-a;j<len2;j++)

			printf("%c",s2[j]);

		printf("\n");

	}

	else 

		printf("Impossible\n");

	return 0;

}