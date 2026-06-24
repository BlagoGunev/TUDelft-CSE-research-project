#include <stdio.h>


int main(){
int a[100000];
int a1[100000];
int t[17];
int n,i,j,k;
long long int turn;

scanf("%d", &n);
for (i=0;i<n;i++){
	scanf("%d", &a[i]);
	a1[i]=a[i];
}
t[0]=1;
for(i=1;i<17;i++){
	t[i]=t[i-1]*2;
}
turn=0;
for(k=1;k<n;k++){
	for(j=16;j>-1;j--){
		if(k-1+t[j]<n){
			turn=turn+a[k-1];
			a[k-1+t[j]]=a[k-1+t[j]]+a[k-1];
			a[k-1]=0;
			j=-1;
		}
	}
	printf("%I64d\n",turn);
}


	return 0;
}