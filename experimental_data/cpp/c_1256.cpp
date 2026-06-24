#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool us[100];
int gcd(int a, int b)
{
    if(a==0) return b;
    return gcd(b%a, a);
}

void print(vector<int> a, int n)
{
    for(int i = 0; i < n; ++i)
        cout << a[i]+1 << ' ';
    cout << '\n';
}

bool change(vector<int> &a, vector <int> &b, int i, int &c, int n)
{
    if(i >= 0 && us[i] && c < n && b[i]>b[i+1])
    {
        b[i] += b[i+1];
        b[i+1] = b[i]-b[i+1];
        b[i] -= b[i+1];
        a[b[i]] += a[b[i+1]];
        a[b[i+1]] = a[b[i]]-a[b[i+1]];
        a[b[i]] -= a[b[i+1]];
        us[i] = false;
        ++c;
        return true;
    }
    return false;

}


int main()
{
    long long n, m, d;
    cin >> n >> m >> d;
    vector<int> c(m);
    int s=0;
    for(int i = 0; i < m; ++i)
    {
        cin >> c[i];
        s+=c[i];
    }
    if(s+(d-1)*(m+1) < n) cout << "NO";
    else{
        cout << "YES\n";
        vector<int> suf(m+1);
        suf[m]=0;
        for(int i = m-1; i >=0; --i)
        {
            suf[i] = suf[i+1]+c[i];
        }

        int i = 0;
        int k = 0;
     //   cout << n-k-c[i] << '\n';
     //   cout << suf[i+1]+(d-1)*(m-i) << '\n';
        while(i < m && suf[i+1]+(d-1)*(m-i) >= n-k-c[i])
        {
            k += c[i];
            for(int j = 0; j < c[i]; ++j)
                cout << i+1 << ' ';
            ++i;
        }
      //  cout << 'a';
        if(i <  m)
        {
        //    cout << n-k-c[i] << '\n';
        //    cout << suf[i+1]+(d-1)*(m-i) << '\n';
            for (int j1 = 0; j1 < n-k-c[i] - suf[i+1]-(d-1)*(m-i); ++j1)
                cout << "0 ";
            for(int j = 0; j < c[i]; ++j)
                cout << i+1 << ' ';
            ++i;
            for(; i < m; ++i)
            {
                for(int j = 0; j < d-1; ++j)
                    cout << "0 ";
                for(int j = 0; j < c[i]; ++j)
                    cout << i+1 << ' ';
            }
            for(int j = 0; j < d-1; ++j)
                    cout << "0 ";
        }
        else for(int j = 0; j < n-k; ++j)
            cout << "0 ";
    }
    return 0;
}