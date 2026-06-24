#include<bits/stdc++.h>

using namespace std;

int main(){



    int  n,k;

    cin>>n>>k;



    if(n==1&&k==0){

        cout<<1<<endl;

        return 0;

    }

    if(n/2>k||n==1){

        printf("-1\n");

        return 0;

    }

    int a=n/2;

    a=k-n/2+1;

    printf("%d %d",a,a*2);

int     s=n*1000+3;

    n-=2;

    while(n--)

    {

        printf(" %d",s);

        s++;

    }

cout<<endl;

}