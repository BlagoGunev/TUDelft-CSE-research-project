#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
/*
m=max(s[i])+1//字符集最大
n=strlen(s)//长度
s[0..n − 1]：字符串。s[n]='\0'
sa[1..n]：字典序第 i 小的是哪个后缀。
rank[0..n − 1]：后缀 i 的排名。
height[i]：lcp(sa[i], sa[i − 1])。
*/

const int mxn=200000+20;
int rk[mxn],sa[mxn],height[mxn],tmp[mxn],cnt[mxn];
int presum[mxn];
int L[mxn],R[mxn];
char s[mxn];
char fb[mxn];
char b[mxn];

void suffixarray(int n,int m){
    int i,j,k;n++;
    for(i=0;i<n+10;i++)rk[i]=sa[i]=height[i]=tmp[i]=0;
    for(i=0;i<m;i++)cnt[i]=0;
    for(i=0;i<n;i++)cnt[rk[i]=s[i]]++;
    for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
    for(i=0;i<n;i++)sa[--cnt[rk[i]]]=i;
    for(k=1;k<=n;k<<=1){
        for(i=0;i<n;i++){
            j=sa[i]-k;
            if(j<0)j+=n;
            tmp[cnt[rk[j]]++]=j;
        }
        sa[tmp[cnt[0]=0]]=j=0;
        for(i=1;i<n;i++){
            if(rk[tmp[i]]!=rk[tmp[i-1]]||rk[tmp[i]+k]!=rk[tmp[i-1]+k])cnt[++j]=i;
            sa[tmp[i]]=j;
        }
        memcpy(rk,sa,n*sizeof(int));
        memcpy(sa,tmp,n*sizeof(int));
        if(j>=n-1)break;
    }
    for(j=rk[height[i=k=0]=0];i<n-1;i++,k++)
        while(~k&&s[i]!=s[sa[j-1]+k])height[j]=k--,j=rk[sa[j]+1];
}

int main(){
    int len;
    scanf("%d",&len);
    scanf("%s",s);
    scanf("%s",fb);
    int mid=len/2;
    for(int i=0;i<mid;i++){
        swap(s[i],s[len-i-1]);
        swap(fb[i],fb[len-i-1]);
    }
    suffixarray(len,'z'+1);
    for(int i=1;i<=len;i++){
        L[i]=R[i]=i;
    }
    //printf("%s\n%s\n",s,fb);
    stack<int> s;
    height[len+1]=0;

    for(int i=1;i<=len+1;i++){
        while(s.size()!=0 && height[i]<=height[s.top()]){
            L[i]=L[s.top()];
            R[s.top()]=i-1;
            s.pop();
        }
        s.push(i);
    }
    presum[0]=0;
    for(int i=1;i<=len;i++){
        presum[i]=presum[i-1];
        if(fb[sa[i]]=='0')presum[i]++;
        //printf("%d %d\n",L[i],R[i]);
        //printf("%d\n",height[i]);
    }
    long long res=0;
    for(int i=1;i<=len;i++){
        if(height[i]!=0){
            res=max(res,(long long)height[i]*(presum[R[i]]-presum[L[i]-2]));
        }
    }
    for(int i=0;i<len;i++){
        if(fb[i]=='0'){
            if(len-i>res)res=len-i;
            break;
        }
    }
    printf("%lld\n",res);

    return 0;
}