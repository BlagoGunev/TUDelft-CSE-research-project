#include<bits/stdc++.h>

using namespace std;

typedef int ll;

const ll eps=0 , mod=3;

ll ny[3]={-1,1,2};//逆元就是本身 



struct MAT

{

	int n,m;

	bitset<265>a[265*16*2][3];//ll a[265*16*2][265];

	ll val(int i,int j){return a[i][1].test(j)?1:(a[i][2].test(j)?2:0);}

	ll x[265];

	

	MAT(){n=m=0;}

	void init(int nn,int mm)//初始化啥也不是矩阵,空矩阵（所有元素都要经过赋值才行） 

	{

		n=nn , m=mm;

		for(int i=1;i<=n;++i)//for(int j=1;j<=m+1;++j)a[i][j]=0;

			for(int j=0;j<3;++j)a[i][j].reset();

	}

	int gaosi()//方程个数n可能大于未知数个数m 

	//复杂度n*m*min(n,m)  (注意增广矩阵是m+1列的)

	//无穷多解输出任意方案(避免回带，自由元全取0)，无解return -1

	{

		int id=0;//上一个首非零元的行号 

		for(int i=1;i<=m;++i)//枚举未知数 （列） 

		{

			int mxid=0;

			for(int j=id+1;j<=n;++j)//if(a[j][i]){mxid=j;break;}

				if(val(j,i)){mxid=j;break;}

			if(mxid==0){x[i]=0;continue;}//xi的取值任意，无穷多解，但取0方便，不然要回带到上面的行  

			

			/*++id;

			if(mxid!=id)

				for(int j=i;j<=m+1;++j)swap(a[id][j],a[mxid][j]);*/

			swap(a[++id],a[mxid]);

				

			//if(a[id][i]!=1)for(int j=i;j<=m+1;++j)a[id][j]=3-a[id][j];//模3卡常版系数化1

			if(a[id][2].test(i))swap(a[id][1],a[id][2]);

			

			for(int j=1;j<=n;++j)//用第id行去消第j行 

				if(j!=id && val(j,i)/*a[j][i]*/)//加上 a[j][i] 不为 0 的判断，快了很多

				{

					/*ll chu=a[j][i];for(int k=i;k<=m+1;++k)a[j][k]=(a[j][k]-chu*a[id][k]+9)%3;*/

					bitset<265>b[3];

					for(int u=0,x=val(j,i);u<3;u++)

						for(int v=0;v<3;v++) b[(u-x*v+9)%3]|=a[j][u]&a[id][v];

					for(int k=0;k<3;k++) a[j][k]=b[k];

				}

		}

		

		for(int i=id+1;i<=n;++i)//if(a[i][m+1])return -1;

			if(val(i,m+1))return -1;

		//int p=1;

		for(int i=1;i<=id;++i)

		{

			//while(a[i][p]==0)++p;x[p]=a[i][m+1];//xp在自由元都确定的情况下，有唯一解 

			x[min(a[i][1]._Find_first(),a[i][2]._Find_first())]=val(i,m+1);

		}

		return 1;

	}

}mat;



int du[75],_u[265],_v[265];ll _c[265];

vector<int>e[75];//存边的id 

int vis[75];



struct FC{int i,j,k;ll val;}fc[265*16*2];int cnt;//一个三元环就是一个方程 

int main()

{

	int T;scanf("%d",&T);while(T--)

	{

		int _n,_m;scanf("%d%d",&_n,&_m);

		for(int i=1;i<=_n;++i)e[i].clear() , du[i]=0 , vis[i]=0;

		cnt=0;

		

		for(int i=1;i<=_m;++i)

		{

			scanf("%d%d%d",&_u[i],&_v[i],&_c[i]);

			++du[_u[i]] , ++du[_v[i]];

			

			if(_c[i]!=-1)fc[++cnt]={i,0,0,_c[i]%3};

		}

		for(int i=1,uu,vv;i<=_m;++i)

		{

			uu=_u[i] , vv=_v[i];

			if(du[uu]<du[vv] || (du[uu]==du[vv]&&uu<vv))e[uu].push_back(i);

			else

			{

				swap(_u[i],_v[i]);//这种写法存边的id，记得要swap（因为后面要访问_u[]和_v[]的） 

				e[vv].push_back(i);

			}

		}

		

		//cnt=0;

		for(int u=1,v,w;u<=_n;++u)

		{

			for(int eid:e[u])vis[_v[eid]]=eid;

			

			for(int eid:e[u])

			{

				v=_v[eid];

				for(int eeid:e[v])

				{

					w=_v[eeid];

					if(vis[w])fc[++cnt]={eid,eeid,vis[w],0};

				}

			}

			

			for(int eid:e[u])vis[_v[eid]]=0;

		}

		

		mat.init(cnt,_m);

		for(int i=1;i<=cnt;++i)//mat.a[i][fc[i].i]=mat.a[i][fc[i].j]=mat.a[i][fc[i].k]=1 , mat.a[i][_m+1]=fc[i].val;

		{

			if(fc[i].j==0 && fc[i].k==0)

			{

				mat.a[i][1].set(fc[i].i) , mat.a[i][fc[i].val].set(_m+1);

				for(int j=1;j<=_m;++j)if(j!=fc[i].i)mat.a[i][0].set(j);

			}

			else

			{

				for(int j=1;j<=_m+1;++j)mat.a[i][0].set(j);

				mat.a[i][1].set(fc[i].i),mat.a[i][1].set(fc[i].j),mat.a[i][1].set(fc[i].k);

				mat.a[i][0].reset(fc[i].i),mat.a[i][0].reset(fc[i].j),mat.a[i][0].reset(fc[i].k);

				//fc[i].val一定是0 ，即a[i][_m+1]一定是0 

			}

		}

		

		if(mat.gaosi()==-1)puts("-1");

		else

		{

			for(int i=1;i<=_m;++i)printf("%d ",mat.x[i]==0?3:mat.x[i]);

			puts("");

		}

	}

	return 0;

}