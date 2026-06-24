#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <utility>
#include <bitset>
using namespace std;

int GCD (int a, int b ) {
	if ( a==0 ) return b;
	return GCD ( b%a, a );
}

#define CetakInt(J) printf("Cetak %d\n",J);
#define CetakChar(J) printf("%c\n",J);
#define sf scanf
#define pf printf
#define FOR(a,b,c) for(int a = b; a<=c ; a++)
#define FOR1(a,b,c) for(int a = b; a<c; a++)

typedef long long int int64;

bool dsc (int i,int j) { 
	return (i>j); 
}

int main(){
	int maks  = 0;
	int m,n;
	int keluar = 0;
	int arr[5002] = {0};
	//int hasil[100003];
	scanf("%d",&m);
	FOR(i,1,m){
		sf("%d",&n);
		if(arr[n]!=2){
			++arr[n];
			++keluar;
		}
		maks = max(maks,n);
	}
	
	if(arr[maks]==2){
		keluar--;
		arr[maks] = 1;
	}
	
	printf("%d\n",keluar);
	
	FOR(i,1,maks){
		if(arr[i] > 0){
			printf("%d ",i);
			--arr[i];
		}
	}
	// printf("maks %d\n",maks);
	// printf("%d\n",arr[1]);
	// printf("%d\n",arr[2]);
	// printf("%d\n",arr[3]);
	for(int i=maks-1;i>=1;i--){
		if(arr[i] > 0){
			printf("%d ",i);
			--arr[i];
			//printf("Caca %d", i);
			//if (i>i) cout << " ";
		}
	}
	//printf("Asfas");
	pf("\n");
	
	return 0;
}