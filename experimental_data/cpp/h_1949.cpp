//��_H
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e6;
int n;
pair<int,int> p[N];
int main(){
	int T,i,j,x,y,l,r,f;
	vector<int> t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			p[i]=make_pair(x+y,x);
		}
		sort(p+1,p+n+1);
		if(p[1]!=make_pair(0,0)){
			printf("YES\n");
			continue;
		}
		f=1;
		i=2;
		l=0,r=0,x=1;
		for(j=1;f&&l<=r;j++){
			t.clear();
			while(i<=n&&p[i].first==j){
				if(p[i].second>=l&&p[i].second<=r+1)
					t.push_back(p[i].second);
				i++;
			}
			if(t.size()==0){
				if(x==2){
					r++;
					x=1;
				}
				else
					l++;
				continue;
			}
			if(t.size()==1&&t[0]==l&&x==1){
				continue;
			}
			if(t.size()==1&&t[0]==r+1&&x==1){
				l++;
				r++;
				continue;
			}
			if(t.size()==2&&t[0]==l&&t[1]==r+1&&x==1){
				r++;
				continue;
			}
			if(t.size()==1&&t[0]==r&&x==1&&r-l==1){
				l++;
				x=2;
				continue;
			}
			f=0;
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}