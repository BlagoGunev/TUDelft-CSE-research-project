#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

int main(){
	int n,x;
	vector< pair < pair < pair<int,int>, pair<int,int> > ,int > > v;
	scanf("%d %d",&n,&x);
	for(int i = 0; i < n; i++){
		int l,r,c;
		scanf("%d %d %d",&l,&r,&c);
		v.pb(mp(mp(mp(r-l+1,l),mp(c,r)),0));
	}
	sort(v.begin(),v.end());
	int mi[200005];
	mi[n-1] = v[n-1].ff.ss.ff;
	v[n-1].ss = n-1;
	for(int i = n-2; i >= 0; i--){
		v[i].ss = i;
		if(v[i].ff.ff.ff == v[i+1].ff.ff.ff)
			mi[i] = min(mi[i+1],v[i].ff.ss.ff);
		else{
			mi[i] = v[i].ff.ss.ff;
		}
	}

	long long ans = 100000000000;
	for(int i = 0; i < n; i++){
		long long y = v[i].ff.ss.ff;
		vector< pair < pair < pair<int,int>, pair<int,int> > ,int > >::iterator it = upper_bound(v.begin(),v.end(),
			mp(mp (mp(x-v[i].ff.ff.ff,v[i].ff.ss.ss+1),mp(0,0)) ,0) );
		//printf("%d %d\n",v[i].ff.ss,y );
		if(it != v.end()){
			pair < pair < pair<int,int>, pair<int,int> > ,int > a = *it;
			if(a.ff.ff.ff + v[i].ff.ff.ff == x){
				ans = min(ans,y + mi[a.ss]);
			}
		}
	}

	printf("%lld\n",ans == 100000000000 ? -1 : ans  );
    return 0;
}