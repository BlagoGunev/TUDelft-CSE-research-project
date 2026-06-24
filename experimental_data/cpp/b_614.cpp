#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char A[100000+5],B[100000+5];

int main()
{
        int n;
        while(scanf("%d",&n)==1)
        {
                int ans=0,m=1,k=0;
                memset(B,'\0',sizeof(B));
                while(n--)
                {
                        scanf("%s",A);
                        if(A[0]=='0')
                                ans=-1;
                        if(ans==-1)
                                continue;

                        int len=strlen(A);
                        if(k)
                        {
                                ans+=len-1;
                        }
                        else
                        {
                                for(int i=0,num=0;A[i]!='\0'&&!k;i++)
                                {
                                        if(A[i]=='1')
                                                num++;
                                        if(A[i]!='1'&&A[i]!='0')
                                                k=1;
                                        if(num>1)
                                                k=1;
                                }
                                if(k)
                                        strcpy(B,A);
                                else
                                        ans+=len-1;
                        }
                }
                if(ans!=-1)
                {
                        if(k)
                                printf("%s",B);
                        else
                                printf("1");
                        for(int i=0;i<ans;i++)
                                printf("0");
                }
                else
                        printf("0");
                printf("\n");
        }
}