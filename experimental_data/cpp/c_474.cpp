#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<string>

#include<vector>

#include <ctime>

#include<queue>

#include<set>

#include<map>

#include<stack>

#include<iomanip>

#include<cmath>

#include<bitset>

#define mst(ss,b) memset((ss),(b),sizeof(ss))

///#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long ll;

#define INF (1ll<<60)-1

#define Max 1e9

using namespace std;

int n;

struct point{

    int x,y;

    point(int x=0,int y=0):x(x),y(y){}

};

typedef point vec;

point operator + (point a,vec b){

    return point(a.x+b.x,a.y+b.y);

}

point operator - (point a,vec b){

    return point(a.x-b.x,a.y-b.y);

}

point rota(point a,point b){

    vec v=a-b;

    vec w=vec(-v.y,v.x);

    return b+w;

}

ll disn(point a,point b){

    ll x=1LL*a.x-1LL*b.x;

    ll y=1LL*a.y-1LL*b.y;

    return 1LL*x*x+1LL*y*y;

}

bool pd(point a,point b,point c,point d){

    ll dis[10];

    dis[0]=disn(a,b);

    dis[1]=disn(b,c);

    dis[2]=disn(c,d);

    dis[3]=disn(d,a);

    dis[4]=disn(a,c);

    dis[5]=disn(b,d);

    sort(dis,dis+6);

    if(dis[0] && dis[0]==dis[3] && dis[4]==dis[5] && dis[0]*2LL==dis[4]) return true;

    return false;

}

point s[110][5][5],a;

int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        for(int j=1;j<=4;j++){

            scanf("%d%d%d%d",&s[i][j][0].x,&s[i][j][0].y,&a.x,&a.y);

            for(int k=1;k<=3;k++){

                s[i][j][k]=rota(s[i][j][k-1],a);

            }

        }

    }

    for(int i=1;i<=n;i++){

        int ans=Max;

        for(int p1=0;p1<4;p1++){

            for(int p2=0;p2<4;p2++){

                for(int p3=0;p3<4;p3++){

                    for(int p4=0;p4<4;p4++){

                        if(pd(s[i][1][p1],s[i][2][p2],s[i][3][p3],s[i][4][p4]))

                            ans=min(ans,p1+p2+p3+p4);

                    }

                }

            }

        }

        if(ans==Max) cout<<-1<<endl;

        else cout<<ans<<endl;

    }

    return 0;

}