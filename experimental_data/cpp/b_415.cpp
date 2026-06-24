#include<stdio.h>
long long n,a,b,k,i,l;
main(){
       scanf("%ld%ld%ld",&n,&a,&b);
       for(i=1;i<=n;i++){scanf("%ld",&k);l=(k*a%b)/a;if(k*a/b==0)l=k;printf("%ld ",l);}
       //while(1){};
}