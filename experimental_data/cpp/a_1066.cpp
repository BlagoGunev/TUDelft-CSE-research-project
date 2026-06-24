#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1000000007
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int L,v,l,r;
        scanf("%d %d %d %d",&L,&v,&l,&r);
        int trains = L/v;
        int lost = (r/v)-((l-1)/v);
   //     printf("t %d l %d\n",trains, lost);
        printf("%d\n",trains-lost);
    }
    return 0;
}