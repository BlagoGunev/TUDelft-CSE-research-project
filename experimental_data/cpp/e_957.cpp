#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define F first
#define S second
#define mp make_pair
using namespace std;
const int N=110000;
int n,w,id[N],BIT[N];
pair< pair<double,int> , int> ary1[N];
pair<double,int> ary2[N];
void ins(int x){
 while(x<N){
  BIT[x]++;
  x+=x&-x;
 }
}
int qry(int x){
 int sum=0;
 while(x){
  sum+=BIT[x];
  x-=x&-x;
 }
 return sum;
}
int main(){
 scanf("%d%d",&n,&w);
 int i;
 for(i=1;i<=n;i++){
  int x,v;
  scanf("%d%d",&x,&v);
  int k=x<0?(N*2+x):x;
  ary1[i]=mp(mp((double)abs(x)/abs(v-w),k),i);
  ary2[i]=mp((double)abs(x)/abs(v+w),i);
 }
 sort(ary1+1,ary1+n+1);
 for(i=1;i<=n;i++){
  //printf("%f %d %d\n",ary1[i].F.F,ary1[i].F.S,ary1[i].S);
  id[ary1[i].S]=i;
 }
 for(i=1;i<=n;i++)
  ary2[i].S=-id[ary2[i].S];
 sort(ary2+1,ary2+n+1);
 for(i=1;i<=n;i++){
  ary2[i].S=-ary2[i].S;
  //printf("%f %d\n",ary2[i].F,ary2[i].S);
 }
 long long ans=0;
 for(i=n;i>=1;i--){
  ans+=qry(ary2[i].S);
  ins(ary2[i].S);
 }
 printf("%lld\n",ans);
}