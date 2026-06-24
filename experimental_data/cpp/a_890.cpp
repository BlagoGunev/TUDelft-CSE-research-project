#include <bits/stdc++.h>

using namespace std;

bool valid;
int tot;
int a[6];

void f(int n,int val,int cont){
	if(val*2==tot && cont ==3)valid = true;
	if(n ==6) return;
	f(n+1,val,cont);
	f(n+1,val+a[n],cont+1);
}


int main(){
	tot=0;
	for(int i=0;i<6;i++){
		scanf("%d",a+i);
		tot+=a[i];
	}
	valid = false;
	f(0,0,0);
	printf(valid?"YES":"NO");
}