/* hanhanw v1.1 */
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

struct QQ{
	int x[4];
}tmp;
int n,ok[10],us[10];
char s[1000];
vector<QQ> ans;

bool operator == (QQ a, QQ b){
	REP(i,0,3)
		if (a.x[i] != b.x[i])
			return 0;
	return 1;
}
bool operator < (QQ a, QQ b){
	REP(i,0,3)
		if (a.x[i] != b.x[i])
			return a.x[i] < b.x[i];
	return a.x[3] < b.x[3];
}
inline void get_ans(char str[], int len){
	REP(i,0,len-1)
		if (str[i] != str[len-i-1])
			return ;
	int res1=0;
	REP(i,0,len-4){
		res1 = res1*10 + str[i];
		if (res1 > 255) break;
		int res2=0;
		REP(j,i+1,len-3){
			res2=res2*10+str[j];
			if (res2 > 255) break;
			int res3=0;
			REP(k,j+1,len-2){
				res3=res3*10+str[k];
				int res4=0;
				if (res3 > 255) break;
				REP(l,k+1,len-1)
					res4=res4*10+str[l];
				if (res4 > 255)
					continue;
				int cnt=0;
				tmp.x[0]=res1;
				tmp.x[1]=res2;
				tmp.x[2]=res3;
				tmp.x[3]=res4;
				REP(l,0,3){
					int v=tmp.x[l];
					if (v==0)
						cnt++;
					while (v){
						cnt++;
						v /=10;
					}
				}
				if (cnt != len)
					continue;
				//printf("%d %d %d\n", i, j, k);
				//printf("%d.%d.%d.%d\n", tmp.x[0], tmp.x[1], tmp.x[2], tmp.x[3]);
			//	system("pause");
				ans.PB(tmp);
			}
		}
	}
}
void dfs(int cur, int len){
	if (cur >= len){
		REP(i,0,9)
			if (ok[i] && !us[i])
				return ;
		int ptr=len;
		get_ans(s,ptr);
		FORD(i,len-1,0)
			s[ptr++] = s[i];
		get_ans(s,ptr);
		ptr=len;
		FORD(i,len-2,0)
			s[ptr++] = s[i];
		get_ans(s,ptr);
		return ;
	}
	REP(i,0,9){
		if (ok[i]){
			s[cur]=i;
			us[i]++;
			dfs(cur+1,len);
			us[i]--;
		}
	}
}

int main(){
	while (~scanf("%d", &n)){
		MSET(ok,0);
		ans.clear();
		REP(i,1,n){
			int x; scanf("%d", &x);
			ok[x] = 1;
		}
		MSET(us,0);
		REP(i,0,6)
			dfs(0,i);
		sort(ans.begin(),ans.end());
		if (ans.SZ() == 0){
			puts("0");
			continue;
		}
		int na=1;
		
		REP(i,1,(int)ans.SZ()-1)
			if (!(ans[i] == ans[i-1]))
				ans[na++]=ans[i];
		
	//	na=ans.SZ();
		printf("%d\n", na);
		REP(i,0,na-1)
			printf("%d.%d.%d.%d\n", ans[i].x[0],ans[i].x[1],ans[i].x[2],ans[i].x[3]);
	}

	return 0;
}