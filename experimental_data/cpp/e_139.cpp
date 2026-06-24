#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>



using namespace std;



struct Tree {

    int x,type,prob;



    void setVal(int xx,int ttype,int pprob) {

        x=xx;

        type=ttype;

        prob=pprob;

    }



    bool operator < (const Tree& a) const {

        return x<a.x;

    }

}tree[400005];



struct Mushroom {

    int x,power;



    bool operator < (const Mushroom& a) const {

        return x<a.x;

    }

}mushroom[100005];



int n,m,x,h,l,r,cnt,num;

double lg_prob,ans;



int main() {

    while(2==scanf("%d%d",&n,&m)) {

        cnt=0;

        for(int i=0;i<n;++i) {

            scanf("%d%d%d%d",&x,&h,&l,&r);

            if(l>0) {//不会向左倒的概率，即区间[x-h,x)不会被压住的概率

                tree[cnt++].setVal(x-h,1,100-l);//1表示区间开始

                tree[cnt++].setVal(x,-1,100-l);//-1表示区间结束

            }

            if(r>0) {//不会向右倒的概率，即区间(x,x+h]不会被压住的概率

                tree[cnt++].setVal(x+1,1,100-r);

                tree[cnt++].setVal(x+h+1,-1,100-r);

            }

        }

        sort(tree,tree+cnt);

        for(int i=0;i<m;++i) {

            scanf("%d%d",&mushroom[i].x,&mushroom[i].power);

        }

        sort(mushroom,mushroom+m);

        num=0;//num表示当前这个点被多少个区间覆盖

        lg_prob=ans=0;

        for(int i=0,j=0;i<m;++i) {

            while(j<cnt&&tree[j].x<=mushroom[i].x) {

                if(tree[j].type==1) {

                    if(tree[j].prob==0) {//如果这个点不被覆盖的概率为0

                        ++num;

                    }

                    else {

                        lg_prob+=log(tree[j].prob/100.0);//取成log，防止精度问题

                    }



                }

                else {

                    if(tree[j].prob==0) {//如果这个点不被覆盖的概率为0

                        --num;

                    }

                    else {

                        lg_prob-=log(tree[j].prob/100.0);

                    }

                }

                ++j;

            }

            if(num==0) {//如果这个点可以不被覆盖

                ans+=mushroom[i].power*exp(lg_prob);

            }

        }

        printf("%.7lf\n",ans);

    }

    return 0;

}