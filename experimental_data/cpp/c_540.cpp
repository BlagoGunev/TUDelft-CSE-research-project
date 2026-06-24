#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool ok = false;
int cnt = 0;
int n,m;
int r1,c1,r2,c2;
char a[501][501];
queue<pair<int, int> > q;
char used[501][501];

int moveX[] = {0,1,0,-1};
int moveY[] = {-1,0,1,0};

bool check(int x, int y) {
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    return true;
}

void bfs(int x, int y) {
    q.push(make_pair(x,y));
    a[x][y] = 'X';
    while(!q.empty()) {
        pair<int,int> now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        for(int i=0;i<4;++i) {
            int nx = x+moveX[i];
            int ny = y+moveY[i];
            if(nx == r2 && ny == c2) {
                if(a[nx][ny] == 'X') {
                    printf("YES\n");
                    exit(0);
                }
                else {
                    ok = true;
                    cnt++;
                }
            }
            if(check(nx,ny) && a[nx][ny] != 'X') {
                q.push(make_pair(nx,ny));
                a[nx][ny] = 'X';
            }
        }
    }
}

int main()
{
    scanf("%d %d\n",&n,&m);
    char str[512];
    for(int i=0;i<n;++i) {
        fgets(str, sizeof(str), stdin);
        for(int j=0;str[j];++j)
            a[i][j] = str[j];
    }
    
    scanf("%d %d",&r1,&c1);
    scanf("%d %d",&r2,&c2);
    r1--; c1--;
    r2--; c2--;
    
    bfs(r1,c1);
    
    if(!ok) {
        printf("NO\n");
        return 0;
    }
    
    for(int i=0;i<4;++i) {
        int nx = r2 + moveX[i];
        int ny = c2 + moveY[i];
        if(check(nx,ny) && a[nx][ny] == '.') {
            printf("YES\n");
            return 0;
        }
    }
    
    printf("NO\n");
    return 0;
}