#include<bits/stdc++.h>

using namespace std;

int main()

{

    int n,k=0; scanf("%d",&n);

    for(int a,b,i=0; i<n && scanf("%d%d",&a,&b) ;i++)

        if(a!=b)

            k=1;

    if(k)

        printf("Happy Alex");

    else

        printf("Poor Alex");

}