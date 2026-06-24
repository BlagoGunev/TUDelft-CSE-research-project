#include <bits/stdc++.h>

#define int long long

#define endl '\n'

using namespace std;

struct segtree

{

    struct node

    {

        int seg=0,pre=0,suf=0,first=0,last=0;

    };

    vector<node>tree;

    int size;

    segtree(int n)

    {

        size=1;

        while(size<n)size*=2;

        tree.assign(size*2-1,node());

    }

    node merge(node a,node b,int lx,int rx)

    {

        int mid=(lx+rx)/2;

        return{

            a.seg+b.seg+(a.last<=b.first)*a.suf*b.pre,

            (a.pre==mid-lx&&a.last<=b.first?a.pre+b.pre:a.pre),

            (b.suf==rx-mid&&a.last<=b.first?b.suf+a.suf:b.suf),

            a.first,b.last

        };

    }

    void set(int i,int v,int x,int lx,int rx)

    {

        if(rx-lx==1)

        {

            tree[x]={1,1,1,v,v};

            return;

        }

        int mid=(lx+rx)/2;

        if(i<mid)set(i,v,x*2+1,lx,mid);

        else set(i,v,x*2+2,mid,rx);

        tree[x]=merge(tree[x*2+1],tree[x*2+2],lx,rx);

    }

    void set(int i,int v)

    {

        set(i,v,0,0,size);

    }

    node get(int l,int r,int x,int lx,int rx)

    {

        if(l>=rx||r<=lx)return node();

        if(l<=lx&&r>=rx)return tree[x];

        int mid=(lx+rx)/2;

        node s1=get(l,r,x*2+1,lx,mid);

        node s2=get(l,r,x*2+2,mid,rx);

        return merge(s1,s2,lx,rx);

    }

    int get(int l,int r)

    {

        return get(l,r,0,0,size).seg;

    }

};

void solve()

{

    int n,q;

    cin>>n>>q;

    segtree st(n);

    for(int i=0;i<n;i++)

    {

        int x;cin>>x;

        st.set(i,x);

    }

    while(q--)

    {

        int c;cin>>c;

        if(c==1)

        {

            int i,v;

            cin>>i>>v;

            st.set(i-1,v);

        }else

        {

            int l,r;

            cin>>l>>r;

            cout<<st.get(l-1,r)<<endl;

        }

    }

}

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);cout.tie(nullptr);

    int ut=1;

//    cin>>ut;

    while(ut--)solve();

}