#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int getint()
{
    char ch=getchar();
    int f=1,x=0;
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return f*x;
}

const int N=200200;

int n,m,k;
int a[N];
int q[N];
int hd,tl;
int ans;

void init()
{
    n=getint(),m=getint(),k=getint();
    for(int i=1; i<=n; i++){
        a[i]=getint();
    }
    sort(a+1,a+1+n);
}

int main()
{
    init();
    for(int i=1; i<=n; i++){
        while(hd<tl && a[i]-q[hd]>=m) hd++;
        if(tl-hd>=k-1){
            ans++;
        }else{
            q[tl++]=a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}