#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <list>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;


//----------------------zjut_DD for Topcoder-------------------------------
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define two(w) (1<<(w))
#define test(x,w) (x&two(w))
#define sz(v) (int)v.size()
#define all(c) c.begin(),c.end() 
#define clr(buf,val) memset(buf,val,sizeof(buf))
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define repv(i,v)  for(int i=0;i<(int)v.size();i++)
#define repi(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
//------------------------------------------------------------------------

#define maxn 110000
int a[maxn], b[maxn];

int n;
LL k;

typedef int type;
struct IndexArray{
	type s[maxn+5]; int N;
	void init(int n){
		N=n; fill(s,s+n+1,0);
	}
	int lowbit(int t){ return t&(-t); }
	void update(int i,type val){
		while( i<=N ){
			s[i]+=val; i+=lowbit(i);
		}
	}
	type get_sum(int i){
		type ret=0;
		while( i>0 ){
			ret+=s[i]; i-=lowbit(i);
		}
		return ret;
	}
}bit1, bit2;//*************ģ�����*****************

int force(){
	int ans=0;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
		VI v;
		for(int p=1;p<=i;p++) v.PB(a[p]);
		for(int p=j;p<=n;p++) v.PB(a[p]);
		int sum=0;
		for(int i=0;i<sz(v);i++) for(int j=0;j<i;j++) if( v[i]<v[j] ) sum++;
		if( sum<=k ) ans++;
	}
	printf("ans=%d\n", ans);
	return ans;
}

int main(){
	
	while( cin>>n>>k ){
		for(int i=1;i<=n;i++){
			scanf("%d", a+i);
			//a[i]=rand();
			b[i]=a[i];
		}
		sort(b+1, b+1+n);
		int x=unique(b+1, b+1+n)-b;
		for(int i=1;i<=n;i++){
			a[i]=lower_bound(b+1, b+x, a[i])-b;
		}
		bit1.init(n);
		bit2.init(n);
		LL ans=0;
		LL inv1=0, inv2=0, inv3=0;
		bit1.update(a[1], 1);
		int j;
		for(j=n;j>=2;j--){
			int s2 = bit2.get_sum(a[j]-1);
			int s3 = 1-bit1.get_sum(a[j]);
			if( inv1+inv2+inv3+ s2+ s3<=k ){
				bit2.update(a[j], 1);
				inv2+=s2;
				inv3+=s3;
			} else {
				break;
			}
		}
		j++;
		//printf("j=%d\n", j);
		if( j==2 ){
			cout<<n*(LL)(n-1)/2<<endl;
			continue;
		}
		ans+=n-j+1;
		for(int i=2;i<n;i++){
			inv1+=i-1-bit1.get_sum(a[i]);
			bit1.update(a[i], 1);
			inv3+=bit2.get_sum(a[i]-1);
			while( (inv1+inv2+inv3>k) && j<=n){
				bit2.update(a[j], -1);
				inv2 -= bit2.get_sum(a[j]-1);
				inv3 -= i-bit1.get_sum(a[j]);
				j++;
			}
			//printf("j=%d\n", j);
			ans+=n-j+1;
		}
		cout<<ans<<endl;
		//cout<<force()<<endl;
	}
}