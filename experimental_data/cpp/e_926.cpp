#include <bits/stdc++.h>
#define for(i,l,r) for (int i=l;i<r;i++)
using namespace std;
int n; stack<int> a; stack<int> print;
signed main() {
 //freopen("926E.inp","r",stdin);
 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 cin>>n;
 while (n--) {
  int num; cin>>num;
  a.push(num); if (a.size()<2) continue;
  int s2=a.top(); a.pop(); int s1=a.top(); a.pop(); a.push(s1); a.push(s2);
  //Repeatedly compare the first 2 stack elements.
  while (a.size()>=2&&s1==s2) {
   a.pop(); a.pop(); s1++; if (a.size()>0) s2=a.top();
   a.push(s1);
  }
 }
 cout<<a.size()<<"\n";
 while (a.size()>0) {print.push(a.top()); a.pop();}
 while (print.size()>0) {cout<<print.top()<<" "; print.pop();}
}