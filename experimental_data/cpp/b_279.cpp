#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int Max,N,M,d[100005],st,en,mx,top;
int main()
{

    scanf("%d %d",&N,&M);
    
    for (int i= 0 ; i < N ; i++)
        scanf("%d",&d[i]);

    while(st != N && en != N)
    {
        if(d[en] + top <= M)    
        {
            mx++;
            top+= d[en++];
        }
        else
        {

            Max = max(mx,Max);
            mx--;
            top-=d[st++];
        }
            
    }
    printf("%d",max(mx,Max));
    
    scanf(" ");
}