#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int b[n];
        int i = 1, max = -1,j=0;
        while (j < n)
        {
            if (a[j] != i)
            {
                b[j]=i;
                j++;
            }
            i++;
        }
        // for(int i=0;i<n;i++)
        // {
        //     printf("%d ",b[i]);
        // }
        // printf("\n");
        //int max=-1;
        for(int i=0;i<n;i++)
        {
            if(max<b[i])
            {
                max=b[i];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}