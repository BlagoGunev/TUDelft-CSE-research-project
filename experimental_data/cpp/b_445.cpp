#include <bits/stdc++.h>
#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

int fer[60];

int fin(int x)

{

    if (x==fer[x])

        return x;

    return fer[x]=fin(fer[x]);

}

int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;i++)

        fer[i]=i;

    int a,b;

    for (int i=0;i<m;i++)

    {

        scanf("%d%d",&a,&b);

        fer[fin(a)]=fin(b);

    }

    int64_t aa,bb;

    aa=bb=0;

    for (int i=1;i<=n;i++)

    if (fer[i]==i)

        aa++;

    else

        bb++;

    aa=1;

    while (bb--)

        aa*=2;

                                /*if (aa)

                                {

                                    while (bb--)

                                    {

                                        aa*=2;

                                    }

                                }

                                else

                                {

                                    aa=1;

                                    bb--;

                                    while (bb--)

                                        aa*=2;

                                }*/

    printf("%lld\n",aa);

    return 0;

}