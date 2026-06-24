#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<cctype>

#include<vector>

typedef long long ll;

const int _=2e5+10;

using namespace std;



void Read(){}template<typename tp,typename... A>

void Read(tp& c,A&... d){

    c=0;char x=getchar();bool op=0;

    while(!isdigit(x)) op|=(x=='-'),x=getchar();

    while(isdigit(x)) c=(c<<1)+(c<<3)+(x^'0'),x=getchar();

    if(op){c=-c;}Read(d...);

}



template<typename tp>void Write(tp c,char x='\n'){

    static char Sta[30];unsigned top=0;

    if(c<0) c=-c,putchar('-');

    do{Sta[top++]=c%10+'0',c/=10;}while(c);

    while(top) putchar(Sta[--top]);

    if(x) putchar(x);

}



int n,m,k,u[_],v[_];



struct Edge{

    int to[_<<1],head[_],next[_<<1],t;

    Edge(){t=1;}

    void add(int u,int v){

        to[++t]=v,next[t]=head[u],head[u]=t;

    }

}e;



vector<int> a0,a1;



void Tree_dfs(int x,int fa,int col){

    if(!col) a0.push_back(x);

    else a1.push_back(x);

    for(int i=e.head[x],y;i;i=e.next[i]){

        if((y=e.to[i])==fa) continue;

        Tree_dfs(y,x,col^1);

    }

}



bool vis[_],fd;

vector<int> cr;

vector<int> ce;



bool Cir_dfs(int x,int fa){

    vis[x]=1;

    if(fd) return false;

    for(int i=e.head[x],y;i;i=e.next[i]){

        if((y=e.to[i])==fa) continue;

        if(vis[y]){

            cr.push_back(y);

            ce.push_back(i>>1);

            fd=1;

            return true;

        }

        bool tmp=Cir_dfs(y,x);

        if(tmp){

            cr.push_back(y);

            ce.push_back(i>>1);

            if(x==cr[0]){

                return false;

            }

            return true;

        }

        else if(fd) return false;

    }

    return false;

}



#include<cassert>

#include<deque>



int main(){

    Read(n,m,k);

    for(int i=1,a,b;i<=m;i++){

        Read(a,b),e.add(a,b),e.add(b,a),u[i]=a,v[i]=b;

    }

    if(m==n-1){

        Write(1);

        Tree_dfs(1,0,0);

        if(a0.size()<a1.size()) swap(a0,a1);

        for(int i=0;i<((k>>1)+(k&1));i++){

            Write(a0[i]," \n"[i==((k>>1)+(k&1))-1]);

        }

    }

    else{

        assert((Cir_dfs(1,0),fd));

        for(int i=1;i<=n;i++) vis[i]=0;

        /*

        auto Nxt=[](int i){

            return i==(int)cr.size()-1?0:i+1;

        };

        auto Pre=[](int i){

            return i==0?(int)cr.size()-1:i-1;

        };

        for(int i=0;i<(int)cr.size();i++){

            for(int j=e.head[cr[i]],y;j;j=e.next[j]){

                if((y=e.to[j])==cr[Pre(i)]||y==cr[Nxt(i)]) continue;

                if(vis[y]){

                    

                }

            }

        }*/

        if((int)cr.size()<=k){

            Write(2),Write(cr.size());

            for(int i=0;i<(int)cr.size();i++) Write(cr[i]," \n"[i==(int)cr.size()-1]);

        }

        else{

            vector<int> inc(m+1);

            for(auto i:cr) vis[i]=1;

            for(int i=0;i<(int)ce.size();i++) inc[ce[i]]=1;

            vector<int> pos(n+1);

            for(int i=0;i<(int)cr.size();i++) pos[cr[i]]=i+1;

            deque<int> q0,q1;

            for(int i=0;i<(int)cr.size();i++) q1.push_back(cr[i]);

            for(int i=0;i<(int)ce.size();i++) q0.push_back(ce[i]);

            for(int i=1;i<=m;i++){

                if(!inc[i]&&vis[u[i]]&&vis[v[i]]){

                    while(q1.front()!=u[i]&&q1.front()!=v[i]){

                        inc[q0.front()]=0,vis[q1.front()]=0;

                        q0.pop_front(),q1.pop_front();

                    }

                    while(q1.back()!=u[i]&&q1.back()!=v[i]){

                        inc[q0.back()]=0,vis[q1.back()]=0;

                        q0.pop_back(),q1.pop_back();

                    }

                }

            }

            if((int)q1.size()<=k){

                Write(2),Write(q1.size());

                for(int i=0;i<(int)q1.size();i++) Write(q1[i]," \n"[i==(int)q1.size()-1]);

            }

            else{

                Write(1);

                for(int i=0,j=1;j<=((k>>1)+(k&1));i+=2,j++){

                    Write(q1[i]," \n"[j==((k>>1)+(k&1))]);

                }

            }

        }

    }

    return 0;

}