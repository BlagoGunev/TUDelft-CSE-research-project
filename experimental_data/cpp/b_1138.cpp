//
// Created by asud on 2019/3/8.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5007;
char s[maxn];
int a[maxn],c[maxn],ans[maxn],tot;
int main(){
    int n;scanf("%d",&n);
    scanf("%s",s+1);for(int i=1;i<=n;i++) c[i]=s[i]-'0';
    scanf("%s",s+1);for(int i=1;i<=n;i++) a[i]=s[i]-'0';
    int w=0,x=0,y=0,z=0,half=n/2; // ca -- w:00  x:01  y:10  z:11
    for(int i=1;i<=n;i++){
        if(c[i]==0&&a[i]==0) w++;
        else if(c[i]==0&&a[i]==1) x++;
        else if(c[i]==1&&a[i]==0) y++;
        else if(c[i]==1&&a[i]==1) z++;
    }
    int flag=0,answ=0,ansx=0,ansy=0,ansz=0;
    for(int ytmp=0;ytmp<=y&&!flag;ytmp++){
        for(int ztmp=0;ztmp<=z&&!flag;ztmp++){
            if(ytmp+ztmp>half) continue;
            int ltot=ytmp+ztmp;
            int rnow=z-ztmp;
            if(rnow>ltot) continue;
            int xtmp=ltot-rnow;
            if(xtmp>x) continue;
            int wtmp2=w+(y-ytmp)-(x-xtmp);
            if(wtmp2<0||wtmp2%2) continue;
            int wtmp=wtmp2/2;
            if(wtmp>w) continue;
            if(ytmp+ztmp+wtmp+x-xtmp!=half) continue;
            flag=1;
            answ=wtmp;ansx=x-xtmp;ansy=ytmp;ansz=ztmp;
        }
    }
    if(flag){
        for(int i=1;i<=n;i++){
            if(c[i]==0&&a[i]==0&&answ) ans[tot++]=i,answ--;
            if(c[i]==0&&a[i]==1&&ansx) ans[tot++]=i,ansx--;
            if(c[i]==1&&a[i]==0&&ansy) ans[tot++]=i,ansy--;
            if(c[i]==1&&a[i]==1&&ansz) ans[tot++]=i,ansz--;
        }
        for(int i=0;i<tot;i++){
            printf("%d%c",ans[i],(i==tot-1)?'\n':' ');
        }
    }else{
        printf("-1\n");
    }
    return 0;
}