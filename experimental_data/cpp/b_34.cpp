#include<stdio.h>
#include<algorithm>
using namespace std;
int num[110];
int main()
{
    int n,m,i;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        int sum = 0;
        for(i=0;i<m;i++){
            if(num[i]<=0)
            sum-=num[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}