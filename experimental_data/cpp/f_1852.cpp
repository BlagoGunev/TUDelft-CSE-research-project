#include<stdio.h>
#include<algorithm>
constexpr int inf{1000000000};
constexpr int N{200000};
struct node {
    int fa;
    union {
        struct {int ls,rs;};
        int son[2];
    };
    int val,sum,max;
    int pos,dir,fst,lst;
    int tag,time,type;
    constexpr node():fa{},ls{},rs{},val{},sum{},max{},pos{},dir{},fst{},lst{},tag{},time{},type{} {}
    constexpr node(const int &x,const int &c):fa{},ls{},rs{},val{c},sum{c},max{std::max(c,0)},pos{x},dir{c>0?-1:1},fst{c>0?x:-2},lst{c<0?x:-2},tag{},time{inf<<1|1},type{} {}
};
node tr[N+5];
int tot;
inline int son_type(const int &x) {
    return tr[tr[x].fa].rs==x;
}
inline void add_val(const int &x,const int &v) {
    tr[x].val+=v,tr[x].sum+=v;
    tr[x].max=std::max(tr[tr[x].ls].max,tr[tr[x].ls].sum+tr[x].val+tr[tr[x].rs].max);
    tr[x].dir=tr[x].val>0?-1:1;
    tr[x].fst=tr[x].val>0?tr[x].pos:-2;
    tr[x].lst=tr[x].val<0?tr[x].pos:-2;
}
inline void add_tag(const int &x,const int &v) {
    if(__builtin_expect(x==0,0)) {
        return;
    }
    tr[x].tag+=v;
    if(tr[x].dir==1) {
        tr[x].pos=std::min(inf+1,tr[x].pos+v);
    }
    else {
        tr[x].pos=std::max(-1,tr[x].pos-v);
    }
    if(tr[x].fst!=-2) {
        tr[x].fst=std::max(-1,tr[x].fst-v);
    }
    if(tr[x].lst!=-2) {
        tr[x].lst=std::min(inf+1,tr[x].lst+v);
    }
    tr[x].time-=v<<1;
}
inline void push_down(const int &x) {
    if(tr[x].tag!=0) {
        add_tag(tr[x].ls,tr[x].tag);
        add_tag(tr[x].rs,tr[x].tag);
        tr[x].tag=0;
    }
}
inline void push_up(const int &x) {
    tr[x].sum=tr[tr[x].ls].sum+tr[x].val+tr[tr[x].rs].sum;
    tr[x].max=std::max(tr[tr[x].ls].max,tr[tr[x].ls].sum+tr[x].val+tr[tr[x].rs].max);
    tr[x].fst=tr[x].ls?tr[tr[x].ls].fst:tr[x].val>0?tr[x].pos:-2;
    tr[x].lst=tr[x].rs?tr[tr[x].rs].lst:tr[x].val<0?tr[x].pos:-2;
    if(tr[tr[x].ls].time<tr[tr[x].rs].time) {
        tr[x].time=tr[tr[x].ls].time,tr[x].type=0;
    }
    else {
        tr[x].time=tr[tr[x].rs].time,tr[x].type=1;
    }
    if(tr[x].ls!=0&&tr[x].dir==-1) {
        int &y{tr[tr[x].ls].lst};
        if(y!=-2&&tr[x].pos-y<tr[x].time) {
            tr[x].time=tr[x].pos-y,tr[x].type=2;
        }
    }
    if(tr[x].rs!=0&&tr[x].dir==1) {
        int &y{tr[tr[x].rs].fst};
        if(y!=-2&&y-tr[x].pos<tr[x].time) {
            tr[x].time=y-tr[x].pos,tr[x].type=3;
        }
    }
}
void rotate(const int &x) {
    int y{tr[x].fa},z{tr[y].fa},k{son_type(x)};
    push_down(y),push_down(x);
    if(z) {
        tr[z].son[son_type(y)]=x;
    }
    tr[x].fa=z;
    tr[tr[y].son[k]=tr[x].son[k^1]].fa=y;
    tr[tr[x].son[k^1]=y].fa=x;
    push_up(y),push_up(x);
}
void splay(int &rt,const int &x) {
    if(rt==x) {
        push_down(x);
        push_up(x);
        return;
    }
    for(int y;y=tr[x].fa;) {
        if(tr[y].fa) {
            rotate(son_type(y)==son_type(x)?y:x);
        }
        rotate(x);
    }
    rt=x;
}
void splay(int &rt,const int &x,const int &y) {
    if(tr[x].fa==y) {
        push_down(x);
        push_up(x);
        return;
    }
    for(int z;(z=tr[x].fa)!=y;) {
        if(tr[z].fa!=y) {
            rotate(son_type(z)==son_type(x)?z:x);
        }
        rotate(x);
    }
}
int first(int x) {
    while(tr[x].ls) {
        x=tr[x].ls;
    }
    return x;
}
int last(int x) {
    while(tr[x].rs) {
        x=tr[x].rs;
    }
    return x;
}
void erase(int &rt,const int &x) {
    splay(rt,x),push_down(x);
    if(tr[x].ls==0&&tr[x].rs==0) {
        return rt=0,void();
    }
    if(tr[x].ls==0) {
        return tr[rt=tr[x].rs].fa=0,void();
    }
    if(tr[x].rs==0) {
        return tr[rt=tr[x].ls].fa=0,void();
    }
    int y{first(tr[x].rs)};
    splay(rt,y,x),push_down(y);
    tr[tr[y].ls=tr[x].ls].fa=y;
    tr[rt=y].fa=0;
    push_up(y);
}
int find(const int &x) {
    if(tr[x].type==0) {
        return find(tr[x].ls);
    }
    if(tr[x].type==1) {
        return find(tr[x].rs);
    }
    if(tr[x].type==2) {
        return last(tr[x].ls);
    }
    if(tr[x].type==3) {
        return x;
    }
    __builtin_unreachable();
}
void move(int &rt,const int &t) {
    while(rt!=0&&tr[rt].time<=t<<1) {
        int x{find(rt)};
        splay(rt,x);
        int y{first(tr[x].rs)};
        splay(rt,y,x);
        if(tr[x].val+tr[y].val==0) {
            erase(rt,x),erase(rt,y);
        }
        else if(std::abs(tr[x].val)>std::abs(tr[y].val)) {
            add_val(x,tr[y].val);
            tr[tr[x].rs=tr[y].rs].fa=x;
            push_up(x);
        }
        else {
            splay(rt,y);
            add_val(y,tr[x].val);
            tr[tr[y].ls=tr[x].ls].fa=y;
            push_up(y);
        }
    }
    add_tag(rt,t);
}
void insert(int &rt,const int &x,const int &c) {
    tr[++tot]=node(x,c);
    if(rt==0) {
        return rt=tot,void();
    }
    int y{rt};
    while(true) {
        push_down(y);
        if(x==tr[y].pos) {
            --tot,add_val(y,c);
            if(tr[y].val==0) {
                erase(rt,y);
            }
            else {
                splay(rt,y);
            }
            return;
        }
        else if(x<tr[y].pos) {
            if(tr[y].ls==0) {
                tr[tr[y].ls=tot].fa=y;
                break;
            }
            y=tr[y].ls;
        }
        else {
            if(tr[y].rs==0) {
                tr[tr[y].rs=tot].fa=y;
                break;
            }
            y=tr[y].rs;
        }
    }
    splay(rt,tot);
}
void output(const int &x) {
    push_down(x);
    if(tr[x].ls) {
        output(tr[x].ls);
    }
    printf("%d: %d %d %d, %d %d %d\n",x,tr[x].fa,tr[x].ls,tr[x].rs,tr[x].val,tr[x].pos,tr[x].max);
    if(tr[x].rs) {
        output(tr[x].rs);
    }
}
int main() {
    int q;
    scanf("%d",&q);
    int cur{0},val{0},root{0};
    tr[tot=0]=node(),tr[0].time=inf<<1|1;
    for(int i=1;i<=q;i++) {
        int x,t,c;
        scanf("%d%d%d",&x,&t,&c);
        move(root,x-cur),cur=x;
        val+=std::max(c,0);
        insert(root,t,c);
        printf("%d\n",val-tr[root].max);
    }
    return 0;
}