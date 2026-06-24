#include <stdio.h>
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int l,d;
	char s;
	if(k%2==0)
	    s='R';
	else
	    s='L';
	if(k%(m*2)==0)
	    d=k/(m*2);
	else
	    d=k/(m*2)+1; 
	k-=m*2*(d-1);
	if(k%2==0)
	    l=k/2;
	else
	    l=k/2+1;
	printf("%d %d %c\n",d,l,s);
	return 0;
}