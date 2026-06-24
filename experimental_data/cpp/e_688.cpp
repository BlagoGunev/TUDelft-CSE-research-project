#include<bits/stdc++.h>

using namespace std;

bool mark[509];

int main(){

    int a,b,c,d,e,f,g,h;

    mark[0]=1;

    bitset<501> se[509];

    scanf("%d%d",&a,&h);

    g=0;

    se[0][0]=1;

    for(d=0;d<a;d++){

        scanf("%d",&f);

        for(e=h;e>=f;e--){

            if(mark[e-f]){

                mark[e]=1;

                //printf("d:%d %d\n",d,e);

                se[e]|=se[e-f];

                se[e]|=se[e-f]<<f;



            }

        }

    }



    printf("%d\n",se[h].count());

    c=0;

    for(d=0;d<=h;d++){

        if(se[h][d]==0)continue;

        if(c)printf(" ");

        else c=1;

        printf("%d",d);

    }

    if(c)printf("\n");

    return 0;

}