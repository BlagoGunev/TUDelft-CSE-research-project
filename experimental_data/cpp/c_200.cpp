#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#define rank krevedka
#define ran rank
using namespace std;

map<string,int>z;
int k = 0;
string name[4];
int x[5];
int y[5];
int points[5];
int kq[5];

int go(string &s)
{
    //if(++m[s] == 1)  return (z[s] = k++);
    if(z.find(s)==z.end()) {z[s] = k++; return k-1;}
    return z[s];
}

//pair<int,int> go1(int k1,int k2)
bool check()
{
    vector<pair<pair<int,pair<int,int> >,string>  >t(4);
    for(int i=0;i<4;i++)
        t[i] = make_pair(make_pair(-points[i],make_pair(-x[i],-y[i])),name[i]);
    sort(t.begin(),t.end());
    return t[0].second == "BERLAND" || t[1].second == "BERLAND";
}

void go1(int k1,int k2)
{
    points[k1]+=3;
    for(int dx = 1; dx<40;dx++)
    for(int yy = 0;yy<40;yy++)
    {
        x[k1] += dx;
        x[k2] -= dx;
        y[k1] +=dx+yy;
        y[k2] += yy;
        if(check())
        {
            cout << dx+yy<<":"<<yy <<endl;
            return; //true;
        }
            //return make_pair(dx,yy);
        x[k1] -= dx;
        x[k2] += dx;
        y[k1] -=dx+yy;
        y[k2] -= yy;

    }
    points[k1]-=3;
    cout <<"IMPOSSIBLE"<<endl;
    //return make_pair(10000,0);
}

int main()
{
    for(int i=0;i<5;i++)
    {
        string s,t;
        cin >> s >> t;
        int k1 = go(s);
        name[k1] = s; kq[k1]++;
        int k2 = go(t);
        name[k2] = t; kq[k2]++;
        int a,b;
        scanf("%d:%d",&a,&b);
        if(a>b) points[k1]+=3; else
        if(a<b) points[k2]+=3; else
        {
            points[k1]++;
            points[k2]++;
        }
        x[k1] +=a-b;
        x[k2] -=a-b;
        y[k1] +=a;
        y[k2] +=b;
    }
    int k1 = 0;
    while(kq[k1]==3) k1++;
    int k2 = k1+1;
    while(kq[k2]==3) k2++;

    //pair<int,int>r;
    if(name[k1]=="BERLAND")  go1(k1,k2); else go1(k2,k1);
    /*
    if(name[k1]=="BERLAND") r = go(k1,k2); else r = go(k2,k1);
    if(r1.first>1000) cout <<"IMPOSSIBLE";else
    cout << r1.first + r1.second<<':'<<r1.second<<endl;
    */
    return 0;
}