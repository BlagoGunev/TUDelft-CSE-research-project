#include <stdio.h>

 

int main()

{

	int n;

	scanf("%x",&n);

	

	if((n%10)%2==0)printf("0\n");

	else printf("1\n");

	return 0;

}