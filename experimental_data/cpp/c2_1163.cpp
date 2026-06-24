#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstring>
#define LL long long
#define X first
#define Y second

using namespace std;

const int VAL=1005;
const int INF=1000000000;
//const double PI=3.14159265359;

int N, i, j, K, v[VAL], M, nr, t, k;
long long ANS, X;
pair <double, int> Panta[VAL];
double D, DR[VAL*VAL];
bool ok[VAL][VAL];
pair <double, double> P[VAL];

int main()
{
    cin >> N;
    for (i=1; i<=N; i++)
        cin >> P[i].X >> P[i].Y;
    for (i=1; i<=N; i++)
    {
        K=0;
        for (j=i+1; j<=N; j++)
        {
            if (ok[i][j]==false && ok[j][i]==false)
            {
                K++;
                if (P[i].X==P[j].X)
                    D=INF;
                else
                    D=(P[i].Y-P[j].Y) / (P[i].X-P[j].X);
                Panta[K]={D, j};
            }
        }
        sort(Panta+1, Panta+K+1);
        j=1;
        if (j>K)
            continue;
        while (1)
        {
            M=0;
            DR[++nr]=Panta[j].first;
            for (k=j; k<=K; k++)
            {
                if (Panta[j].first==Panta[k].first)
                    v[++M]=Panta[k].second;
                else
                    break;
            }
            j=k;
            for (k=1; k<=M; k++)
            {
                ok[i][v[k]]=ok[v[k]][i]=true;
                for (t=1; t<=M; t++)
                    ok[v[k]][v[t]]=ok[v[t]][v[k]]=true;
            }
            if (j>K)
                break;
        }
    }
    sort(DR+1, DR+nr+1);
    ANS=1LL*nr*(nr-1);
    ANS/=2;
    j=1;
    for (i=2; i<=nr; i++)
    {
        if (DR[i]==DR[i-1])
        {
            j++;
            ANS-=j-1;
        }
        else
            j=1;
    }
    cout << ANS;
    return 0;
}