//#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 10000

main()
{
    //freopen("a.txt","r",stdin);
    int i,j,a[MAX],b[MAX],n,check,count=0,l,r,u,d;
    
	scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
    //for(i=0;i<n;i++) printf("%d %d\n",a[i],b[i]);
    
    for(i=0;i<n;i++){
		check=0;
		l=0;
		u=0;
		r=0;
		d=0;
    	for(j=0;j<n;j++)
			if(i!=j){
			
			if(a[i]==a[j]&&b[i]>b[j]) {check++;l=1;}
			if(a[i]==a[j]&&b[i]<b[j]) {check++;u=1;}
			if(a[i]<a[j]&&b[i]==b[j]) {check++;r=1;}
			if(a[i]>a[j]&&b[i]==b[j]) {check++;d=1;}
			
			}
		if(check>=4&&l==1&&d==1&&r==1&&u==1) {
			count++;
			//printf("%d %d\n",a[i],b[i]);
		}
	}
    
    printf("%d",count);
    
    //getch();
}