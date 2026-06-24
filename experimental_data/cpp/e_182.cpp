#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int oo=1000000007;
const int maxn=201;
struct arr{
  int x,y,z;
}a[maxn];
int f[3001][maxn];
int n,m,s;

bool cmp(arr i,arr j){
  return (i.x<j.x) || (i.x==j.x && i.y<j.y);
}

int lower(int k){
  int l=0,r=s-1,mid;
  while (l<r){
    mid=(l+r)/2;
    if (a[mid].x<k) l=mid+1;
    else r=mid;
  }
  return l;
}

int upper(int k){
  int l=0,r=s-1,mid;
  while (l<r){
    mid=(l+r)/2;
    if (a[mid].x<=k) l=mid+1;
    else r=mid;
  }
  if (a[l].x==k) return l;
  return l-1;
}

int main(){
  int i,j,k,l,r,p;
  scanf("%d%d",&n,&m);
  for (s=i=0;i<n;i++){
    scanf("%d%d",&l,&r);
    a[s].x=l;
    a[s].y=r;
    a[s].z=i;
    s++;
    if (l!=r){
      a[s].z=i;
      a[s].x=r;
      a[s].y=l;
      s++;
    }
  }
  sort(a,a+s,cmp);
  for (i=0;i<s;i++) f[a[i].x][i]=1;
  for (i=1;i<m;i++){
    for (j=0;j<s;j++){
      l=lower(a[j].y);
      r=upper(a[j].y);
      p=i+a[j].y;
      if (p<=m)
      for (k=l;k<=r;k++)
        if (a[k].z!=a[j].z) f[p][k]=(f[p][k]+f[i][j])%oo;
    }
  }
  k=0;
  for (j=0;j<s;j++) k=(k+f[m][j])%oo;
  printf("%d\n",k);
  return 0;
}