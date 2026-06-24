#include<cstdio>

#include<cstring>

#include<set>

#include<algorithm>

#include<iostream>

using namespace std;

int ss[1000];

int main()

{

    int a,b,c;

    int k=0;

    scanf("%d%d%d",&a,&b,&c);

    for(int i=1;i<=81;i++)

    {

        int bbb=b;

        for(int j=1;j<=a;j++)

            bbb*=i;

        int ans=c+bbb;  

        int tans=ans;   

        if(ans<=0) continue;

        if(ans>=1000000000) break;

        int sum=0;

        while(ans){

            sum+=ans%10;

            ans/=10;

        }

        if(sum==i){

            ss[k++]=tans;

        }

    }

    if(ss[0]==0) printf("0\n");

    else{

        printf("%d\n",k);

        for(int i=0;i<k;i++)

        {

           if(i==k-1) printf("%d\n",ss[i]);

           else       printf("%d ",ss[i]);

        }

    }

    return 0;

}