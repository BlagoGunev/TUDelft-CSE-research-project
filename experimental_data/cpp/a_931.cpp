#include <bits/stdc++.h>
using namespace std;
int n,m;
int calc(int x){
 return x*(x+1)/2;
}

int main(){
 scanf("%d%d",&n,&m);
 int avg = (n+m)/2;
 cout << calc(abs(n-avg)) + calc(abs(m-avg)) << "\n" ;
}