#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 100006
#define MOD (long long)1000000007
using namespace std;

inline ll getnum()
{
    char c = getchar();
    int num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

char S[100],temp[40];
int val[405],done[100023],there[100023],sorted[100023];
unordered_map<string,int> Map,Gap;
vector<int> V[100023],W[100023],todo;
string All[100003];
queue<piii > Q;

void thatsort()
{
    int ind=Q.front().ff,l=Q.front().ss.ff,r=Q.front().ss.ss;
    Q.pop();

    //cout<<ind<<' '<<l<<' '<<r<<endl;

    int pos=0;
    for(int i=l;i<=r;i++)
    {
        if(done[V[sorted[i]][ind]]==0)todo.pb(V[sorted[i]][ind]);
        done[V[sorted[i]][ind]]++;
    }

    done[todo[0]]+=l-1;

    for(int i=1;i<todo.size();i++)done[todo[i]]+=done[todo[i-1]];
    for(int i=todo.size()-1;i>0;i--)done[todo[i]]=done[todo[i-1]]+1;
    done[todo[0]]=l;

    //cout<<"hre\n";

    int x=l;

    for(int i=l;i<=r;i++)
    {
        there[done[V[sorted[i]][ind]]]=sorted[i];
        done[V[sorted[i]][ind]]++;
    }

    for(int i=l;i<=r;i++)sorted[i]=there[i];

    for(int i=0;i<todo.size();i++)
    {
        if(todo[i]>0)Q.push(mp(ind+1,mp(x,done[todo[i]]-1)));
        x=done[todo[i]];
        done[todo[i]]=0;
    }

    todo.clear();
}

int main()
{
    for(char i='a';i<='z';i++)val[(int)i]=i-'a'+1;
    val[(int)'.']=27;
    val[(int)'/']=28;

    int n=getnum(),ind=0,wind=0;

    for(int i=1;i<=n;i++)
    {
        sorted[i]=i;

        gets(S+1);
        int j=8,k;

        for(k=1;S[j]!=0&&S[j]!='/';j++,k++)temp[k]=S[j];
        temp[k]=0;

        string x=string(temp+1);

        if(Map[x]==0)
        {
            Map[x]=++ind;
            All[ind]=x;
        }

        int pos=Map[x];

        for(k=1;S[j]!=0;j++,k++)temp[k]=S[j];
        temp[k]=0;

        x=string(temp+1);

        if(Gap[x]==0)Gap[x]=++wind;

        int y=Gap[x];

        V[pos].pb(y);
    }

    vector<int>::iterator it;

    for(int i=1;i<=ind;i++)
    {
        sort(V[i].begin(),V[i].end());
        it=unique(V[i].begin(),V[i].end());
        V[i].erase(it,V[i].end());
        V[i].pb(0);
    }

    Q.push(mp(0,mp(1,ind)));

    while(!Q.empty())thatsort();

    int ans=0;
    wind=0;

    for(int i=1;i<=ind;i++)
    {
        int l=sorted[i-1],r=sorted[i];

        if(V[l].size()!=V[r].size())wind++;
        else
        {
            int flag=1;
            for(int j=0;j<V[r].size();j++)if(V[r][j]!=V[l][j])flag=0;

            if(!flag)wind++;
        }

        W[wind].pb(sorted[i]);
        if(W[wind].size()==2)todo.pb(wind);
    }

    printf("%d\n",todo.size());

    for(int i=0;i<todo.size();i++)
    {
        for(int j=0;j<W[todo[i]].size();j++)
        {
            printf("http://%s ",All[W[todo[i]][j]].c_str());
        }
        puts("");
    }
}