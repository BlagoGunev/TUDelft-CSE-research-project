#include<cstdio>

#define Fast register

struct Input{
  #define SIZE 98304
  char BUF[SIZE],*S,*T;
  Input():S(BUF),T(BUF){}
  inline Input&operator>>(char&c){return(c=(S==T)&&(T=(S=BUF)+fread(BUF,1,SIZE,stdin),S==T)?EOF:*S++,*this);}
  template<class T>inline Input&operator>>(T&s){
    s=0;Fast char c;
    while(*this>>c,c<48||c>57);
    while(s=s*10+c-48,*this>>c,c>47&&c<58);
    return*this;
  }
}input;

int x[100001];
int y[100001];

int main(){
  Fast int n,m;input>>n>>m;
  for(Fast int i=1;i<=n;++i)input>>x[i];
  for(Fast int i=1;i<=m;++i)input>>y[i];
  Fast int cnt=0;
  Fast int p1=1,p2=1,s1=0,s2=0;
  while(p1<=n&&p2<=m){
    if(s1==s2)++cnt,s1=x[p1++],s2=y[p2++];
    else if(s1>s2)s2+=y[p2++];
    else s1+=x[p1++];
  }return(printf("%d",cnt),0);
}