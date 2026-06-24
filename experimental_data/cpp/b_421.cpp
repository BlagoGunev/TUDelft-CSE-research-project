#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

char str2[100020];
int main()
{
    char str1[15]={'W','T','Y','U','I','O','A','H','X','V','M'};
    int j,i;
    while(~scanf("%s",str2))
    {
        int len=strlen(str2);
        int flag=0;
        for(i=0;i<len/2;i++)
        {
            if(str2[i]!=str2[len-1-i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("NO\n");
        }
        else
        {
            for(i=0;i<=len/2;i++)
            {
                flag=0;
                for(j=0;j<11;j++)
                {
                    if(str2[i]==str1[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0) break;
            }
            if(flag==0) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}