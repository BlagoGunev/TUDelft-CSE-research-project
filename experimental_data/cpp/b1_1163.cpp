#include<bits/stdc++.h>
using namespace std;
int num[100005];
int main()
{
    int cat=0;
    int n;
    scanf("%d",&n);
    int ans=1;
    int MAX=0;
    int MIN=1e9;
    int num1=0;
    int num2=0;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(num[tmp]==0) cat++,num1++;
        if(num[tmp]==1) num1--;
        num[tmp]++;
        if(num[tmp]==MAX) num2++;
        if(num[tmp]>MAX) MAX=num[tmp],num2=1;
        if((MAX-1)*cat+1==i&&num2==1||(MAX)*(cat-1)+1==i&&num1==1||cat==i||cat==1) ans=i;
    }
    printf("%d\n",ans);
}