#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mem(ss,b) memset(ss,b,sizeof(ss))

template<class T> void read(T&num) {

    char CH; bool F=false;

    for(CH=getchar();CH<'0'|CH>'9';F= CH=='-',CH=getchar());

    for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());

    F && (num=-num);

}

int stk[70], tp;

template<class T> inline void print(T p) {

    if(!p) { puts("0"); return; }

    while(p) stk[++ tp] = p%10, p/=10;

    while(tp) putchar(stk[tp--] + '0');

    putchar('\n');

}

const double pi=acos(-1); 

int main()

{

   int n,m,sum=0;

   read(n);

   for(int i=1;i<=n;i++)

   {

   	  read(m);

   	  sum+=m-1;

   	  if(sum&1)

   	   printf("1\n");

   	   else 

   	   printf("2\n");

   } 

}