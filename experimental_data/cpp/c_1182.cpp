#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
        return true;
    return false;
}

int trans(char c) {
    if (c == 'a')
        return 0;
    if (c == 'e')
        return 1;
    if (c == 'o')
        return 2;
    if (c == 'i')
        return 3;
    return 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector <string> ws(n);
    for (int i = 0; i < n; ++i)
        cin >> ws[i];
    
    unordered_map <int, vector <int> > hsh[5];
    vector <pair<int, int> > ps;
    for (int i = 0; i < n; ++i) {
        const string& tmp = ws[i];
        int cnt = 0;
        char last;
        for (int j = 0; j < tmp.length(); ++j) {
            if (isVowel(tmp[j])) {
                last = tmp[j];
                cnt += 1;
            }
        }
        // cout << i << " " << cnt << " " << last << endl;
        int d = trans(last);
        if (hsh[d].find(cnt) == hsh[d].end())
            hsh[d].emplace(cnt, vector <int>());
        if (hsh[d][cnt].size() == 1) {
            ps.emplace_back(i + 1, hsh[d][cnt][0]);
            hsh[d][cnt].pop_back();
        } else {
            hsh[d][cnt].push_back(i + 1);
        }
    }
    vector <pair<int, int> > ups;
    unordered_map <int, int> wait;
    for (const auto& h : hsh) {
        for (const auto& p : h) {
            int len = p.first;
            for (const auto& id : p.second) {
                if (wait[len] == 0) {
                    wait[len] = id;
                } else {
                    ups.emplace_back(wait[len], id);
                    wait[len] = 0;
                }
            }
        }
    }
    /*cout << ps.size() << " " << ups.size() << endl;
    cout << endl;
    for (const auto& p : ps)
        cout << p.first << " " << p.second << endl;
    cout << endl;
    for (const auto& p : ups)
        cout << p.first << " " << p.second << endl;
    cout << endl;*/
    cout << min(ups.size(), ps.size()) + max(0, int(ps.size() - ups.size()) / 2) << endl;
    for (int i = 0; i < ps.size(); ++i) {
        if (ups.size()) {
            auto p = ups.back();
            cout << ws[p.first - 1] << " " << ws[ps[i].first - 1] << '\n';
            cout << ws[p.second - 1] << " " << ws[ps[i].second - 1] << '\n';
            ups.pop_back();
        } else if (i != ps.size() - 1) {
            auto p = ps.back();
            cout << ws[p.first - 1] << " " << ws[ps[i].first - 1] << '\n';
            cout << ws[p.second - 1] << " " << ws[ps[i].second - 1] << '\n';
            ps.pop_back();
        }
    }
        
    return 0;
}