#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

class p {
public:
	int l, r;
	p()
	{}
	p(int l, int r)
	:l(l),r(r)
	{}
};

bool cmp(const p &i, const p &j) {
	if(i.l!=j.l) return i.l<j.l;
	else return i.r<j.r;
}

int d[4][3][5002], n, q;
vector<p> v;
p a[5001];

int f(int last, int skip, int k) {
	if(k==v.size()) return 0;
	int& ret=d[last][skip][k];
	if(ret>=0) return ret;
	if(v.size()-k+skip==2) return ret=0;
	int add=(v[k-last].r<v[k].l?v[k].r-v[k].l+1:v[k].r-v[k-last].r);
	if(skip==2) return ret=f(1,2,k+1)+add;
	return ret=max(f(1,skip,k+1)+add,f(last+1,skip+1,k+1));
}

int main() {
	scanf("%d %d",&n,&q);
	for(int i=0;i<q;i++)
		scanf("%d %d",&a[i].l,&a[i].r);
	sort(a,a+q,cmp);
	v.push_back(p(0,0));
	int cnt=0;
	for(int i=0;i<q;i++) {
		bool ok=true;
		for(int j=0;j<q;j++) if(i!=j) {
			if(a[j].l<=a[i].l && a[i].r<=a[j].r) {
				if(a[j].l==a[i].l && a[i].r==a[j].r) {
					if(i<j) continue;
				}
				ok=false; break;
			}
		}
		if(!ok) cnt++;
		else v.push_back(a[i]);
	}
	if(cnt>=2) {
		bool col[5001]={false};
		int res=0;
		for(int i=1;i<v.size();i++) {
			for(int j=v[i].l;j<=v[i].r;j++) {
				if(!col[j]) {
					res++;
					col[j]=true;
				}
			}
		}
		printf("%d\n",res);
		return 0;
	}
	memset(d,-1,sizeof(d));
	printf("%d\n",f(1,cnt,1));
	return 0;
}