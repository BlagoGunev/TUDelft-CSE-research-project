#include<bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")

#define ls i<<1

#define rs ls | 1

#define mid ((ll+rr)>>1)

#define pii pair<int,int>

#define MP make_pair

typedef long long LL;

const long long INF = 1e18+1LL;

const double Pi = acos(-1.0);

const int N = 1e6+10, M = 2e5+20, mod = 1e9+7, inf = 2e9;





int ids[N],L[N],R[N],mx[N],lmx[N],rmx[N],n,m;

void push_up(int i,int ll,int rr) {

     lmx[i] = lmx[ls];

     if(lmx[i] == mid-ll+1) lmx[i] += lmx[rs];



     rmx[i] = rmx[rs];

     if(rmx[i] == rr-mid) rmx[i] += rmx[ls];



     mx[i] = max(max(mx[ls],mx[rs]),(rmx[ls]+lmx[rs]+1)>>1);

     mx[i] = max(mx[i],max((lmx[i]+1)>>1,(rmx[i]+1)>>1));



     L[i] = rr;

     if((lmx[i]+1)>>1 == mx[i])

        L[i] = ll,R[i] = lmx[i]+ll-1;



     if(((rmx[i]+1)>>1) == mx[i] && L[i] >= rr-rmx[i]+1)

        L[i] = rr-rmx[i]+1,R[i]=rr;



     if(lmx[rs] && rmx[ls] && ((lmx[rs] + rmx[ls]+1)>>1) == mx[i]&& L[i] >= mid-rmx[ls]+1)

        L[i] = mid-rmx[ls]+1, R[i] = mid+1+lmx[rs]-1;



     if(mx[i] == mx[ls] && L[i] >= L[ls]) L[i] = L[ls],R[i] = R[ls];

     if(mx[i] == mx[rs] && L[i] >= L[rs]) L[i] = L[rs], R[i] = R[rs];



}

void build(int i,int ll,int rr) {

        L[i] = ll; R[i] = rr;

        lmx[i] = rr-ll+1;

        rmx[i] = lmx[i];

        mx[i] = (rr-ll+1+1)/2;

        if(ll == rr) {

            return ;

        }

        build(ls,ll,mid),build(rs,mid+1,rr);

}



void update(int i,int ll,int rr,int pos,int v) {

        if(ll == rr && rr == pos) {

            mx[i] = (v+1)/2;

            if(!v) L[i] = inf, R[i] = -inf,lmx[i] = 0,rmx[i] = 0;

            else  L[i] = ll, R[i] = rr,lmx[i] = 1,rmx[i] = 1;

            return ;

        }

        if(pos <= mid) update(ls,ll,mid,pos,v);

        else update(rs,mid+1,rr,pos,v);

        push_up(i,ll,rr);

}

int main() {

        int op,id;

        scanf("%d%d",&n,&m);

        build(1,1,n);

        for(int i = 1; i <= m; ++i) {

            scanf("%d%d",&op,&id);

            if(op == 1) {

                int pos;

                int now = lmx[1];

                int pre = rmx[1];

              //  cout<<lmx[1]<<" "<<rmx[1]<<" "<<mx[1]<<" "<<L[1]<<" "<<R[1]<<endl;

                if(now == 0 && pre == 0) now = -1;

                else {

                    if(now >= pre)  pos = 1;

                    else pos = n;

                    now = max(now,pre);

                }

                if(now < mx[1] || (now == mx[1] && pos >= L[1] + mx[1] - 1))   pos = L[1] + mx[1] - 1;

                printf("%d\n",pos);

                ids[id] = pos;

                update(1,1,n,pos,0);

               // cout<<lmx[1]<<" "<<rmx[1]<<" "<<mx[1]<<" "<<L[1]<<" "<<R[1]<<endl;

            } else {

                update(1,1,n,ids[id],1);

               // cout<<lmx[1]<<" "<<rmx[1]<<" "<<mx[1]<<" "<<L[1]<<" "<<R[1]<<endl;

                ids[id] = 0;

            }

        }

        return 0;

}