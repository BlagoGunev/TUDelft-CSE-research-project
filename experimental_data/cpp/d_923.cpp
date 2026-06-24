#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int gi() {
  int x=0,o=1;char ch=getchar();
  while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
  if(ch=='-') o=-1,ch=getchar();
  while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return x*o;
}
int suma1[N],suma2[N],sumb1[N],sumb2[N];
char s1[N],s2[N];
int main() {
  scanf("%s",s1+1);
  scanf("%s",s2+1);
  int len1=strlen(s1+1),len2=strlen(s2+1);
  for(int i=1;i<=len1;i++) sumb1[i]=sumb1[i-1]+(s1[i]=='B'||s1[i]=='C');
  for(int i=1;i<=len2;i++) sumb2[i]=sumb2[i-1]+(s2[i]=='B'||s2[i]=='C');
  for(int i=1;i<=len1;i++) suma1[i]=(s1[i]=='A')?suma1[i-1]+1:0;
  for(int i=1;i<=len2;i++) suma2[i]=(s2[i]=='A')?suma2[i-1]+1:0;
  int Q=gi();
  while(Q--) {
    int a=gi(),b=gi(),c=gi(),d=gi();
    int a1=min(suma1[b],b-a+1),a2=min(suma2[d],d-c+1),b1=sumb1[b]-sumb1[a-1],b2=sumb2[d]-sumb2[c-1];
    if(((b1&1)!=(b2&1))||b1>b2||a1<a2) putchar('0');
    else if(b1==b2) {
      if(a1%3==a2%3) putchar('1');
      else putchar('0');
    }
    else {
      if(b1==0) putchar(a1>a2?'1':'0');
      else putchar('1');
    }
  }
  return 0;
}