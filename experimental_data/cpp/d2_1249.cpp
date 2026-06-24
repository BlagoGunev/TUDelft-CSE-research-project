#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define pb push_back
using namespace std;
int n,k;
struct dot{
    int l,r,id;
    bool operator < ( const dot& b)const{
        return r<b.r;
    }
}a[200005],s;
bool cmp(dot x,dot y){
    return x.l==y.l?x.r<y.r:x.l<y.l;
}
int as[200005],cnt,sum;
int c[200005],x;
int mx=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) {
        a[i].id=i+1;
        scanf("%d%d",&a[i].l,&a[i].r);
        mx=max(mx,a[i].r);
        c[a[i].l]++;
        c[a[i].r+1]--;
    }
    sort(a,a+n,cmp);
    priority_queue<dot> q;
    for(int i=1;i<=mx;i++){
        sum+=c[i];
        while(sum>k){
            while(x<n){
                if(a[x].l<=i && a[x].r>=i) q.push(a[x]);
                if(a[x].l>i){
                    break;
                }
                x++;
            }
            s=q.top();
            q.pop();
            sum--;
            c[s.r+1]++;
            as[cnt++]=s.id;
            //cout<<i<<' '<<s.id<<endl;
        }
    }
    cout<<cnt<<endl;
    sort(as,as+cnt);
    for(int i=0;i<cnt;i++){
        printf("%d\n",as[i]);
    }
}