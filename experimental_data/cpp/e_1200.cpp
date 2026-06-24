#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iterator>
#include<iostream>
#include<list>
#include<map>
#include<memory>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<utility>
#include<bitset>
#include<functional>
#define ll long long
const int N=100005;
using namespace std;

char s[N*10],w[N*10];
int nxt[N*10];
int main(){
    int n;
    scanf("%d",&n);
    int j,i,k;
    scanf("%s",s);
    int m=strlen(s);
    for(i=1;i<n;i++){
        scanf("%s",w);
        int len=strlen(w);
        nxt[0]=-1;
        j=0;k=-1;
        while(j<len-1){
            if(k==-1 || w[j]==w[k]){
                ++k;++j;
                nxt[j]=k;
            }else{
                k=nxt[k];
            }
        }
        j=max(0,m-len);
        k=0;
        while(j<m){
            if(k==-1 || s[j]==w[k]){
                j++;k++;
            }else{
                k=nxt[k];
            }
            //cout<<j<<k<<endl;
        }
        //cout<<endl;
        while(k<len) s[m++]=w[k++];
    }
    s[m]='\0';
    printf("%s\n",s);
    return 0;
}