#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
int A[50][50];

int main(int argc, char *argv[]){
	int n,m;
	scanf("%d%d", &n, &m);
	memset(A, 0, sizeof(A));
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		A[a][b]=A[b][a]=1;
	}
	for(int k=0;k<n;++k){
		A[k][k]=1;
	}
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(A[i][k] && A[k][j]){
					A[i][j]=1;
					A[j][i]=1;
				}
			}
		}
	}
	
	int cnt[50];
	memset(cnt, 0, sizeof(cnt));
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(A[i][j]==1){
				cnt[i]++;
			}
		}
		if(cnt[i]>3){
			printf("-1\n");
			return 0;
		}
	}
	int npairs=0;
	int nsingles=0;
	for(int i=0;i<n;++i){
		if(cnt[i]==2){
			++npairs;
		}else if(cnt[i]==1){
			++nsingles;
		}
	}
	if(nsingles*2<npairs){
		printf("-1\n");
		return 0;
	}
	bool used[50];
	memset(used, 0, sizeof(used));
	for(int i=0;i<n;++i)if(!used[i]){
		if(cnt[i]==3){
			for(int j=0;j<n;++j)if(A[i][j]){
				used[j]=true;
				printf("%d ", j+1);
			}
			printf("\n");
		}else if(cnt[i]==2){
			bool ok=false;
			for(int j=0;j<n;++j){
				if(A[i][j]){
					printf("%d ", j+1);
					used[j]=true;
				}else if((!ok)&&(cnt[j]==1) && (!used[j])){
					printf("%d ", j+1);
					used[j]=true;
					ok=true;
				}
			}
			printf("\n");
		}
	}
	int c=0;
	for(int i=0;i<n;++i)if((!used[i])&&(cnt[i]==1)){
		printf("%d ", i+1);
		++c;
		if((c%3)==0){
			printf("\n");
		}
	}
	return 0;
}