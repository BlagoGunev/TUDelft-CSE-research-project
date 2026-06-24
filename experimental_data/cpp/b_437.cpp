#include<cstdio>
#include<cstring>
using namespace std;
int zr, m, a[22];
inline int Lowbit(int w)
{
	return w&-w;
}
void Give(int w)
{
	if(!~w)return;
	if(a[w]>m)
	{
		Give(w-1);
		Give(w-1);
	}
	else
	{
	//	printf("iusdaf %d\n",w);
		++zr;
		a[w]+=1<<(w+1);
	}
}
int main()
{
	int n, i, j, tot=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	    tot+=Lowbit(i);
	if(tot<n)
	{
		puts("-1");
		return 0;
	}
	for(i=0;i<18;++i)
	    a[i]=1<<i;
	j=0;
	while(n)
	{
		if(n&1)Give(j);
		j++;
		n>>=1;
	}
	printf("%d\n",zr);
	for(i=0;i<18;++i)
	    for(j=1<<i;j<a[i];j+=1<<(i+1))
	        printf("%d ",j);
	puts("");
	return 0;
}