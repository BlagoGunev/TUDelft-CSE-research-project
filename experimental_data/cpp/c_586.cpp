#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long N = 4444;
long long n,v[N],d[N],p[N],ls[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%I64d",&n);
    for (long long i=1; i<=n; i++)
        scanf("%I64d%I64d%I64d",&v[i],&d[i],&p[i]);
    for (long long i=1; i<=n; i++)
        if (p[i] >= 0)
        {
            long long delta=0,voice=v[i];
            for (long long j=i+1; j<=n; j++)
                if (p[j]>=0) 
                {
                    p[j]-=delta;
                    if (voice>0) {p[j]-=voice; voice--;}
                    if (p[j]<0) delta+=d[j];
                }
            ls[++ls[0]]=i;
        }
    printf("%I64d\n",ls[0]);
    for (long long i=1; i<ls[0]; i++)
        printf("%I64d ",ls[i]);
    printf("%I64d\n",ls[ls[0]]);
    return 0;
}