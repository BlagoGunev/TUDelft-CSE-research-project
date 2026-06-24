#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
#define N 100100
#define K 310
int p[N][K], b[K], d[K], a[N];
vector <int> v[N];
int main()
{
    int s, e, n, l, i, j, r, t;
    scanf("%d%d%d%d", &n, &l, &s, &e);
    for(i=0; i<n; scanf("%d", &a[i]), i++);
    for(i=0; i<l; scanf("%d", &j), v[j].push_back(i), i++);
    for(i=0; i<N; i++)
        for(l=v[i].size(), j=0; j<K; p[i][j]=l, j++);
    for(i=1; i<K; b[i]=N, i++);
    r=0;
    for(j=0; j<n; j++)
    {
        t=a[j];
        for(i=0; i<K-1; i++)
        {
            int &q=p[t][i+1];
            for(; q-1>=0 && v[t][q-1]>=b[i]; q--);
            if(q<v[t].size()) d[i+1]=v[t][q]+1;
            else d[i+1]=N;
        }
        for(i=0; i<K; i++)
        {
            if(d[i]<b[i]) b[i]=d[i];
            if(b[i]<N && i*e+j+1+b[i]<=s && i>r) r=i;
        }
    }
    printf("%d\n", r);
    return 0;
}