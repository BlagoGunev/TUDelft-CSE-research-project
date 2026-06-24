#include <bits/stdc++.h>
using namespace std;
long long b,h,s;string a; 
int main() {cin>>a; scanf("%lld",&b);sort(a.begin(),a.end()); 
for(int i=0;i<a.size();i++)
for(int j=i+1;j<a.size();j++){
  string t=a;swap(t[j],t[i]);
  sort(t.begin()+i+1,t.end());
  h=stoll(a),s=stoll(t);
  if (s>h&&s<=b) swap(a[i],a[j]);}puts(a.c_str());}