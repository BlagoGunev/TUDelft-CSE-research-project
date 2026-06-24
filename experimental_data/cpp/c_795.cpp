#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;

int n;


/*
1 2
4 4
5 5
7 3
8 7
9 6
*/

int main(){
	while(~scanf("%d",&n)){
		int dig=n/2;//¼ÆËãÓÐ¶àÉÙÎ»
		if(n%2==1){
		printf("7");
		for(int i=1;i<dig;i++) 
			printf("1"); 
		}
		else
		for(int i=0;i<dig;i++)
			printf("1");
		printf("\n");
	}
	return 0;
}