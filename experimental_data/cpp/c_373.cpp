/*template by : Dewangga Winardi*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

	
/*end of template*/



int main(int argc , char** argv)
{
	

	int kang[500005];

	int n=getnum<int>();
	for (int i=0; i<n; i++) kang[i]=getnum<int>();

	sort(kang,kang+n);

	int index=n/2;

	int kiri=0,kanan=index;
	int ans=n;
	
	while (1) {
		if (kiri>=index || kanan>=n) break;
		if (kang[kiri] * 2 <= kang[kanan]) {
			kiri++; kanan++; ans--;
		} else kanan++;
	}

	printf("%d\n",ans);	

	//pause;
	return 0;
}