#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<map>
#include<queue>


using namespace std;

typedef pair<int, int> PII;
typedef pair<int, float> PIF;
typedef unsigned long long ULL;
typedef long long int LL;

#define PI acos(-1)
#define MAX  2011

//functions come here

int main()
{
    int n;
    scanf("%d", &n);
    int a[14]={4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int i;
    for(i=0; i<14; i++)
    {
        if(a[i]>n)
        {
            printf("NO\n");
            break;
        }
        else
        {
            if(n%a[i]==0)
            {
                printf("YES\n");
                break;
            }
        }
    }
    if(i==14)
        printf("NO\n");
    return 0;
}