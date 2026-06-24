/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define HOME 

#define MX 100005
int N, M, K;

int board[101][MX];
char input[MX];
long long ret = 0;
int main()
{
#ifdef HOME
    freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &N, &M);
    for(int i = 0;i < N;i++)
    {
        scanf("%s", input);
        for(int j = 0;j < M;j++)
        {
            if(input[j] == '.')
                board[i][j] = 0;
            else if(input[j] == '+')
                board[i][j] = 1;
            else 
                board[i][j] = 2;
        }
    }
    int p = 0;
    int dir = 1;
    int tmpr[MX], mr, tmpl[MX], ml;
    bool gr , gl;
    for(int i = 0;i < N-1;i++)
    {
        int pr = p, pl = p;
        ml = mr = 0;
        gr = gl = true;

        if(board[i+1][p] == 0)
        {
            ret ++;
            continue;
        }
        for(pr = p+1;pr <= M;pr++)
        {
            if(pr == M || board[i][pr] == 2)
            {
                tmpr[mr++] = pr;
                gr = false;
                break;
            }
            else if(board[i][pr] == 1)
                tmpr[mr++] = pr;
            
            if(0 == board[i+1][pr])
                break;
        }
        for(pl = p-1; pl >= -1;pl--)
        {
            if(pl == -1 || board[i][pl] == 2)
            {
                tmpl[ml++] = pl;
                gl = false;
                break;
            }
            else if(board[i][pl] == 1)
            {
                tmpl[ml++] = pl;
            }
            if(0 == board[i+1][pl])
                break;
        }
        if(!gl && !gr)
            break;

        int pl_n = 0, pr_n = 0;
        while(true)
        {
            if(dir == 1)
            {
                if(gr && (pr_n == mr || tmpr[pr_n] > pr))
                {
                    ret += pr - p;
                    p = pr;
                    break;
                }
                ret += tmpr[pr_n] - p;
                dir = 0;
                p = tmpr[pr_n] - 1;
                if(gr || pr_n < mr-1)
                    pr_n++;
            }
            else
            {
                if(gl && (pl_n == ml || tmpl[pl_n] < pl))
                {
                    ret += p - pl;
                    p = pl;
                    break;
                }
                
                ret += p - tmpl[pl_n];
                dir = 1;
                p = tmpl[pl_n] + 1;
                if(gl || pl_n < ml - 1)
                    pl_n++;
            }
        }
        ret++;
    }
    if(!gl && !gr)
        cout<<"Never"<<endl;
    else 
        cout<<ret<<endl;
    return 0;
}