#include<bits/stdc++.h>
using namespace std;
int n,m,ds[55][55],X[4]={1,-1,0,0},Y[4]={0,0,1,-1},nx;
int T;
struct hhh{
    int i1,j1,i2,j2;
};
vector<hhh> an;
vector<pair<int,int>> qb;
struct hh{
    int x,y,z;
}qq[55*55];
int kk;
bool ccc(hh x,hh y){return x.z<y.z;}
char s[55][55],t[55][55];
bool hsb(int x,int y){
    if(x<1||x>n||y<1||y>m)return false;
    return s[x][y]!='X';
}
int sum;
int b[55][55];
bool bbb[55][55];
void dfs(int x,int y){
    if(b[x][y]==T||s[x][y]!='*')return;
    b[x][y]=T,++sum;
    for(int i=0;i<4;++i)
    if(hsb(x+X[i],y+Y[i]))
    dfs(x+X[i],y+Y[i]);
}
void hsa(int i1,int j1,int i2,int j2){an.push_back({i1,j1,i2,j2});}
int bfs(int x,int y){
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)ds[i][j]=-1;
    ds[x][y]=0;
    qb.push_back(make_pair(x,y));
    for(int i=0;i<qb.size();++i){
        x=qb[i].first,y=qb[i].second;
        for(int j=0;j<4;++j)
        if(hsb(x+X[j],y+Y[j]))
        if(ds[x+X[j]][y+Y[j]]==-1){
            ds[x+X[j]][y+Y[j]]=ds[x][y]+1;
            qb.push_back(make_pair(x+X[j],y+Y[j]));
        }
    }
    qb.clear();
    int mi=3000;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='*')mi=min(mi,ds[i][j]);
    return mi;
}
void bfss(int x,int y){
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)ds[i][j]=-1;
    ds[x][y]=0;
    qb.push_back(make_pair(x,y));
    for(int i=0;i<qb.size();++i){
        x=qb[i].first,y=qb[i].second;
        for(int j=0;j<4;++j)
        if(hsb(x+X[j],y+Y[j]))
        if(ds[x+X[j]][y+Y[j]]==-1)
        if(t[x+X[j]][y+Y[j]]=='*'){
            ds[x+X[j]][y+Y[j]]=ds[x][y]+1;
            qb.push_back(make_pair(x+X[j],y+Y[j]));
        }
    }
    qb.clear();
}
void pr(){for(int i=1;i<=n;++i)printf("%s\n",s[i]+1);printf("\n");}
void prds(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)printf("%2d ",ds[i][j]);
        printf("\n");
    }
}
int main()
{
    //freopen("J.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i)scanf("%s",t[i]+1);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='*')++nx;
    int is=0,js=0;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    if(t[i][j]=='*'){
        int mi=bfs(i,j);if(mi==-1)return !printf("NO");
    while(mi){
        int i2=0,j2=0;
        for(int i1=1;i1<=n;++i1)for(int j1=1;j1<=m;++j1)
        if(s[i1][j1]=='*')
        for(int k=0;k<4;++k)
        if(hsb(i1+X[k],j1+Y[k]))
        if(ds[i1+X[k]][j1+Y[k]]==mi-1)
        {i2=i1+X[k],j2=j1+Y[k];break;}
        for(int i1=1;i1<=n;++i1)
        for(int j1=1;j1<=m;++j1)
        if(s[i1][j1]=='*')
        if(i1!=i2||j1!=j2){
            s[i1][j1]='.';
    for(int k=0;k<4;++k)if(s[i1+X[k]][j1+Y[k]]=='*'){is=i1+X[k],js=j1+Y[k];break;}
s[i2][j2]='*';++T;sum=0;dfs(i2,j2);if(sum!=nx){s[i1][j1]='*';s[i2][j2]='.';continue;}
s[i2][j2]='.';
            ++T;
            sum=0;
            if(nx>1)dfs(is,js);
            if(sum==nx-1){hsa(i1,j1,i2,j2);i1=n+1;break;}
            s[i1][j1]='*';

        }
        s[i2][j2]='*';
//pr();
        --mi;
    }
        is=i,js=j;i=n+1;break;
    }
bbb[is][js]=true;bfss(is,js);
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    if(t[i][j]=='*')
    qq[++kk]={i,j,ds[i][j]};
    sort(qq+1,qq+kk+1,ccc);
    for(int ii=2;ii<=kk;++ii)
{
    if(qq[ii].z<qq[ii-1].z||qq[ii].z-qq[ii-1].z>1)return 1;
    int i=qq[ii].x,j=qq[ii].y;
    if(t[i][j]=='*'&&s[i][j]!='*')
    {
        int mi=bfs(i,j);
    while(mi){
        int i2=0,j2=0;
        for(int i1=1;i1<=n;++i1)
        for(int j1=1;j1<=m;++j1)
        if(s[i1][j1]=='*')
        for(int k=0;k<4;++k)
        if(hsb(i1+X[k],j1+Y[k]))
        if(ds[i1+X[k]][j1+Y[k]]==mi-1)
        {i2=i1+X[k],j2=j1+Y[k];break;}
        bool bb=false;
        for(int i1=1;i1<=n;++i1)
        for(int j1=1;j1<=m;++j1)
        if(s[i1][j1]=='*')
        if(!bbb[i1][j1])
        if(i1!=i2||j1!=j2){
            s[i1][j1]='.';++T;
            sum=0;
            dfs(is,js);
            if(sum==nx-1){hsa(i1,j1,i2,j2);bb=true;i1=n+1;break;}
            s[i1][j1]='*';
        }
        s[i2][j2]='*';
        --mi;
    }
//pr();
    }
    bbb[i][j]=true;
}
for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]!=t[i][j]){while(1){vector<int> vv;vv.push_back(1);}}
    printf("YES\n");
    if(an.size()>10000){while(1){vector<int> vv;vv.push_back(1);}}
    printf("%d\n",an.size());
    for(auto i:an)printf("%d %d %d %d\n",i.i1,i.j1,i.i2,i.j2);
    return 0;
}