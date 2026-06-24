#include<cstdio>
#include<cmath>
#include<climits>
using namespace std;
int max(int a,int b){
 return a>b?a:b;
}
int main(){
 int n;
 scanf("%d",&n);
 int ma=INT_MIN;
 bool flag=true;
 for (int i=0;i<n;i++){
  int a;
  scanf("%d",&a);
  if (a<0){
   ma=max(ma,a);
   continue;
  }
  int b=sqrt(a);
  if (b*b!=a)
   ma=max(ma,a);
 }
 printf("%d\n",ma);
 return 0;
}