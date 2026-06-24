#include<cstdio>

#include<vector>

#include<algorithm>

#include<queue>

#include<set>

#define base 200001

int n,f[200005],cnt[200005],w[400005],now=0,ans;

std::vector<int> p[200005];

std::set<int> ss;

int main()

{

	scanf("%d",&n);

	for (int i=1;i<=n;i++) scanf("%d",&f[i]),++cnt[f[i]],p[f[i]].push_back(i);

	for (int i=1;i<=n;i++) if (cnt[i]>cnt[now]) now=i;

	for (int i=1;i<=n;i++) if (f[i]==now) ss.insert(i);

//	printf("Ins %d\n",i);

	for (int i=-n;i<=n;i++) w[i+base]=-1;

//	printf("Mode %d\n",now);

	for (int i=1;i<=n;i++)

	{

		if (i==now) continue;

		//M = (i,now)

		std::vector<int> pp;

		for (int x=0;x<(int)p[i].size();x++)

		{

			int k=p[i][x];

			std::set<int>::iterator it;

			it=ss.lower_bound(k);

			std::vector<int> del;

			if (it!=ss.end()) pp.push_back(*it),del.push_back(*it);

			if (it!=ss.begin()) --it,pp.push_back(*it),del.push_back(*it);

			pp.push_back(k);

			for (int d=0;d<(int)del.size();d++) ss.erase(del[d]);

		}

//		puts("QwQ");

		std::sort(pp.begin(),pp.end());

		int kk=-1;

		std::queue<int> q;

		int ns=0;

//		printf("N = %d %d\n",i,now);

//		for (int d=0;d<(int)pp.size();d++) printf("%d ",pp[d]);puts("");

		for (int d=0;d<(int)pp.size();d++)

		{

			int x=pp[d];

//			printf("kk = %d\n",kk);

			if (x>kk||kk==-1)

			{

//				puts("Clear");

				while (!q.empty())

				{

					int x=q.front();q.pop();

					w[x+base]=-1;

				}

				std::set<int>::iterator it=ss.lower_bound(x);

				if (it!=ss.begin()) kk=*(--it);

				else kk=0;

				w[0+base]=kk;

//				printf("Push 0(%d)\n",kk);

				q.push(0);

				ns=0;

			}

			int nl=0,nr=n;

			if (d>0) nl=std::max(nl,pp[d-1]+1);

			std::set<int>::iterator it=ss.lower_bound(x);

			if (it!=ss.end()) kk=*it;else kk=n+1;

//			printf("QwQ %d\n",kk);

			nr=std::min(nr,kk-1);

			if (it!=ss.begin()) --it,nl=std::min(nl,1+*it);

			if (d+1<(int)pp.size()) nr=std::min(nr,pp[d+1]-1);

			if (f[x]==now) ++ns;else if (f[x]==i) --ns;

//			printf("ns = %d\n",ns);

			if (w[ns+base]==-1) w[ns+base]=x,q.push(ns)/*,printf("Push %d(%d)\n",ns,x)*/;

			else ans=std::max(ans,nr-w[ns+base])/*,printf("Range %d %d[sum = %d]\n",w[ns+base]+1,nr,ns)*/;

//			printf("wzfnb %d\n",kk);

		}

		while (!q.empty())

		{

			int x=q.front();q.pop();

			w[x+base]=-1;

		}

		for (int d=0;d<(int)pp.size();d++)

		{

			int x=pp[d];

			if (f[x]==now) ss.insert(x);

		}

	}

	printf("%d\n",ans);

	return 0;

}