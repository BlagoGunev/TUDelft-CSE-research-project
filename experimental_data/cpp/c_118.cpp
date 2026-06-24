#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cctype>

using namespace std;

typedef long long ll;
#define REP(i,k) for(int (i)=0;(i)<(k);(i)++)
#define INF ~(1<<31)

int main(){
int n,k;

while(cin>>n>>k){
string s;
string orig;
cin>>s;
orig=s;
sort(s.begin(),s.end());

int res=INF;
string minstr=orig;

int cnt[10];
memset(cnt,0,sizeof(cnt));

REP(i,s.length()){
cnt[s[i]-'0']++;
}

REP(i,10){
int need=k-cnt[i];
if(need<=0) {res=0;minstr=orig;break;}
int l=i-1,r=i+1;
int price=0;
int p=1;

int needchange[10];
memset(needchange,0,sizeof(needchange));

int lc1=-1,lc2=-1,lastchange=0;

while(true){
int c1=0;
int c2=0;

if(l>=0) c1=cnt[l];
if(r<=9) c2=cnt[r];
int c=c1+c2;
if(c>=need){
price+=(need*p);
lastchange=need;
lc1=l;
lc2=r;
break;
}
else{
price+=(c*p);
need-=c;
if(l>=0)
needchange[l]+=c1;
if(r<=9)
needchange[r]+=c2;
}

l--;
r++;
p++;
}

/*
cout<<"_----";
cout<<i<<endl;
cout<<"P: "<<price<<endl;
cout<<"lc1: "<<lc1<<endl;
cout<<"lc2: "<<lc2<<endl;
REP(j,10){
cout<<j<<"- "<<needchange[j]<<endl;
}*/


string newstr="";
REP(j,orig.length()){
if(needchange[orig[j]-'0']>0){
needchange[orig[j]-'0']--;
newstr+=i+'0';
}
else if((lc2!=-1 && orig[j]-'0'==lc2 && lastchange>0)){
lastchange--;
newstr+=i+'0';
}
else
newstr+=orig[j];
}

for(int j=minstr.length()-1;j>=0;j--){
if(lastchange==0) break;
if((lc1!=-1 && orig[j]-'0'==lc1 && lastchange>0)){
lastchange--;
newstr[j]=(i+'0');
}
}

if(price<res || (price==res && newstr<minstr)){
res=price;
minstr=newstr;
}

}

cout<<res<<endl;
cout<<minstr<<endl;

}

}