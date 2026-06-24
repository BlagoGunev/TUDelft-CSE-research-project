#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100;

int n, k;
vector<pair<int, int>> places[3];

char field [MAXN][12];

inline bool valid(int index){
    return index >= 0 && index < 12;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin>>n>>k;
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        for(int j = 0; j < 12; j++)
            field[i][j] = s[j];

        for(int j = 0; j < 12; j++){
            if(s[j] == '-')continue;
            if(s[j] == 'S')continue;
            if(s[j] == 'P')continue;
            
            int delta = 0;
            if(valid(j - 1) && s[j - 1] == 'S')delta++;
            if(valid(j + 1) && s[j + 1] == 'S')delta++;

            places[delta].push_back(make_pair(i, j));
        }
    }

    for(int delta = 0; delta <= 2 && k > 0; delta++)
        for(int index = 0; index < places[delta].size() && k > 0; index++, k--)
            field[places[delta][index].first][places[delta][index].second] = 'x';
    
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++){
            if(field[i][j] != 'S')continue;
            if(valid(j - 1))
                if(field[i][j - 1] == 'P' || field[i][j - 1] == 'S' || field[i][j - 1] == 'x')
                    result++;
            if(valid(j + 1))
                if(field[i][j + 1] == 'P' || field[i][j + 1] == 'S' || field[i][j + 1] == 'x')
                    result++;
            
        }
    }

    cout<<result<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 12; j++)
            cout<<field[i][j];
        cout<<endl;
    }

    return 0;
}