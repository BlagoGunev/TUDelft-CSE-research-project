#include<iostream>

#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<algorithm>

#define inf 0x7fffffff

using namespace std;



int n;



int main()

{

    while (scanf("%d",&n)!=EOF)

    {

        if (n==1) {printf("1\n1\n");continue; }

        if (n==2) {printf("1\n1\n");continue; }

        if (n==3) {printf("2\n1 3\n");continue; }

        if (n==4) {printf("4\n2 4 1 3\n");continue; }

        printf("%d\n",n);

        printf("1");

        for (int i=3 ;i<=n ;i+=2) printf(" %d",i);

        for (int i=2 ;i<=n ;i+=2) printf(" %d",i);

        printf("\n");

    }

    return 0;

}