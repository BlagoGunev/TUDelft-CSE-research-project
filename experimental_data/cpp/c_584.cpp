#include<stdio.h>
#include<string.h>
#include<stack>
#include<string>
#include<math.h>
#include<queue>
#include<set>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define LL __int64
#define inf 1999999999
#define N 100010
#define mod 1000000007
char s1[N],s2[N],s3[N];
int main()
{
    int i,j,n,m,num=0;
    scanf("%d%d",&n,&m);
    scanf("%s%s",s1,s2);
    for(i=0;i<n;i++) num+=s1[i]==s2[i];
 //   printf("%d\n",num);
    num=n-num;
    int tmp=(num+1)/2;
    if(tmp>m)
    {
        puts("-1");
        return 0;
    }
    if(num>m)
    {
        int flag=0;
        for(i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
                s3[i]=s1[i];
            else
            {
                if(num==m)
                {
                    s3[i]=(s1[i]-'a'+1)%26+'a';
                    if(s3[i]==s2[i])
                        s3[i]=s3[i]=(s1[i]-'a'+2)%26+'a';
                    num--;m--;
                    continue;
                }
                if(flag==0)
                {
                    s3[i]=s1[i];
                    flag=1;
                    m--;
                }
                else
                {
                    s3[i]=s2[i];
                    flag=0;
                }
                num--;
            }
        }
        s3[n]=0;
        printf("%s\n",s3);
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(s1[i]==s2[i])continue;
        s3[i]=(s1[i]-'a'+1)%26+'a';
        if(s3[i]==s2[i])
            s3[i]=s3[i]=(s1[i]-'a'+2)%26+'a';
    }
    m-=num;
    for(i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])continue;
        if(m>0)
        {
            s3[i]=s3[i]=(s1[i]-'a'+1)%26+'a';
            m--;
        }
        else s3[i]=s1[i];
    }
    s3[n]=0;
    printf("%s\n",s3);
    return 0;
}