#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N=2e5+5;

namespace Read {

	static const int buf_size = 1 << 20;

	

	static unsigned char buf[buf_size];

	static int buf_len, buf_pos;

	

	inline bool isEOF() {

		if (buf_pos == buf_len) {

			buf_pos = 0; buf_len = fread(buf, 1, buf_size, stdin);

			if (buf_pos == buf_len) return true;

		}

		return false;

	}

	

	inline char readChar() {

		return isEOF() ? EOF : buf[buf_pos++];

	}

	

	inline int read() {

		int x = 0; char c = readChar();

		while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = readChar(); }

		return x;

	}

	

	template <typename T>

	inline void read(T &x) {

		x = read(); 

	}

	

	template <typename T, typename... Ts>

	inline void read(T &x, Ts &...rest) {

		read(x);

		read(rest...);

	}

} using namespace Read;

int n,m,cnt,Q,block;

int a[N],b[N],bl[N],ans[N];

int nxt[N],pre[N];

int res[N];

int lsh[N],cnt2;

int hd;

int c[N],cc[N];

struct query{

    int l,r,t,k,id;

    bool operator <(const query &x)const {

        return bl[l]<bl[x.l]||bl[l]==bl[x.l]&&bl[r]<bl[x.r]||bl[l]==bl[x.l]&&bl[r]==bl[x.r]&&t<x.t;

    }

}q[N];

struct upd{

    int p,x,y;

}up[N];

inline void add(const int &x) {

    int y=c[x]++;

    cc[y]--,cc[y+1]++;

    if(cc[y+1]==1) {

        nxt[y+1]=nxt[y],nxt[y]=y+1,pre[y+1]=y;

        if(nxt[y+1]) pre[nxt[y+1]]=y+1;

    }

    if(cc[y]==0) {

        pre[y+1]=pre[y];

        if(pre[y+1]) nxt[pre[y+1]]=y+1;

        else hd=y+1;

    }

}

inline void del(const int &x) {

    int y=c[x]--;

    cc[y]--,cc[y-1]++;

    if(cc[y-1]==1) {

        nxt[y-1]=y,pre[y-1]=pre[y],pre[y]=y-1;

        if(pre[y-1]) nxt[pre[y-1]]=y-1;

        else hd=y-1;

    }

    if(cc[y]==0) {

        nxt[y-1]=nxt[y];

        if(nxt[y-1]) pre[nxt[y-1]]=y-1;

    }

}

int get(int x) {return lower_bound(lsh+1,lsh+1+cnt2,x)-lsh;} 

int p[N],siz[N],cnt3,sum[N];

int main() {

    //freopen("data.in","r",stdin);

    n=read(),m=read();block=pow(n,2.0/3);

    for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i],lsh[++cnt2]=a[i];

	for(int i=1;i<=n;i++) bl[i]=(i-1)/block+1;

    for(int i=1;i<=m;i++) {

        int op=read();

        if(op==1) {

            int l=read(),r=read(),k=read();

            Q++,q[Q]={l,r,cnt,k,Q};

        }

        else {

            int p=read(),x=read();

            up[++cnt]={p,b[p],x},b[p]=x,lsh[++cnt2]=x;

        }

    }

    sort(lsh+1,lsh+1+cnt2),cnt2=unique(lsh+1,lsh+1+cnt2)-lsh-1;

    for(int i=1;i<=n;i++) a[i]=get(a[i]);

    for(int i=1;i<=cnt;i++) up[i].x=get(up[i].x),up[i].y=get(up[i].y);

    for(int i=1;i<=cnt2;i++) c[i]++,cc[1]++;hd=1;

    sort(q+1,q+1+Q);

    int L=1,R=0,T=0;memset(ans,0x3f,sizeof ans);

    for(int i=1;i<=Q;i++) {

        int l=q[i].l,r=q[i].r,k=q[i].k,t=q[i].t;

        //cout<<l<<' '<<r<<endl;

        while(L>l) add(a[--L]);

        while(R<r) add(a[++R]);

        while(L<l) del(a[L++]);

        while(R>r) del(a[R--]);

        while(T<t) {

            T++;

            int p=up[T].p,x=up[T].x,y=up[T].y;

            if(l<=p&&p<=r) del(x),add(y);

            a[p]=y;

        }

        while(T>t) {

            int p=up[T].p,x=up[T].x,y=up[T].y;

            if(l<=p&&p<=r) del(y),add(x);

            a[p]=x;

            T--;

        }

        cnt3=0;

        for(int j=hd;j;j=nxt[j]) {

            if(j>1)p[++cnt3]=j-1,siz[cnt3]=cc[j],sum[cnt3]=sum[cnt3-1]+siz[cnt3];

        }

        //cout<<"cnt:"<<cnt3<<endl;

        // for(int j=1;j<=cnt3;j++) {

        //     cout<<siz[j]<<' '<<p[j]<<' '<<sum[j]<<endl;

        // }

        int le=0,ok=0;

        for(int j=1;j<=cnt3;j++) {

            while(le<j&&sum[j]-sum[le]>=k) ok=1,le++;

            if(ok) {

                //cout<<"rnm"<<' '<<q[i].id<<endl;

                ans[q[i].id]=min(ans[q[i].id],p[j]-p[le]);

            }

        }

        //cout<<"ok:"<<ok<<endl;

    }

    for(int i=1;i<=Q;i++) {

        printf("%d\n",ans[i]==0x3f3f3f3f?-1:ans[i]);

    }

}