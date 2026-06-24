#include<bits/stdc++.h>



using namespace std;



int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    int a[n+1];

    for(int i=1;i<=n;i++)

        scanf("%d",&a[i]);

    int sofar=0,x,y;

    for(int i=0;i<m;i++)

        {

            int t;

            scanf("%d",&t);

            if(t==1)

                {

                    scanf("%d%d",&y,&x);

                    a[y]=x-sofar;

                }

            else if(t==2)

                {

                    scanf("%d",&x);

                    sofar+=x;

                }

            else

                {

                    scanf("%d",&x);

                    printf("%d\n",a[x]+sofar);

                }

        }

    return 0;

}