#include<cstdio>
#include<cstring>

int o[110000],o2[110000],L,K,t,t2,s[110000];

long long  Sum[30];

char Chr;

int main()
{   int i,k;
    for(;(Chr=getchar())>='a';s[L++]=Chr-'a'+1);
    scanf("%d",&K);
    t=L;
    K+=L;
    for(i=0;i<L;i++)o[i]=i-1;
    for(;;)
    {   memset(Sum,0,sizeof Sum);
        Sum[0]=t;
        for(i=0;i<t;i++)Sum[s[o[i]+1]]+=L-o[i]-1;
        if(K<=Sum[0])break;
        for(k=0;k<27;k++)if(K>Sum[k])K-=Sum[k];else break;
        if(k==27)
        {   puts("No such line.");
                return 0;
        }
        t2=0;
        for(i=0;i<t;i++)if(s[o[i]+1]==k)o2[t2++]=o[i]+1;
        for(i=0;i<t2;i++)o[i]=o2[i];
        t=t2;
        putchar('a'+k-1);
    }
    putchar('\n');
    return 0;
}