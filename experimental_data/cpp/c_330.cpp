#include<cstdio>
#include<cstdlib>
#include<cstring>

char a[101][101];
int main()
{
    int i,j,n,err,p,cnt;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            err=1;
            for(p=0;p<n;p++)
            {
                if(a[i][p]=='.')
                {
                    err=0; break;
                }
            }
            //printf("till here\n");
            if(err)
            {
                for(p=0;p<n;p++)
                {
                    if(a[p][j]=='.')
                    {
                        err=0; break;
                    }
                }
            }
            if(err) break;
        }
        if(err) break;
    }
    //printf("till here\n");
    if(err) printf("-1\n");
    else
    {
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='.') {cnt++; break;}
            }
        }
        if(cnt==n)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    {
                        if(a[i][j]=='.') {printf("%d %d\n",i+1,j+1);break;}
                    }
                }
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(a[j][i]=='.') {printf("%d %d\n",j+1,i+1);break;}
                }
            }
        }
    }
    return 0;
}