#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<cctype>

#include<vector>

typedef long long ll;

const int _=+10;

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



#define int ll



void calcdiv(int x,vector<int>& d,vector<int>& a){

    for(int i=2;i*i<=x;i++){

        if(x%i) continue;

        d.push_back(i),a.push_back(0);

        while(x%i==0) x/=i,a[a.size()-1]++;

    }

    if(x!=1) d.push_back(x),a.push_back(1);

}



namespace Try{

    void calc(){

        const int __=3e7;

        vector<int> e(__+1);

        int Max=0;

        for(int i=1;i<=__;i++){

            for(int j=1;j*i<=__;j++) e[j*i]++,Max=max(e[j*i],Max);

        }

        Write(Max);

    }

}



void dfs(int x,int val,vector<int>& Div,vector<int>& A,vector<int>& Ans){

    if(x==-1){

        Ans.push_back(val);

        return;

    }

    for(int i=0;i<=A[x];i++){

        dfs(x-1,val,Div,A,Ans);

        val*=Div[x];

    }

}



signed main(){

    int t;Read(t);

    while(t--){

        int n,m1,m2;Read(n,m1,m2);

        vector<int> d1,d2,a1,a2;

        calcdiv(m1,d1,a1),calcdiv(m2,d2,a2);

        vector<int> Div,A;

        {int i=0,j=0;

        for(;i<(int)d1.size()&&j<(int)d2.size();){

            if(d1[i]==d2[j]) Div.push_back(d1[i]),A.push_back(a1[i]+a2[j]),j++,i++;

            else if(d1[i]<d2[j]){

                Div.push_back(d1[i]),A.push_back(a1[i]);

                i++;

            }

            else Div.push_back(d2[j]),A.push_back(a2[j]),j++;

        }

        for(;i<(int)d1.size();i++) Div.push_back(d1[i]),A.push_back(a1[i]);

        for(;j<(int)d2.size();j++) Div.push_back(d2[j]),A.push_back(a2[j]);

        }

        vector<int> All;

        dfs(Div.size()-1,1,Div,A,All);

        sort(All.begin(),All.end());

        All.erase(unique(All.begin(),All.end()),All.end());

        vector<int> f(All.size());

        int Ans1=0,Ans2=0;

        for(int i=0;i<(int)All.size();i++){

            f[i]=All[i]<=n?All[i]:0;

            for(int j=0;j<(int)Div.size();j++){

                if(All[i]%Div[j]) continue;

                f[i]=max(f[i],f[lower_bound(All.begin(),All.end(),All[i]/Div[j])-All.begin()]);

            }

            int tmp=All[i]/f[i];

            if(f[i]&&tmp<=n&&tmp){

                Ans1++,Ans2^=min(f[i],tmp);

            }

        }

        Write(Ans1,' '),Write(Ans2);

    }

    return 0;

}