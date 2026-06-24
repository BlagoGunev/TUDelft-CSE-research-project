#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int n,a[5],x[5];
char c[1111];
int main(){
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	scanf("%s",c);
	n=strlen(c);
	for(int q=0;q<n;q++){
		if(c[q]=='R')x[1]=q%4+1;
		if(c[q]=='B')x[2]=q%4+1;
		if(c[q]=='Y')x[3]=q%4+1;
		if(c[q]=='G')x[4]=q%4+1;
		if(c[q]=='!')a[q%4+1]++;
		
	}
	
	for(int q=1;q<=3;q++)
	  printf("%d ",a[x[q]]);
	printf("%d\n",a[x[4]]);
	
	return 0;
}