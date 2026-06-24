#include<stdio.h>



int main()

{

    int n,i,a;

    scanf("%d",&n);

    a=n;

    for (i=1;i<=n;i++)

    {

        if (i%2==0) printf("I love ");

        else printf("I hate ");

        if (i==a) printf("it ");

        else printf("that ");

    }

}