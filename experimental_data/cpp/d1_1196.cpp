#include<iostream>
using namespace std;

int q,n,k,a[3000];
char ch[10000];

int go(int s){
	for(int i=0;i<3000;i++)a[i]=0;
	for(int i=0;i<n;i++){
		if(s==4)s=1;
		if(ch[i]!='R'&&s==1)a[i]=1;
		if(ch[i]!='G'&&s==2)a[i]=1;
		if(ch[i]!='B'&&s==3)a[i]=1;
		s++;
	}
	int sum=0,minm=10000;
	for(int i=0;i<=n-k;i++){
		sum=0;
		for(int j=i;j<i+k;j++){
			sum+=a[j];
		}
		if(sum<minm)minm=sum;
	}
	
	return minm;
}

int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k);
		scanf("%s",ch);
		int a1=go(1);
		int a2=go(2);
		int a3=go(3);
		if(a1<=a2&&a1<=a3)printf("%d\n",a1);
		else if(a2<=a1&&a2<=a3)printf("%d\n",a2);
		else if(a3<=a2&&a3<=a1)printf("%d\n",a3);
	}
	return 0;
}