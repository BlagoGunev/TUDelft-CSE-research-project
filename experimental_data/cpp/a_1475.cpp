#include<stdio.h>
int main()
{
    long long int t,n;
    scanf("%lld", &t);
    while(t--)
    {   
        int count=0;
        scanf("%lld", &n);
        if(n%2!=0)
        {
            printf("YES\n");
        }
        else
        {
            while(n!=0)
            {
                n=n/2;
                if(n%2!=0 && n>2)
                {
                    count++;
                    break;
                }
            }
        
        if(count==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        }
    }

}