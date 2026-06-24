#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j;
    char s[100001];
    while(scanf("%lld",&n)==1)
    {
        getchar();
        scanf("%s",s);
        ll l=n;
        ll c;
        for(i=0;i<l;i++)
        {
            if(s[i]=='a')
            {
                printf("%c",s[i]);
                for(j=i+1;j<l;j++)
                {
                    if(s[j]!='a')
                    {
                        break;
                    }
                }
                i=j-1;
            }
            else if(s[i]=='e')
            {
                c=0;
                printf("%c",s[i]);
                for(j=i+1;j<l;j++)
                {
                    if(s[j]!='e')
                    {
                        break;
                    }
                    else
                    {
                        c++;
                    }
                }
                i=j-1;
                if(c==1)
                {
                    printf("%c",s[i]);
                }

            }
            else if(s[i]=='i')
            {
                printf("%c",s[i]);
                for(j=i+1;j<l;j++)
                {
                    if(s[j]!='i')
                    {
                        break;
                    }
                }
                i=j-1;
            }
            else if(s[i]=='o')
            {
                c=0;
                printf("%c",s[i]);
                for(j=i+1;j<l;j++)
                {
                    if(s[j]!='o')
                    {
                        break;
                    }
                    else
                    {
                        c++;
                    }
                }
                i=j-1;
                if(c==1)
                {
                    printf("%c",s[i]);
                }
            }
            else if(s[i]=='u')
            {
                printf("%c",s[i]);
                for(j=i+1;j<l;j++)
                {
                    if(s[j]!='u')
                    {
                        break;
                    }
                }
                i=j-1;
            }
            else if(s[i]=='y')
            {
                printf("%c",s[i]);
                for(j=i+1;j<l;j++)
                {
                    if(s[j]!='y')
                    {
                        break;
                    }
                }
                i=j-1;
            }
            else
            {
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}