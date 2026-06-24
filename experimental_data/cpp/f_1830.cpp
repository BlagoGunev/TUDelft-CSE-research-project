#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

class FD{
private:
    template<typename T=int>
    inline static T Read(){
        T r=0;
        int f=0,c=getchar();
        while((c<'0' || c>'9') && ~c) f|=c=='-',c=getchar();
        while(c>='0' && c<='9') r=(r<<1)+(r<<3)+(c^48),c=getchar();
        return f?-r:r;
    }

    typedef long long ll;
    static constexpr int AwA=1e6+10;

    int n,m;
    int a[AwA];
    int cnt[AwA];
    vector<int> to[AwA];

    struct Line{
        ll k,b;
        Line(ll k=0,ll b=0):k(k),b(b){}
        inline ll operator[](const int&x) const{return k*x+b;}
    };
    struct Node{
        int lp,rp;
        Line k;
        int tag;
    }tr[AwA<<2];

    inline void Upt(int u,int v){
        tr[u].tag+=v;
        tr[u].lp+=v,tr[u].rp+=v;
        tr[u].k.b-=tr[u].k.k*v;
    }
    inline void PushDown(int u){
        if(tr[u].tag){
            Upt(u<<1,tr[u].tag),Upt(u<<1|1,tr[u].tag);
            tr[u].tag=0;
        }
    }
    inline void PushUp(int u){tr[u].lp=tr[u<<1].lp,tr[u].rp=tr[u<<1|1].rp;}

    void Build(int u,int l,int r){
        tr[u].lp=tr[u].rp=0;
        tr[u].k=Line(0,-1e18);
        tr[u].tag=0;
        if(l==r) return;
        int mid=(l+r)>>1;
        Build(u<<1,l,mid),Build(u<<1|1,mid+1,r);
    }
    void Insert(int u,int l,int r,Line v){
        if(tr[u].k.b<-1e17) return void(tr[u].k=v);
        int mid=(l+r)>>1;
        if(l==r){
            if(v[tr[u].lp]>tr[u].k[tr[u].lp]) swap(v,tr[u].k);
            return;
        }
        PushDown(u);
        if(v[tr[u<<1].rp]>tr[u].k[tr[u<<1].rp]) swap(v,tr[u].k);
        if(v[tr[u].lp]>tr[u].k[tr[u].lp]) Insert(u<<1,l,mid,v);
        else if(v[tr[u].rp]>tr[u].k[tr[u].rp]) Insert(u<<1|1,mid+1,r,v);
    }
    void InsDown(int u,int l,int r){
        if(tr[u].k.b<-1e17) return;
        Line v=tr[u].k;
        tr[u].k=Line(0,-1e18);
        int mid=(l+r)>>1;                                                                                                                                 
        Insert(u<<1,l,mid,v),Insert(u<<1|1,mid+1,r,v);
    }
    void Update(int u,int l,int r,int lx,int rx,int v){
        // if(l==1 && r==m) printf("Update %d %d\n",lx,v);
        if(lx<=l && r<=rx) return Upt(u,v);
        PushDown(u);
        InsDown(u,l,r);
        int mid=(l+r)>>1;
        if(lx<=mid) Update(u<<1,l,mid,lx,rx,v);
        if(mid<rx) Update(u<<1|1,mid+1,r,lx,rx,v);
        PushUp(u);
    }
    pair<int,ll> Query(int u,int l,int r,int p){
        if(l==r) return {tr[u].lp,tr[u].k[tr[u].lp]};
        pair<int,ll> pr;
        int mid=(l+r)>>1;
        PushDown(u);
        if(p<=mid) pr=Query(u<<1,l,mid,p);
        else pr=Query(u<<1|1,mid+1,r,p);
        pr.second=max(pr.second,tr[u].k[pr.first]);
        return pr;
    }
public:
    inline void Work(){
        n=Read(),m=Read();
        fill(to+1,to+m+2,vector<int>());
        fill(cnt+1,cnt+m+2,0);
        for(int i=1;i<=n;i++){
            int l=Read(),r=Read();
            to[l].push_back(r+1),cnt[r]++;
        }
        for(int i=1;i<=m;i++) a[i]=Read();
        m++;

        Build(1,1,m);
        for(int i=1;i<=m;i++){
            auto p=Query(1,1,m,i);
            ll k=max(0ll,p.second);
            // printf("%d %lld\n",p.first,k);
            for(int p:to[i]) Update(1,1,m,p,m,1);
            Insert(1,1,m,Line(a[i],k));
            // puts("-----");
            // for(int u=1;u<=7;u++){
            //     printf("%d~%d %d (%lld,%lld)\n",tr[u].lp,tr[u].rp,tr[u].tag,tr[u].k.k,tr[u].k.b);
            // }
            // puts("------");
            if(cnt[i]) Update(1,1,m,i+1,m,-cnt[i]);
        }
        printf("%lld\n",max(0ll,Query(1,1,m,m).second));
    }
    inline void Main(){
        int T=Read();
        while(T-->0) Work();
    }
}Fd;

int main(){
    auto t1=system_clock::now();
    Fd.Main();
    auto d=duration_cast<microseconds>(system_clock::now()-t1);
    cerr<<"\33[31m"<<1.0*d.count()*microseconds::period::num/microseconds::period::den<<"s\33[m"<<endl;
    return 0;
}