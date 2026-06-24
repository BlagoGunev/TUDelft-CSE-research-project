#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//ifstream cin("a.in");
//ofstream cout("a.out");
int n,k,i,j,v[1510],sum,st,dr,mid,ok,contor,t;
char s[1510][40],c[40],sortat[1510][40];
int cmp(int x,int y){
    return strcmp(s[x],s[y])<0 ;
}
int verif(int x){
    for(int i=0;i<k;i++)
        if(c[i]!=sortat[x][i])return 0;
    return 1;
}
int main(){
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>s[i];
        v[i]=i;
    }
    sum='S'+'E'+'T';
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++)
        memcpy(sortat[i],s[v[i]],k);
    for(i=1;i<n-1;i++)
        for(j=i+1;j<n;j++){
            for(t=0;t<k;t++)
                if(sortat[i][t]==sortat[j][t])
                    c[t]=sortat[i][t];
                else c[t]=sum-sortat[i][t]-sortat[j][t];
            ///caut binar daca exista c
            if(j+1==n){
               contor+=verif(n);
               continue;
            }
            st=j+1;
            dr=n;
            while(st<=dr){
                mid=(st+dr)/2;
                ok=strcmp(sortat[mid],c);
                if(ok<0)///s[mid] mai lexicografic decat c
                    st=mid+1;
                else dr=mid-1;
            }
           if(st<=n)
            contor+=verif(st);
        }
    cout<<contor;
    return 0;
}