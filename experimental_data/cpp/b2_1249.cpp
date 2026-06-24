#include<cctype> 
#include<cstdio>
#define R register
int Q,N,A[200005],f[200005],p[200005];
template<class T>inline void read(R T &m)
{
	m=0;
	R char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))m=(m<<3)+(m<<1)+(c&15),c=getchar();
}
int main()
{
	read(Q);
	while(Q--)
	{
		read(N);
		for(R int i=1;i<=N;++i)
		{
			read(A[i]);
			f[i]=0;
			p[i]=i;
		}
		for(R int i=1;i<=N;++i)
		{
			if(!f[p[i]])
			{
				R int tmp=A[i],step=1;
				p[i]=i;
				while(tmp!=i)
				{
					++step;
					p[tmp]=i;
					tmp=A[tmp];
				}
				f[i]=step;
			}
		}
		for(R int i=1;i<=N;++i)
		{
			printf("%d ",f[p[i]]);
		}
		puts("");
	}
}