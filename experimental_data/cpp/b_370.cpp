#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define nmax 200
using namespace std;

int V[nmax][nmax];

bool verifica(int a, int b)
{
    int na = V[a][0];
    int nb = V[b][0];
    if(nb > na) return false;
    int nr = 0;
    for(int i=1 ; i<=na ; i++)
    {
        for(int j=1 ; j<=nb ; j++)
        {
            if(V[a][i] == V[b][j])
            {
                nr++;
                break;
            }
        }
    }
    if(nr == nb) return true;
    return false;
}

int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        scanf("%d",&x);
        V[i][0] = x;
        for(int j=1 ; j<=x ; j++)
            scanf("%d",&V[i][j]);
        sort(V[i] + 1 , V[i] + x + 1);
    }
    for(int i=1 ; i<=n ; i++)
    {
        bool sem = true;
        for(int j=1 ; j<=n ; j++)
        {
           if(i != j)
           {
               if(verifica(i,j) == true)
               {
                   sem = false;
                   break;
               }
           }
        }
        if(sem) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}