#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n,k,l,c,d,p,nl,np,s=0;
  scanf("%u%u%u%u%u%u%u%u",&n,&k,&l,&c,&d,&p,&nl,&np);
  int ll=k*l,dd=c*d;
  while(ll>0&&dd>0&&p>0){
		ll-=nl*n;
		dd-=n;
		p-=np*n;
		if(ll>=0&&dd>=0&&p>=0) s++;	
	}
  printf("%i",s);
}