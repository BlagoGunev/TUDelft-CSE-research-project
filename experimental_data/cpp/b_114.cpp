#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,maxs[17]={0};
bool dont[18][18]={false};
char a[18][14];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        maxs[i+1]=-1;
    }
    maxs[0]=-1;
    char A[12],B[12];
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%s",A);
        for(int ii=0;ii<n;ii++)
        {
            if(strcmp(A,a[ii])==0)
            {
                x=ii;
                break;
            }
        }
        scanf("%s",B);
        for(int ii=0;ii<n;ii++)
        {
            if(strcmp(B,a[ii])==0)
            {
                y=ii;
                break;
            }
        }
        //printf("%d %d\n",x,y);
        dont[x][y]=true;
        dont[y][x]=true;
    }
    for(int i=0;i<1<<n;i++)
    {
        //printf("%d\n",i);
        int x=i,p[17]={0},zero=0,one=0,g[17]={0},g2[17]={0};
        for(int j=0;j<n;j++)
        {
            p[j]=x%2;
            if(x%2==0)
            {
                g[zero]=j;
                zero++;
            }
            else
            {
                g2[one]=j;
                one++;
            }
            x/=2;
        }
        bool error = false;
        for(int j=0;j<zero;j++)
        {
            for(int k=0;k<zero;k++)
            {
                if(dont[g[j]][g[k]])
                {
                    error=true;
                    break;
                }
            }
            if(error)break;
        }
        if(!error)
        {
            maxs[zero]=i;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(maxs[i]>=0)
        {
            int x=maxs[i],p[17]={0},zero=0,one=0,g[17]={0},g2[17]={0};
            for(int j=0;j<n;j++)
            {
                p[j]=x%2;
                if(x%2==0)
                {
                    g[zero]=j;
                    zero++;
                }
                else
                {
                    g2[one]=j;
                    one++;
                }
                x/=2;
            }
            bool error[2] = {false};
            for(int j=0;j<zero;j++)
            {
                for(int k=0;k<zero;k++)
                {
                    if(dont[g[j]][g[k]])
                    {
                        error[0]=true;
                        break;
                    }
                }
                if(error[0])break;
            }
            printf("%d\n",zero);
            int min=0;
            for(int k=0;k<zero;k++)
            {
                min=k;
                for(int s=k+1;s<zero;s++)
                {
                    if(strcmp(a[g[s]],a[g[min]])<0)
                    {
                        min = s;
                    }
                }
                swap(g[k],g[min]);
            }
            for(int k=0;k<zero;k++)
            {
                printf("%s\n",a[g[k]]);
            }
            return 0;
        }
    }
}