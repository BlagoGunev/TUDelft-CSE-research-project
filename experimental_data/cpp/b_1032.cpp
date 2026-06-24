#include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        string s;
        cin >> s;
        int str = s.length();
        int zv = 0;
        int a;
        int b;
        for (int i = 1; i <= 5; i++)
        {
            int cur;
            if (str % i == 0)
            {
                cur = str / i;
            }
            else cur = str / i + 1;
            if (cur <= 20)
            {
                a = i;
                b = cur;

                zv = a*b - str;
                break;
            }
        }
        int zv2 = zv % a;
        int zv1 = zv / a;
        int cur = 0;
        int cur1 = 0;
        cout << a << ' ' << b << endl;
        for (int i = 0; i < a; i++)
        {
            for (int t = 0; t < zv1; t++)
                {
                    cout << '*';
                    cur1++;
                }
                if (zv2 > 0)
                {
                    cout << '*';
                    cur1++;
                    zv2--;
                }
                for (int i = 0; i < b - cur1; i++)
                {
                    cout << s[cur];
                    cur++;
                }
                cur1 = 0;
            cout << endl;
        }
    }