#include<stdio.h>

char a[1000005],b[1000005];
int cnt,now,ans;

int main(){
	int i;
//	gets(a);
//	gets(b);
	char c=getchar();
	int k=0;
	while  ((c=='0')||(c=='1')) {
		a[k]=c;
		k++;
		c=getchar();
	}
	int t=0;
	c=getchar();
	while  ((c=='0')||(c=='1')) {
		b[t]=c;
		t++;
		c=getchar();
	}
	for (i=1;i<t;i++) if (b[i-1]!=b[i]) cnt++;
	cnt=cnt%2;
	for (i=0;i<t;i++) if (b[i]!=a[i]) now++;
	if (now%2==0) ans++;
	now=now%2;
	for (i=t;i<k;i++) {
		now+=cnt;
		if (a[i]!=b[t-1]) now++;
		if (a[i-t]!=b[0]) now++;
		if (now%2==0) ans++;
		now=now%2;
	}
	printf("%d",ans);
	return 0;
}