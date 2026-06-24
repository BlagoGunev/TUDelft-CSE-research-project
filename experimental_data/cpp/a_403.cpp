#include<stdio.h>

#include<string.h>

using namespace std;

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        int n,p;

        scanf("%d%d",&n,&p);

        int x,y;

        x=1;y=2;

        for(int i=0;i<n*2+p;i++)

        {

            printf("%d %d\n",x,y);

            y++;

            if(y==n+1)

            {

                x++;

                y=x+1;

            }

        }

    }

}