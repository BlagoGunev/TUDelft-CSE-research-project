#include<cstdio>

#include<cmath>

#include<iostream>

#include<cstring>

#include<algorithm>

#include<stack>

#include<bitset>

#include<queue>

#include<map>

#include<utility>

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

typedef long long LL;

typedef unsigned long long ULL;

const int MN=200+10;

const int ME=10000+10;

const LL mod=2147493647LL;

const double pi=acos(-1.0);

const int Intmax=(~(1<<31));

const int Intmin=(1<<31);

const LL LLmax=(~(1LL<<63));

const LL LLmin=(1LL<<63);

const ULL ULLmax=(~(0ULL));



struct Node{

	LL l,r;

	LL s,d;

}node[MN],node2[MN];

bool cmp(const Node &a,const Node &b){

    return a.l<b.l;

}

int main(){

#ifndef ONLINE_JUDGE

    freopen("1.cpp","r",stdin);

#endif // ONLINE_JUDGE

    int n;

    scanf("%d",&n);

    int i,j;

    for(i=0;i<n;i++){

        scanf("%d%d",&node[i].s,&node[i].d);

        LL l,r;

        l=node[i].s;

        r=node[i].s+node[i].d-1;

        bool flag=true;

        for(j=i-1;j>=0;j--){

			if(l>node[j].r||r<node[j].l) continue;

			else{

				flag=false;

				break;

			}

        }

        if(flag){

			node[i].l=l;

			node[i].r=r;

			node2[i]=node[i];

			continue;

        }

        flag=true;

        l=1;

        r=1+node[i].d-1;

        for(j=i-1;j>=0;j--){

			if(l>node[j].r||r<node[j].l) continue;

			else{

				flag=false;

				break;

			}

        }

        if(flag){

			node[i].l=l;

			node[i].r=r;

			node2[i]=node[i];

			continue;

        }

        sort(node2,node2+i,cmp);

        for(j=0;j<i-1;j++){

            if(node2[j].r+node[i].d>=node2[j+1].l) continue;

			break;

        }

        node[i].l=node2[j].r+1;

        node[i].r=node[i].l+node[i].d-1;

        node2[i]=node[i];

    }

    for(i=0;i<n;i++) printf("%I64d %I64d\n",node[i].l,node[i].r);

    return 0;

}