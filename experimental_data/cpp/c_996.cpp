///////////////////////////
//         INFO          //
//                       //
//    Handle -> Scayre   //
//                       //
//   Template vers. 1.0  //
//                       //
//   The only way is up  //
//                       //
///////////////////////////

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <complex>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);

#define f first
#define s second

#define inf (int)1e9 + 7

#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define mp(x,y) make_pair(x,y)

#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)

#define pb push_back
#define ppb pop_back

#define endl "\n"

#define in(x) insert(x)

#define sz(x) (int)x.size()

#define all(x) x.begin(),x.end()

#define pw2(x) (1<<x) //2^x

#define forit(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

#define sqr(x) ((x) * 1ll * (x))

using namespace std;

const int N = (int)5e5 + 7, MOD = (int)1e9 + 7;

struct step
{
	int cr,rw,cl;	
};

int n,k,st,cnt;

int a[4][55],b[104][2],p[104][2],d[104];

step st1;

vector <step> s;

int main(){

	#ifdef IOI2019
		freopen ("in.txt", "r", stdin);
	#endif

	NFS

	cin >> n >> k;
	
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(i==0||i==3){
				p[a[i][j]][0]=i;
				p[a[i][j]][1]=j;
			}
			else{
				b[a[i][j]][0]=i;
				b[a[i][j]][1]=j;
			}
		}
			
	if(k==2*n){
		int f=0;
		for(int i=1;i<=k;i++)
			if(b[i][0]==1 && p[i][0]==0 && b[i][1]==p[i][1] || b[i][0]==2 && p[i][0]==3 && b[i][1]==p[i][1]){
				f=1; 
				break;
			}
	
		if(!f){
			cout << -1 << endl;
			ioi
		}
	}
	
	for(int i=1;i<=k;i++)
		if(b[i][0]==1 && p[i][0]==0 && b[i][1]==p[i][1]){
			st++;
			st1.cr=i;
			st1.rw=1;
			st1.cl=b[i][1]+1;
			s.pb(st1);
			d[i]=1;
			cnt++;
			a[b[i][0]][b[i][1]]=0;
			a[p[i][0]][p[i][1]] = 0;
			b[i][0]=b[i][1]=p[i][0]=p[i][1]=-1;
		}
		else if(b[i][0]==2 && p[i][0]==3 && b[i][1]==p[i][1]){
			st++;
			st1.cr=i;
			st1.rw=4;
			st1.cl=b[i][1]+1;
			s.pb(st1);
			d[i]=1;
			cnt++;
			a[b[i][0]][b[i][1]]=0;
			a[p[i][0]][p[i][1]]=0;
			b[i][0]=b[i][1]=p[i][0]=p[i][1]=-1;
		}
		
	while(cnt < k){
		int fx =-1,fy=-1,px,py,cx,cy;
		for(int i=0;i<n;i++)
			if(a[1][i]==0){
				fx=1;
				fy=i;
				break;
			}
			
		for(int i=0;i<n && fx<0;i++)
			if(a[2][i]==0){
				fx=2;
				fy=i;
				break;
			}
			
		px=fx;
		py=fy;
		if(fx==1){
			if(fy==n-1){
				cx=2;
				cy=n-1;
			}
			else{
				cx=1;
				cy=fy+1;
			}
		}
		else{
			if(fy==0){
				cx=1;
				cy=0;
			}
			else{
				cx=2;
				cy=fy-1;
			}
		}
		
		while(cx!=fx || cy!=fy){
			swap(a[cx][cy],a[px][py]);
			
			if(a[px][py]){
				st++;
				st1.cr=a[px][py];
				st1.rw=px+1;
				st1.cl=py+1;
				s.pb(st1);
				b[a[px][py]][0]=px;
				b[a[px][py]][1]=py;
			}
			px=cx;
			py=cy;
			if(px==1){
				if(py==n-1){
					cx=2;
					cy=n-1;
				}
				else{
					cx=1;
					cy=py+1;
				}
			}
			else{
				if(py==0){
					cx=1;
					cy=0;
				}
				else{
					cx=2;
					cy=py-1;
				}
			}
		}
		
		for(int i=1;i<=k;i++)
			if(b[i][0]==1 && p[i][0]==0 && b[i][1]==p[i][1]){
				st++;
				st1.cr=i;
				st1.rw=1;
				st1.cl=b[i][1]+1;
				s.pb(st1);
				d[i]=1;
				cnt++;
				a[b[i][0]][b[i][1]]=0;
				a[p[i][0]][p[i][1]]=0;
				b[i][0]=b[i][1]=p[i][0]=p[i][1]=-1;
			}
			else if(b[i][0]==2 && p[i][0]==3 && b[i][1]==p[i][1]){
				st++;
				st1.cr=i;
				st1.rw=4;
				st1.cl=b[i][1]+1;
				s.pb(st1);
				d[i]=1;
				cnt++;
				a[b[i][0]][b[i][1]]=0;
				a[p[i][0]][p[i][1]]=0;
				b[i][0]=b[i][1]=p[i][0]=p[i][1]=-1;
			}
	}
	
	cout << st << endl;
	
	for (int i=0;i<st;i++){
		cout << s[i].cr << ' ' << s[i].rw << ' ' << s[i].cl << endl;
	}

	#ifdef IOI2019
		cout << "\nTime Elapsed : " << clock () * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	ioi
}