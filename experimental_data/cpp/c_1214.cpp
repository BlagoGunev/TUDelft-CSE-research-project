#include<stdio.h>
int main(){
	char a[210010];
	int cnt1=0,cnt2=0;
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	if(n%2!=0){
	printf("No\n");
	return 0;}
	int m1=0,m2=0;
   for(int i=0;i<n;i++) {
   	if(a[i]=='(') cnt1++;
   	if(a[i]==')') cnt2++;
   }
   if(cnt1!=cnt2){
	printf("No\n");
	return 0;}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(') m1++;
		else  m2++;
		if(m2>m1+1){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}