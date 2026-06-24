#include <bits/stdc++.h>
#define tr true
#define br break
#define con continue
#define len strlen
#define maxx 5005
using namespace std;
char s[maxx],t[maxx];
int n,k,r,c,m;
bool f[maxx],g[maxx];
int main()
{
    scanf("%s",s); n=len(s); k=0;r=1;
    while (r*2<=n) r*=2,k++;
    m=n-r+1; memset(f,tr,sizeof(f));
    for (int i=0;i<m;i++)
    {
        t[i]='z';
        for (int j=0;j<r;j++) if (f[j]&&s[j+i]<t[i]) t[i]=s[j+i];
        memset(g,false,sizeof(g));
        for (int j=0;j<r;j++) if (f[j]&&s[j+i]==t[i]){
            if (g[j]) con; c=r-1-j;
            for (int j=c;;j=(j-1)&c)
            {
                g[r-1-j]=tr;
                if (!j) br;
            }
        }
        for (int j=0;j<r;j++) f[j]=g[j];
    }
    for (int i=0;i<m;i++) printf("%c",t[i]); printf("\n");
    return 0;
}