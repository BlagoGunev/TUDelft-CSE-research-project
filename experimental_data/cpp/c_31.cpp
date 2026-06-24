#include <iostream>
#include <algorithm>
using namespace std;
typedef struct {long l,r;long nro;} CURS;

bool operator< (const CURS &a, const CURS &b)
{
	if (a.r<=b.r)
		return 1;
	return 0;
}

long n,i;
CURS C[5005];
long s1,s2,nrseg,kk;

long maxim(long a, long b)
{
	if(a>b)
		return a;
	else
		return b;
}

long minim(long a, long b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
		{
			cin>>C[i].l>>C[i].r;
			C[i].nro=i;
		}
	sort(C+1,C+n+1);
	s1=0;
	for (i=2;i<=n;i++)
		if (C[i].l<C[i-1].r)
		{
			s1=i;
			break;
		}
	if (s1==0)
	{
		cout<<n<<endl;
		for (i=1;i<=n;i++)
			cout<<i<<" ";
		return 0;
	}
	// se verifica cate cu cate segmente se suprapune segmentul s1
	nrseg=0;
	for(i=1;i<=n;i++)
		if(((C[i].l>C[s1].l&&C[i].l<C[s1].r)||(C[i].r>C[s1].l&&C[i].r<C[s1].r))&&(i!=s1))
		{
			nrseg++;
			s2=i;
		}
	if(nrseg==1)
	{
		kk=1;
		for(i=s1+1;i<=n;i++)
			if(C[i].l<C[i-1].r)
					kk=0;
		if(kk)
		{
			cout<<"2"<<endl<<minim(C[s1].nro,C[s2].nro)<<" "<<maxim(C[s1].nro,C[s2].nro);
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		kk=1;
		C[s1].l=-1;
		C[s1].r=-1;
		sort(C+1,C+n+1);
		for (i=2;i<=n;i++)
			if (C[i].l<C[i-1].r)
			{
				kk=0;
				break;
			}	
		if(kk)
			cout<<"1"<<endl<<C[1].nro;
		else
			cout<<"0";
	}
	return 0;
}