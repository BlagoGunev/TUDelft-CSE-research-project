#include <iostream>

#include <cstring>

#include <cstdio>

using namespace std;

typedef long long LL;

const int MXN = 100;

char s[MXN];

char ss[MXN];

char ans[2][MXN];

int z['Z'+1];

bool work(char* s){

	memset(z,-1,sizeof(z));

	int a,b;

	for(int i=0;i<27;i++){

		if(z[s[i]] != -1){

			a = z[s[i]];

			b = i;

			break;

		}

		z[s[i]] = i;

	}

	if(b == a+1){

		return 0;

	}

	if((b-a)%2 == 0 && a==27-b-1){

		int cur = 0;

		for(int i=0;i<=a;i++,cur++){

			ans[1][i] = s[cur];

		}		

		for(int i=a;i<13;i++,cur++){

			ans[0][i] = s[cur];	

		}

		for(int i=12;i > a &&cur != b;i--,cur++){

			ans[1][i] = s[cur];

		}

		cur ++;

		for(int i=a-1;i>=0;i--,cur++){

			ans[0][i] = s[cur];

		}

		return 1;

	}else if((b-a)%2==1 && a==27-b-1-1){

		int cur = 0;

		for(int i=0;i<=a;i++,cur++){

			ans[1][cur] = s[i];

		}

		for(int i=a+1;i<13;i++,cur++){

			ans[0][i] = s[cur];

		}

		for(int i=12;cur != b;i--,cur++){

			ans[1][i] = s[cur];

		}

		cur = b+1;

		for(int i=a;cur<27;i--,cur++){

			ans[0][i] = s[cur];

		}

		return 1;

	}else{

		return 0;

	}



}

int main(){

	scanf("%s",s);

	int n = strlen(s);

	memset(z,-1,sizeof(z));

	int a,b;

	for(int i=0;i<27;i++){

		if(z[s[i]] != -1){

			a = z[s[i]];

			b = i;

			break;

		}

		z[s[i]] = i;

	}

	if(b == a+1){

		puts("Impossible");

		return 0;

	}

	bool ok = 0;

	for(int i=0;i<n;i++){

		for(int j=i;j<n;j++)

			ss[j-i] = s[j];

		for(int j=0;j<i;j++)

			ss[n-i+j] = s[j];

		if(work(ss)){

			ok = 1;	

		}

	}

	if(ok){

		printf("%s\n%s\n",ans[0],ans[1]);	

	}else{

		puts("Impossible");

	}



	return 0;

}