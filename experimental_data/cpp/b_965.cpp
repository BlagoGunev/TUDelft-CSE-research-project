#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

char ship[100][101];
int N, cnt[100][100];

bool valid_coord(int x, int y)
{
	return 0<=x && x<N && 0<=y && y<N;
}

int main()
{
	//ios_base::sync_with_stdio(false);
#ifdef NON_SUBMIT
#ifdef COMPARE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#endif
	int K, x=0, y=0;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) {
		scanf("%s",ship[i]);
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			bool Down=true, Right=true;
			for(int k=0;k<K;k++) {
				if(!valid_coord(i,j+k) || ship[i][j+k]=='#') {
					Right=false;
				}
				if(!valid_coord(i+k,j) || ship[i+k][j]=='#') {
					Down=false;
				}
			}
			for(int k=0;k<K;k++) {
				if(Right) {
					cnt[i][j+k]++;
				}
				if(Down) {
					cnt[i+k][j]++;
				}
			}
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(cnt[i][j]>cnt[x][y]) {
				x=i;
				y=j;
			}
		}
	}
	printf("%d %d\n",x+1,y+1);
#ifdef NON_SUBMIT
#ifndef COMPARE
	system("PAUSE");
#endif
#endif
    return 0;
}