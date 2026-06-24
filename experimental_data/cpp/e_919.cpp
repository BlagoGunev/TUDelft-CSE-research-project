inline long long ksm(long long a,long long n,long long qy){
 long long fh=1;
 while(n){
  if(n&1)fh=fh*a%qy;
  a=a*a%qy;
  n=(n>>1);
 }
 return (fh%qy);
}
long long a,b,p,x;
long long sc;
int main(){
 __builtin_scanf("%lld%lld%lld%lld",&a,&b,&p,&x);
 long long z=ksm(a,p-2,p);
 for(int i=1;i<p;i++){
  b=b*z%p;
  long long n=(p-1)*((i-b+p)%p)+i;
  if(n<=x)sc+=(x-n)/(p*(p-1))+1;
 }
 __builtin_printf("%lld",sc);
 return 0;
}