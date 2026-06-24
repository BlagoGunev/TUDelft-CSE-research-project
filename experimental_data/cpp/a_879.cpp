#include <cstdio>
#include <cstring>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a[1010],b[1010];
        for(int i=1; i<=n ; i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        int coun=0,j=1;
        for(int i=a[j];; i++)
        {
            if((i-a[j])%b[j]==0 && (i-a[j])>=0)
            {
                coun++;
                j++;
            }
            if(coun==n)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;

}