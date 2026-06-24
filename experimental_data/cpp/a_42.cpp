#include<sstream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,n,m,ar[110],br[110];
    double S[110],l,V;

    while(scanf("%d%lf",&n,&V)==2)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
            scanf("%d",&br[i]);


        for(i=0;i<n;i++)
        {
            S[i]=br[i]/(double)ar[i];
        }
        sort(&S[0],&S[n]);
        l=0;

        for(i=0;i<n;i++)
        {
          l+=(S[0]*ar[i]);
        }
        if(l>V)
            printf("%lf\n",V);
        else printf("%lf\n",l);

    }
    return 0;
}