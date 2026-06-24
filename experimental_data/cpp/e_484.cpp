#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cmath>

#include <cstring>

#include <queue>

#include <set>

#include <vector>

#include <map>

#define LL long long



using namespace std;



const int N=1e5+7;



int Ls[N*20],Rs[N*20],L[N*20],R[N*20],M[N*20];

int root[N],tot;



struct node{

	int id,key;

	bool operator < (const node & t) const {

		return key<t.key;

	}

}a[N];

int sorted[N];



int n;



inline void pushup(int k,int l,int r){

	M[k]=max(R[Ls[k]]+L[Rs[k]],max(M[Ls[k]],M[Rs[k]]));



	int mid=(l+r)>>1;

	if (L[Ls[k]]>=mid-l+1) L[k]=mid-l+1+L[Rs[k]];

	else L[k]=L[Ls[k]];

	if (R[Rs[k]]>=r-mid) R[k]=r-mid+R[Ls[k]];

	else R[k]=R[Rs[k]];

}



inline int bulidtree(int l,int r){

	int k=tot++;

	if (l==r){

		L[k]=R[k]=M[k]=1;

		return k;

	}



	int mid=(l+r)>>1;

	Ls[k]=bulidtree(l,mid);

	Rs[k]=bulidtree(mid+1,r);

	pushup(k,l,r);



	return k;

}



inline void COPY(int x,int y){

	Ls[x]=Ls[y];

	Rs[x]=Rs[y];

}



inline int update(int o,int p,int l,int r){

	int k=tot++;

	COPY(k,o);



	if (l==r){

		L[k]=R[k]=M[k]=0;

		return k;

	}



	int mid=(l+r)>>1;

	if (p<=mid) Ls[k]=update(Ls[k],p,l,mid);

	else Rs[k]=update(Rs[k],p,mid+1,r);

	pushup(k,l,r);



	return k;

}



inline int query(int o,int x,int y,int l,int r){

	if (l==x && r==y) return M[o];



	int mid=(l+r)>>1;

	if (y<=mid) return query(Ls[o],x,y,l,mid);

	else if (x>mid) return query(Rs[o],x,y,mid+1,r);

	else {

		int ret=min(mid-x+1,R[Ls[o]])+min(y-mid,L[Rs[o]]);

		return max(ret,max(query(Ls[o],x,mid,l,mid),query(Rs[o],mid+1,y,mid+1,r)));

	}

}



inline bool ok(int x,int l,int r,int w){

	return query(root[x],l,r,1,n)>=w;

}



inline int search(int x,int y,int w){

	int l=1,r=n;

	int mid;

	while (l<=r){

		mid=(l+r)>>1;

		if (ok(mid,x,y,w)) l=mid+1;

		else r=mid-1;

	}

	return sorted[r];

}



int main(){

	scanf("%d",&n);

	for (int i=1;i<=n;i++){

		scanf("%d",&a[i].key);

		sorted[i]=a[i].key;

		a[i].id=i;

	}

	sort(sorted+1,sorted+n+1);

	sort(a+1,a+n+1);



	root[1]=bulidtree(1,n);

	int j=1;

	for (int i=2;i<=n;i++){

		root[i]=root[i-1];

		while (j<=n && a[j].key<sorted[i]){

			root[i]=update(root[i],a[j].id,1,n);

			j++;

		}

	}



	int q;

	scanf("%d",&q);

	int l,r,w;

	while (q--){

		scanf("%d %d %d",&l,&r,&w);

		printf("%d\n",search(l,r,w));

	}



	return 0;

}