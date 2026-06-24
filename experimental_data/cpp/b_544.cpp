#include<cstdio>

const int maxn=107;

char map[maxn][maxn];int n,cnt,k;

bool judge(){

	cnt=0;

	for(int i=0,p=1;i<n&&cnt!=k;++i,p^=1)

	  for(int j=0;j<n&&cnt!=k;++j)

	  	if((j+p)%2==0)map[i][j]='L',cnt++;

	if(cnt!=k){

		cnt=0;

		for(int i=0;i<n;++i)for(int j=0;j<n;++j)map[i][j]='S';

		for(int i=0,p=1;i<n&&cnt!=k;++i,p^=1)

		  for(int j=0;j<n&&cnt!=k;++j)

		    	if((p+j)%2==1)map[i][j]='L',cnt++;              

		if(cnt!=k)return false;

		else return true;

	}else return true;

}

int main(){

	scanf("%d%d",&n,&k);

	for(int i=0;i<n;++i)for(int j=0;j<n;++j)map[i][j]='S';

	if(judge()){

		puts("YES");

		for(int i=0;i<n;++i)puts(map[i]);

	}

	else puts("NO");

	return 0;

}