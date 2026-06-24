#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[52],b[52],ma[52],mb[52];
int main()
{
    int N,M,ok = 0;
    scanf("%d %d",&N,&M);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d",&a[i]);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d",&b[i]);
    sort(a + 1, a + 1 + N);
    sort(b + 1, b + 1 + N);
    for(int i = 2 ; i <= N ; i++)
        ma[i] = a[i] - a[i - 1],mb[i] = b[i] - b[i - 1];
    ma[1] = a[1] + M - a[N];
    mb[1] = b[1] + M - b[N];
    //for(int i = 1 ; i <= N ; i++)
      //  printf("%d %d\n",ma[i],mb[i]);
    for(int i = 0 ; i < N ; i++){
        int t = 1;
        for(int j = 1 ; j <= N ; j++){
           int kl = (i + j) % N;
           if(kl == 0) kl = N;
           if(mb[j] != ma[kl])
              t = 0;
        }
    if(t) ok = 1;
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}