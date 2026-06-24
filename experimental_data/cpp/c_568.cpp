#include <iostream>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <string>
#include <numeric>
#include <set>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

const int MAXN=201;

char val[26];
int nxtVowel[26], nxtCons[26];
char str[MAXN];
char res[MAXN];

struct Rule
{
    int p1, p2;
    int t1,t2;
    Rule(int p1=0, int t1=0, int p2=0, int t2=0):
        p1(p1),p2(p2), t1(t1),t2(t2)
    {}
};

vector<int> v[2*MAXN];
vector<int> vt[2*MAXN];
int comp[2*MAXN];
int used[2*MAXN];
vector<int> order;

bool isVowel(char c)
{
    return val[c-'a']=='V';
}

int neg(int x)
{
    return x^1;
}

int var(int x)
{
    return x*2;
}

void term(int x1, int x2)
{
    v[neg(x1)].push_back(x2);
    v[neg(x2)].push_back(x1);
    vt[x2].push_back(neg(x1));
    vt[x1].push_back(neg(x2));
}

void dfs(int cur)
{
    if(used[cur]) return;
    used[cur]=true;
    for(int i=0;i<v[cur].size();i++)
    {
        dfs(v[cur][i]);
    }
    order.push_back(cur);
}

void color(int cur, int clr)
{
    if(comp[cur]!=-1) return;
    comp[cur]=clr;
    for(int i=0;i<vt[cur].size();i++)
        color(vt[cur][i], clr);
}

bool isSatisfiable(const vector<Rule> &rules, int n, char* s)
{
    int m=rules.size();
    vector<int> res(n,-1);

    for(int i=0;i<2*n;i++)
    {
        v[i].clear();
        vt[i].clear();
    }
    for(int i=0;i<n;i++)
        if(s[i]!='-')
        {
            res[i]=isVowel(s[i]);
            if(val[s[i]-'a']=='V')
                term(var(i), var(i)); //(x or x)
            else
                term(neg(var(i)), neg(var(i))); //(!x or !x)
        }
    for(int i=0;i<m;i++)
    {
        int v1=var(rules[i].p1);
        if(!rules[i].t1)
            v1=neg(v1);

        int v2=var(rules[i].p2);
        if(!rules[i].t2)
            v2=neg(v2);

        if(res[rules[i].p1]==!rules[i].t1 || res[rules[i].p2]==rules[i].t2) continue;
        if(res[rules[i].p1]!=-1 && res[rules[i].p2]!=-1) return false;

        // v1->v2 = !v1 or v2
        term(neg(v1), v2);
    }

    for(int i=0;i<2*n;i++)
    {
        used[i]=0;
        comp[i]=-1;
    }

    for(int i=0;i<2*n;i++)
    {
        if(!used[i])
            dfs(i);
    }
    while(!order.empty())
    {
        int cur=order.back(); order.pop_back();
        if(comp[cur]==-1)
            color(cur, cur);
    }

    for(int i=0;i<n;i++)
        if(comp[var(i)]==comp[neg(var(i))])
            return false;
    return true;
}

int main()
{
    scanf("%s",val);
    int l=strlen(val);

    int lastV=-1, lastC=-1;
    for(int i=l-1;i>=0;i--)
    {
        nxtVowel[i]=lastV;
        nxtCons[i]=lastC;
        if(val[i]=='V')
            lastV=i;
        else
            lastC=i;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    vector<Rule> rules(m);
    REP(i,m)
    {
        int p1, p2;
        char b1[4], b2[4];
        scanf("%d%s%d%s",&p1,b1,&p2,b2);
        rules[i]=Rule(p1-1,b1[0]=='V',p2-1,b2[0]=='V');
    }
    scanf("%s",str);
    if(lastV!=-1 && lastC!=-1)
    {
        for(int pref=n;pref>=0;pref--)
        {
            for(int T=0;T<2;T++)
            {
                for(int i=0;i<pref;i++)
                    res[i]=str[i];
                if(pref<n)
                {
                    int letter=str[pref]-'a';
                    if(nxtCons[letter]==-1 && nxtVowel[letter]==-1) continue;
                    if(nxtCons[letter]==-1 && nxtVowel[letter]!=-1)
                        res[pref]=nxtVowel[letter]+'a';
                    else if(nxtCons[letter]!=-1 && nxtVowel[letter]==-1)
                        res[pref]=nxtCons[letter]+'a';
                    else if(T==0)
                        res[pref]=min(nxtCons[letter], nxtVowel[letter])+'a';
                    else
                        res[pref]=max(nxtCons[letter], nxtVowel[letter])+'a';
                }
                for(int i=pref+1;i<n;i++)
                    res[i]='-';
                if(isSatisfiable(rules, n, res))
                {
                    for(int j=pref+1;j<n;j++)
                    {
                        res[j]=min(lastC, lastV)+'a';
                        if(!isSatisfiable(rules,n,res))
                            res[j]=max(lastC,lastV)+'a';
//                      assert(isSatisfiable(rules,n,res));
                    }
//                  assert(isSatisfiable(rules,n,res));
                    puts(res);
                    return 0;
                }
            }
        }
        puts("-1");
    }
    else
    {
        if(isSatisfiable(rules,n,str))
            puts(str);
        else
            puts("-1");
    }
    return 0;
}