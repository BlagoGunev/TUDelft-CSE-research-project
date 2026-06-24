#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int ile[300001], czy[300001];
int miotla[100003];
vector<int> pp[100003], pk[100003], kp[100003], kk[100003];
int main(){
int n,x1,y1,x2,y2;
scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
scanf("%d", &n);
int a,b,c,d,ak,bk;
scanf("%d%d", &c, &d);
ak=c;
bk=d;
for (int i=2; i<=n; i++){
scanf("%d%d", &a, &b);
if(d==b){
if(c<a){
pp[b].push_back(c);
pk[b].push_back(a);
}
if(a<c){
kp[b].push_back(a);
kk[b].push_back(c);
}
}
c=a;
d=b;
}
if(d==bk){
if(c<ak){
pp[bk].push_back(c);
pk[bk].push_back(ak);
}
if(ak<c){
kp[bk].push_back(ak);
kk[bk].push_back(c);
}
}
int kt=0, lk=1;
for (int i=0; i<=y2; i++){
	for(int j=0; j<pp[i].size(); j++)
	for(int g=pp[i][j]; g<pk[i][j]; g++)
	if(g>=x1 && g<x2)
	{
	miotla[g]=1;
	}
   for(int j=0; j<kp[i].size(); j++){
for(int g=kp[i][j]; g<kk[i][j]; g++){
ile[miotla[g]]--;
miotla[g]=0;		
}
	}
}

if(miotla[x1]!=0){
kt++;
czy[kt]=1;
ile[kt]++;
miotla[x1]=kt;
}
for(int i=x1+1; i<x2; i++){
if(miotla[i-1]==0 && miotla[i]!=0)
kt++;
if(miotla[i]!=0){
czy[kt]=1;
ile[kt]++;
miotla[i]=kt;

}
}
for (int i=y2+1; i<y1; i++)
{
for(int j=0; j<pp[i].size(); j++){
	kt++;

	for(int g=pp[i][j]; g<pk[i][j]; g++)
	if(g>=x1 && g<x2)
	{
	miotla[g]=kt;
	ile[kt]++;
		czy[kt]=1;
	}
	int a=pp[i][j]-1, a1=pp[i][j];
	if(a>=x1 && miotla[a]!=0){
		if(ile[miotla[a]]<ile[miotla[a1]]){
		a=miotla[a];
		a1=miotla[a1];
		ile[a]=0;
		czy[a]=0;
		for(int g=x1; g<x2; g++)
			if(miotla[g]==a){
			miotla[g]=a1;
			ile[a1]++;
	}
	} else{
		a=miotla[a];
		a1=miotla[a1];
		ile[a1]=0;
		czy[a1]=0;
		for(int g=x1; g<x2; g++)
			if(miotla[g]==a1){
			miotla[g]=a;
			ile[a]++;
	}

	}

	}
	

	a=pk[i][j], a1=pk[i][j]-1;
	if(a<x2 && miotla[a]!=0){
	if(ile[miotla[a]]<ile[miotla[a1]]){
		a=miotla[a];
		a1=miotla[a1];
		ile[a]=0;
		czy[a]=0;
		for(int g=x1; g<x2; g++)
			if(miotla[g]==a){
			miotla[g]=a1;
			ile[a1]++;
	}
	} else{
		a=miotla[a];
		a1=miotla[a1];
		ile[a1]=0;
		czy[a1]=0;
		for(int g=x1; g<x2; g++)
			if(miotla[g]==a1){
			miotla[g]=a;
			ile[a]++;
	}
}
}
}
for(int j=0; j<kp[i].size(); j++){
for(int g=kp[i][j]; g<kk[i][j]; g++){
ile[miotla[g]]--;
miotla[g]=0;		
}
	}
//for(int g=x1; g<x2; g++)
//printf("%d ", miotla[g]);
//printf("\n");
}
int wyn=0;
for(int i=1; i<=kt; i++){
if(czy[i]==1)
wyn++;
}
printf("%d", wyn);
}