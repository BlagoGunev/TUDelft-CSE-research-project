#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;
const int MaxL = 100010;
const int MaxC = 1024;
int rem[3][MaxL],cnt[MaxL],fid[MaxC+1],h[MaxL],*r,*p,*nr,*np;
void makeSufArr(char s[],int len){
    p = rem[0],np = rem[1],r = rem[2];
    for (int i = 0;i < len;i++)
        np[i] = s[i];
    sort(np,np+len);
    int sz = 0;
    for (int i = 1;i < len;i++)
        if (np[i] != np[i-1])
            cnt[fid[np[i-1]] = sz++] = i;
    cnt[fid[np[len-1]] = sz++] = len;
    for (int i = len-1;i >= 0;i--)
        p[--cnt[r[i] = fid[s[i]]]] = i;
    for (int k = 1;k < len && r[p[len-1]] < len-1;k <<= 1){
        for (int i = 0;i < len;i++) cnt[r[p[i]]] = i+1;
        for (int i = len-1;i >= 0;i--) if (p[i] >= k)
            np[--cnt[r[p[i]-k]]] = p[i]-k;
        for (int i = len-k;i < len;i++)
            np[--cnt[r[i]]] = i;
        nr = p,p = np;
        nr[p[0]] = 0;
        for (int i = 1;i < len;i++)
            nr[p[i]] = nr[p[i-1]]+(r[p[i]] != r[p[i-1]] ||
                p[i-1]+k >= len || r[p[i]+k] != r[p[i-1]+k]);
        np = r,r = nr;
    }
}
void makeHeight(char s[],int len){
/*add special char, such as '#', at the end of each component*/
    for (int i = 0,d = 0,j;i < len;i++){
        if (s[i] == '#' || r[i] == len-1){
            h[r[i]] = d = 0;
            continue;
        }
        if (d > 0) d--;
        j = p[r[i]+1];
        while (s[i+d] != '#' && s[j+d] != '#' &&
               s[i+d] == s[j+d]) d++;
        h[r[i]] = d;
    }
}
char st[MaxL];
int sk[MaxL],f[MaxL],sn;
int main(){
    scanf("%s",st);
    int L = strlen(st);
    makeSufArr(st,L);
    makeHeight(st,L);
    //for (int i = 0;i < L;i++) printf("%d ",p[i]);puts("");
    //for (int i = 0;i < L;i++) printf("%d ",r[i]);puts("");
    //for (int i = 0;i < L;i++) printf("%s\n",st+p[i]);puts("");
    //for (int i = 0;i < L;i++) printf("%d ",h[i]);puts("");
    LL Res = L*(L+1LL) / 2;
    f[sn = 0] = 0;
    for (int i = 0;i < L;i++){
        //printf("%d : %d\n",i,h[i]);
        Res -= h[i];
        int mini = i;
        while (h[i] < f[sn]){
            LL d = i-sk[sn]+1;
            LL e = f[sn]-max(h[i],f[sn-1]);
            //printf("at %d(%d) : %lld %lld => %lld\n",f[sn],sk[sn],d,e,e*d*(d+1) / 2);
            Res += e*(d*(d+1) / 2-1);
            mini = min(mini,sk[sn]);
            --sn;
        }
        if (h[i] > f[sn]){
            sk[++sn] = mini;
            f[sn] = h[i];
        }
        //printf("sn = %d : ",sn);for(int j = 0;j <= sn;j++)printf("%d(%d) ",f[j],sk[j]);puts("");
    }
    cout << Res << endl;
    return 0;
}