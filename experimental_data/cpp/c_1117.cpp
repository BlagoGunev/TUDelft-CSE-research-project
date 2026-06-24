#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAXN = 100000 + 10;

long long sx, sy;
long long ex, ey;

int n;
char Data[MAXN];

long long deltax[MAXN], deltay[MAXN];
long long x, y;

inline long long dabs(long long x){
	if(x < 0)
		return -x;
	return x;
}

inline bool check(long long round){
	long long base = round / n;
	long long left = round % n;
	
	long long totx = x * base + deltax[left];
	long long toty = y * base + deltay[left];
	
	if(dabs(ex - (sx + totx)) + dabs(ey - (sy + toty)) <= round)
		return true;
	return false;
}

int main(){
	scanf("%lld%lld%lld%lld%d", &sx, &sy, &ex, &ey, &n);
	scanf("%s", Data+1);	
	
	for(register int i=1; i<=n; i++){
		if(Data[i] == 'U')
			y++;
		else if(Data[i] == 'D')
			y--;
		else if(Data[i] == 'L')
			x--;
		else
			x++;
	}
	
	for(register int i=1; i<=n; i++){
		deltax[i] = deltax[i-1];
		deltay[i] = deltay[i-1];
		
		if(Data[i] == 'U')
			deltay[i] = deltay[i-1] + 1;
		else if(Data[i] == 'D')
			deltay[i] = deltay[i-1] - 1;
		else if(Data[i] == 'L')
			deltax[i] = deltax[i-1] - 1;
		else
			deltax[i] = deltax[i-1] + 1;
	}
	
	long long l = 0;
	long long r = 2e18;
	
	while(l < r){
		long long mid = (l + r) >> 1;
		
		if(check(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	} 
	
	if(l == -1 || l == 2e18)
		l = -1;
	
	printf("%lld", l);
	return 0;
}