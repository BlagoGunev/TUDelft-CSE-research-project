#include<cstdio>

#include<cstring>

using namespace std;

const int N = 110;

int n,m;

char s[N][N],ss[N];

int flag[N],num[N];



int main(){

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

		scanf("%s",s[i]+1);

	for(int i=1;i<=m;i++){

		scanf("%d",&num[i]);

		flag[num[i]]=1;

	}

	int len=strlen(s[num[1]]+1),ll=len;

	for(int i=1;i<=len;i++) ss[i]=s[num[1]][i];

	for(int i=2;i<=m;i++){

		len=strlen(s[num[i]]+1);

		if(ll!=len) {printf("No\n");return 0;}

		for(int j=1;j<=len;j++){

			if(ss[j]!=s[num[i]][j]) ss[j]='?';  

		}

	}

	bool _flag;

	for(int i=1;i<=n;i++){

		if(flag[i]) continue;

		_flag=1;

		len=strlen(s[i]+1);

		if(ll!=len) continue;

		for(int j=1;j<=len;j++){

			if(ss[j]=='?') continue;

			if(ss[j]!=s[i][j]) {_flag=0;break;}

		}

		if(_flag) {printf("No\n");return 0;}

	}

	printf("Yes\n");

	printf("%s\n",ss+1);

	return 0;

}