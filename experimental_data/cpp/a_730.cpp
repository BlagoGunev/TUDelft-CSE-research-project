#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAXN 1002
#define F first
#define S second
typedef unsigned long long ull;

int r[102];
int n;

int table[10002][3], matches;



void loseKatka(set<pair<int, int> > &rq, int rt){
    auto i1 = rq.begin();
    auto i2 = rq.begin();
    i2++;
    pair<int, int> m1 = *i1, m2 = *i2;
    rq.erase(m1);
    rq.erase(m2);
    if(m1.F+1 != -rt) rq.insert(make_pair(m1.F+1, m1.S));
    if(m2.F+1 != -rt) rq.insert(make_pair(m2.F+1, m2.S));

    table[matches][0] = m1.S;
    table[matches][1] = m2.S;
    table[matches][2] = -1;
    matches++;
}

bool canBallance(int rt){
    int toLose = 0, bal = 0;
    for(int i = 0; i < n; i++){
        if(rt > r[i])
            return false;
        toLose += r[i] - rt;
    }

    matches = 0;
    set<pair<int, int> > rq;
    for(int i = 0; i < n; i++){
        if(r[i] == rt){
            continue;
        }
        rq.insert(make_pair(-r[i], i));
    }

    if(toLose %2 == 1){
        if(rq.size() < 3)
            return false;
        auto i1 = rq.begin();
        auto i2 = rq.begin();
        auto i3 = rq.begin();
        i2++;i3++;i3++;
        pair<int, int> m1 = *i1, m2 = *i2, m3 = *i3;
        rq.erase(m1);
        rq.erase(m2);
        rq.erase(m3);
        if(m1.F+1 != -rt) rq.insert(make_pair(m1.F+1, m1.S));
        if(m2.F+1 != -rt) rq.insert(make_pair(m2.F+1, m2.S));
        if(m3.F+1 != -rt) rq.insert(make_pair(m3.F+1, m3.S));

        table[matches][0] = m1.S;
        table[matches][1] = m2.S;
        table[matches][2] = m3.S;
        matches++;
    }

    while(rq.size() >= 2){
        loseKatka(rq, rt);
    }
    return rq.size() == 0;
}

int main(){

    int maxR = -1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> r[i];
        maxR = max(maxR, r[i]);
    }

    int ans = 0, resMatches;
    for(int i = maxR; i > 0; i--){
        if(canBallance(i)){
            ans = i;
            resMatches = matches;
            break;
        }
    }

    cout << ans << endl;
    char match[103];
    match[n] = 0;
    for(int i = 0; i < n; i++){
        match[i] = '0';
    }

    if(ans == 0){
        matches = 0;
        set<pair<int, int> > rq;
        for(int i = 0; i < n; i++){
            if(r[i] == 0){
                continue;
            }
            rq.insert(make_pair(-r[i], i));
        }

        while(rq.size() >= 2){
            loseKatka(rq, 0);
        }

        while(rq.size() != 0){
            pair<int, int> m1 = *rq.rbegin();
            rq.erase(m1);
            if(m1.F+1 != 0) rq.insert(make_pair(m1.F+1, m1.S));

            table[matches][0] = m1.S;
            table[matches][1] = (m1.S+1)%n;
            table[matches][2] = -1;
            matches++;
        }

        cout << matches << endl;
        if(matches > 10000)
            return 1;
        for(int i = 0; i < matches; i++){
            match[table[i][0]] = '1';
            match[table[i][1]] = '1';
            if(table[i][2] != -1) match[table[i][2]] = '1';

            printf("%s\n", match);

            match[table[i][0]] = '0';
            match[table[i][1]] = '0';
            if(table[i][2] != -1) match[table[i][2]] = '0';
        }
    }
    else {
        cout << resMatches << endl;
        if(resMatches > 10000)
            return 1;
        for(int i = 0; i < resMatches; i++){
            match[table[i][0]] = '1';
            match[table[i][1]] = '1';
            if(table[i][2] != -1) match[table[i][2]] = '1';

            printf("%s\n", match);

            match[table[i][0]] = '0';
            match[table[i][1]] = '0';
            if(table[i][2] != -1) match[table[i][2]] = '0';
        }
    }


}