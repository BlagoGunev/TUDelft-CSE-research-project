#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
int x[5][2], y[5][2];
void ret(int xx){
	if(xx) puts("YES");
	else puts("NO");
	exit(0);
}
int f(int idx, int sq){
	int X = x[idx][1-sq], Y = y[idx][1-sq];
	int x1 = x[0][sq], x2 = x[0][sq];
	for(int i = 1; i < 4;  i ++) x1 = min(x1,x[i][sq]);
	for(int i = 1; i < 4;  i ++) x2 = max(x2,x[i][sq]);
	if(X < x1 or X > x2) return 0;
	int y1 = y[0][sq], y2 = y[0][sq];
	for(int i = 1; i < 4;  i ++) y1 = min(y1,y[i][sq]);
	for(int i = 1; i < 4;  i ++) y2 = max(y2,y[i][sq]);
	if(Y < y1 or Y > y2) return 0;
	return 1;
}
int main(){
	for(int j = 0; j < 2; j ++) 
		for(int i = 0; i < 4; i ++) scanf("%d %d", &x[i][j], &y[i][j]);
		
	for(int sq = 0; sq < 2; sq ++) {
		for(int i = 0; i < 4; i ++) x[i][sq] *= 2;
		for(int i = 0; i < 4; i ++) y[i][sq] *= 2;
		
		int x1 = x[0][sq], x2 = x[0][sq];
		for(int i = 1; i < 4;  i ++) x1 = min(x1,x[i][sq]);
		for(int i = 1; i < 4;  i ++) x2 = max(x2,x[i][sq]);
		int y1 = y[0][sq], y2 = y[0][sq];
		for(int i = 1; i < 4;  i ++) y1 = min(y1,y[i][sq]);
		for(int i = 1; i < 4;  i ++) y2 = max(y2,y[i][sq]);
		
		x[4][sq] = x1 + (x2 - x1)/2;
		y[4][sq] = y1 + (y2 - y1)/2;
	}
	for(int i = 0; i < 5; i ++) if(f(i,0)) ret(1);
		   
	for(int j = 0; j < 2; j ++)
		for(int i = 0; i < 5; i ++){
			int s = x[i][j] + y[i][j];
			int r = y[i][j] - x[i][j];
			x[i][j] = s;
			y[i][j] = r;
		}

// 	for(int j = 0; j < 2; j ++){
// 		for(int i = 0; i < 4; i ++) printf("(%d,%d) ", x[i][j], y[i][j]);
// 		puts("");
// 	}
	for(int i = 0; i < 5; i ++) if(f(i,1)) ret(1);
	ret(0);
}