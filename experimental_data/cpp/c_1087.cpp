#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <set>
//#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int2 pair<int, int>
#define MP make_pair
#define PB push_back
#define X first
#define Y second

vector<int2> vec;
vector<int2> out;

void init(){
    for(int i = 0; i < 3; i++){
        int x, y;
        cin >> x >> y;
        
        vec.PB(MP(x, y));
    }
}

void prepare(){
    sort(vec.begin(), vec.end());
}

int bb;
int2 best;

void printLine(int2 a, int2 b, int2 d){
    int2 c = a;
    bb = abs(d.X-c.X) + abs(d.Y - c.Y);
    best = c;
    
    while(c.X != b.X || c.Y != b.Y){
        if(c.X < b.X)
            c.X++;
        else if(c.X > b.X)
            c.X--;
        else if(c.Y < b.Y)
            c.Y++;
        else if(c.Y > b.Y)
            c.Y--;
        else
            break;
//        cout << c.X << " " << c.Y << "hello\n";
        int nb = abs(d.X-c.X) + abs(d.Y - c.Y);
        if(nb < bb){
            best = c;
            bb = nb;
        }
        out.PB(c);
    }
}

void solve(){
    out.PB(vec[0]);
    printLine(vec[0], vec[1], vec[2]);
    printLine(best, vec[2], vec[0]);
//    out.PB(vec[1]);
//    out.PB(vec[2]);
    
    cout << out.size() << "\n";
    
    for(int i = 0; i < out.size(); i++)
        cout << out[i].X << " " << out[i].Y << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    prepare();
    solve();
    
    return 0;
}