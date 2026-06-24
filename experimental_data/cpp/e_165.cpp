#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

bool b[5000001];
int f[5000001],n,a[5000001];

int main(){
   // freopen("1.txt","r",stdin);
   // freopen("2.txt","w",stdout);
    scanf("%d",&n);
    memset(b,false,sizeof(b));
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]=true;
    memset(f,0,sizeof(f));
    for (int i=(1<<22)-1;i;--i)
    {
       //if ((1<<22)-1-i==90) printf("%d\n",i);
        if (b[(1<<22)-1-i]) f[i]=(1<<22)-1-i;
        else 
        for (int j=1;j<=22;j++)
          if (f[i|(1<<(j-1))]) 
          {
             f[i]=f[i|(1<<(j-1))];
             break;
          }  
       // if (f[i]) printf("%d %d\n",i,f[i]);
    }
    for (int i=1;i<=n;i++) 
        if (f[a[i]]) printf("%d ",f[a[i]]);
        else printf("-1 ");
    printf("\n");
}