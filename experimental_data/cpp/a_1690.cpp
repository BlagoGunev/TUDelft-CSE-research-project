#include <iostream>

int main(){

    int t,n,k;

    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);

        k=n%3;n-=k;

        printf("\t%d %d %d\n",n/3+ (k==2), n/3 + 1 + (k!=0),n/3 - 1);

    }

}