/*
D. Scissors
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Jenya has recently acquired quite a useful tool ? k-scissors for cutting strings. They are generally used for cutting out two non-intersecting substrings of length k from an arbitrary string s (its length should be at least 2?k in order to perform this operation) and concatenating them afterwards (preserving the initial order). For example, with the help of 2-scissors you can cut ab and de out of abcde and concatenate them into abde, but not ab and bc since they're intersecting.

It's a nice idea to test this tool before using it in practice. After looking through the papers, Jenya came up with two strings s and t. His question is whether it is possible to apply his scissors to string s such that the resulting concatenation contains t as a substring?

Input
The first line contains three integers n, m, k (2???m???2?k???n???5?105) ? length of s, length of t and the aforementioned scissors' parameter correspondingly.

The next two lines feature s and t consisting of lowercase latin letters.
*/

#include<bits/stdc++.h> 
using namespace std; 

#define _   int v, int tl, int tr, int l, int r, int h
#define tm  (tl + tr >> 1)
#define sol v+v,tl,tm,l,r,h 
#define sag v+v+1,tm+1,tr,l,r,h 

#define mp make_pair 
#define pb push_back 
#define st first 
#define nd second 

typedef long long ll; 
typedef pair < int , int > pp; 
const int mod = 1e9 + 9; 
const int N   = 5e5 + 5; 

int L[N],R[N],f[N],m,n,cut,i,j,k;
char a[N],b[N];

int main(){
    scanf("%d%d%d %s %s",&m,&n,&cut,a+1,b+1);

 memset(L , 22 , sizeof L);
 for(j=0,i=2;i<=n;i++){
  for(; j && b[j+1] != b[i] ;) j = f[j];
  if(b[j+1] == b[i]) j++;
  f[i] = j;
 } 
 for(j=0,i=1;i<=m;i++){
  for(; j && b[j+1] != a[i] ;) j = f[j];
  if(b[j+1] == a[i]) j++;
  if(i >= cut)
   for(k=j; L[k] > m ;k=f[k]) 
    L[k] = i;
  if(j == n){
            j = f[j];
            if(i < cut){
                cout << "Yes\n" << 1 << " " << cut+1 << endl;
                return 0;
            }
            if(i-n+1 > m-cut+1){
                cout << "Yes\n" << m-cut-cut+1 << " " << m-cut+1 << endl;
                return 0;
            }
        }
 }
 ///
 reverse(a+1 , a+m+1);
 reverse(b+1 , b+n+1);
 for(j=0,i=2;i<=n;i++){
  for(; j && b[j+1] != b[i] ;) j = f[j];
  if(b[j+1] == b[i]) j++;
  f[i] = j;
 } 
 for(j=0,i=1;i<=m;i++){
  for(; j && b[j+1] != a[i] ;) j = f[j];
  if(b[j+1] == a[i]) j++;
  if(i >= cut)
   for(k=j; !R[k] ;k=f[k]) 
    R[k] = m-i+1;
  if(j == n) j = f[j];
 }
 
    for(i=0;i<=n;i++)
  if(L[i] < R[n-i] && max(i,n-i) <= cut){
   cout << "Yes\n" << L[i]-cut+1 << " " << R[n-i] << endl;
   return 0;
  }
 cout << "No";
 return 0;
}