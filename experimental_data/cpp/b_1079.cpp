//cf.cpp
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>
#include <stack>
#include <bitset>
#include <utility>
#define mp make_pair
#define pb push_back
#define llc (long long)
#define pob pop_back
#define pm %1000000007
using namespace std;

int modex(int b, int e){
	int h = 1;
	while(e){
		if(e&1)h=llc h*b pm;
		b=llc b*b pm;
		e>>=1;
	}
	return h;
}

int main(){
	char c[101];
	int len = 0;
	while(true){
		c[len]=getchar();
		if(c[len]=='\n'||c[len]==EOF)
			break;
		len++;
	}
	int r, cn;
		r=(len+19)/20;
		cn=(len+r-1)/r;
	char p[r][cn];
	for(int i = 0;i < r;i ++){
		for(int j = 0;j < cn;j ++){
			p[i][j]='.';
		}
	}
	for(int i = 0;i < r*cn-len;i ++){
		p[(i+i/cn)%r][i%cn]='*';
	}
	len=0;
	for(int i = 0;i < r*cn;i ++){
		if(p[i/cn][i%cn]=='.'){p[i/cn][i%cn]=c[len];len++;}
	}
	printf("%d %d\n",r,cn);
	for(int i = 0;i < r;i ++){
		for(int j = 0;j < cn;j ++){
			cout<<p[i][j];
		}
		cout<<"\n";
	}
}