#include<cstdio>
#include<cstdlib>
#include<cstring>


int a[105];
int b[105];
int neg[20005]={};
int pos[20005]={};
int nl[205];
int pl[205];
int nn;
int pn;
int main(void)
{
    int n,k;    
    int i,j;
    scanf("%d %d",&n,&k);
    int all = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        b[i]*=k;
    }
    nn = 0;
    pn = 0;
    int ans = 0;
    
    for(i=0;i<n;i++)
    {
        int x = a[i]-b[i];
        if(x==0)
            ans+=a[i];
        else if(x<0)
        {
            nl[nn++] = i;
        }
        else
            pl[pn++] = i;
            
    }
    
    for(i=0;i<nn;i++)
    {
        int x = b[nl[i]]-a[nl[i]];
        for(j=19999;j>x;j--)
            if(neg[j-x]!=0&&neg[j]<neg[j-x]+a[nl[i]])
                neg[j]=neg[j-x]+a[nl[i]];
        if(a[nl[i]]>neg[x])
            neg[x] = a[nl[i]];
        
    }
    for(i=0;i<pn;i++)
    {
        int x = a[pl[i]]-b[pl[i]];
        for(j=19999;j>x;j--)
            if(pos[j-x]!=0&&pos[j]<pos[j-x]+a[pl[i]])
                pos[j]=pos[j-x]+a[pl[i]];
        if(a[pl[i]]>pos[x])
            pos[x] = a[pl[i]];
        
    }
    int max = 0;
    for(i=19999;i>=0;i--)
        if(neg[i]>0&&pos[i]>0)
        {
            if(max<neg[i]+pos[i])
                max = neg[i]+pos[i];
        }
    ans+=max;
    if(ans==0)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}