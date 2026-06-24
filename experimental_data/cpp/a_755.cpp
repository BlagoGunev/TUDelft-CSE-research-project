#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
 int isprime(int n)
 {
 	int i,flag=0;
 	for(i=5;i<=sqrt(n);i++)
 	{
 		if(n%i==0&&n!=5)
 		{
 			flag = 1;
 			break;
		 }
	 }
	 if(flag==1) return 1;
	 else return 0;
 }
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;;i++)
	{
		int k = n*i+1;
		if(k%2==0&&k!=2||k%3==0&&k!=3)
		{
			printf("%d\n",i);
			break;
		}
		else
		{
			if(isprime(k))
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}