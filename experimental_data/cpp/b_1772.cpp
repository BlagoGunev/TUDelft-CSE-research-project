#include<stdio.h>

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        int a,b,c,d,k,q,u,i=4;

        scanf("%d%d%d%d",&a,&b,&c,&d);

        while(i!=0)

        {

        if(a<b&&a<c&&d>c&&d>b)

        {

            printf("YES\n");

            break;

        }

        else

        {

          k=a;

          q=b;

          b=a;

          a=c;

          u=d;

          d=q;

          c=u;

        }

        i--;

        }

        if(i==0)

        {

            printf("No\n");

        }

    }

    return 0;

}