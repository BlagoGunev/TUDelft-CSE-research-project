#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,x;
    scanf("%d%d",&n,&m);
    if (n==0&&m==1)
        printf("Yes\n");
    else if (m==0||n==0||m==1)
        printf("No\n");
    else if (m-1>n)
        printf("No\n");
    else if ((n-(m-1))%2==0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}