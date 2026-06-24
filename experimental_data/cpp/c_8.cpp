#include <iostream>
#include <vector>
using namespace std;

int xs, ys;
int n;
int x[24], y[24];

int t1[24];
int t2[24][24];

int d[1 << 24];
int back[1 << 24];

int go(int left, int i)
{
    if (left == 0) return 0;
    int &r = d[left];
    int &b = back[left];
    if (r > 0) return r-1;
    for (; i < n; ++i) if (left >> i & 1) break;
    int c = go(left ^ (1 << i), i+1) + 2*t1[i];
    if (!r || r > c + 1) r = c + 1, b = left ^ (1 << i);
    if ((left >> (i+1)) > 0)
    for (int j = i + 1; j < n; ++j)
    if (left >> j & 1)
    {
        c = go(left ^ (1 << i) ^ (1 << j), i+1) + t2[i][j];
        if (!r || r > c + 1) r = c + 1, b = left ^ (1 << i) ^ (1 << j);
    }
    return r - 1;
}


vector<int> way(int left)
{
    if (left == 0)
    {
        return vector<int>(1, 0);
    }
    int b = back[left];
    vector<int> res = way(b);
    for (int i = 0; i < n; ++i)
        if ((b ^ (1 << i)) == left)
        {
            res.push_back(i+1);
            res.push_back(0);
            return res;
        }
    for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
        if ((b ^ (1 << i) ^ (1 << j)) == left)
        {
            res.push_back(i+1);
            res.push_back(j+1);
            res.push_back(0);
            return res;
        }
    return res;
}

int main()
{
    cin >> xs >> ys;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i)
    {
        t1[i] = (x[i]-xs)*(x[i]-xs) + (y[i]-ys)*(y[i]-ys);
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
        t2[i][j] = t1[i] + t1[j] + (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    }
    cout << go((1 << n) - 1, 0) << endl;
    vector<int> w = way((1 << n) - 1);
    cout << w[0];
    for (int i = 1; i < w.size(); ++i)
        cout << " " << w[i];
    cout << endl;
        
    return 0;
}