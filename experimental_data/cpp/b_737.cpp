#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
char s[1<<20]={0};

int main()
{
    int n, m, l, c=0;
    scanf("%d%d%d%*d%s", &n, &m, &l, s);
    s[n]='1';
    
    for(int p=-1, i=0; i<=n; i++)
    {
        if( s[i]=='1' )
        {
            c+=(i-p-1)/l;
            p=i;
        }
    }
    
    c-=m-1;
    printf("%d\n", c);
    
    for(int p=-1, i=0; i<=n && c>0; i++)
    {
        if( s[i]=='1' )
        {
            for(int j=p+l+1; j<=i && c>0; j+=l)
                printf(--c==0 ? "%d\n" : "%d ", j);
            
            p=i;
        }
    }
}