#include<stdio.h>
#include<string.h>
using namespace std;
char a[10][10];
int fx[8]={1,-1,0,0,1,-1,1,-1};
int fy[8]={0,0,1,-1,1,-1,-1,1};
int judge()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]=='x')
            {
                for(int z=0;z<8;z++)
                {
                    int flag=0;
                    for(int k=1;k<=2;k++)
                    {
                        int xx=i+fx[z]*k;
                        int yy=j+fy[z]*k;
                        if(xx>=0&&xx<4&&yy>=0&&yy<4)
                        {
                            if(a[xx][yy]=='x')continue;
                            else flag=1;
                        }
                        else flag=1;
                    }
                    if(flag==0)return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    memset(a,'.',sizeof(a));
    for(int i=0;i<4;i++)
    {
        scanf("%s",a[i]);
    }
    int flag=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j]=='.')
            {
                a[i][j]='x';
                int tmp=judge();
                a[i][j]='.';
                if(tmp==1)flag=1;
            }
        }
    }
    if(flag==1)printf("YES\n");
    else printf("NO\n");
}
/*
#include<stdio.h>
#include<string.h>
using namespace std;
int a[150];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=0)flag=1;
        }
        if(flag==0)
        {
            printf("NO\n");
            continue;
        }
        int sum=0;
        printf("YES\n");
        int l=1;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum!=0)
            {
                sum=0;
                printf("%d %d\n",l,i);
                l=i+1;
            }
        }
    }
}
*/