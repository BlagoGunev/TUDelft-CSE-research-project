#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
#define PI 3.14159265

int points[1001][5];

int main()
{
    int n;
    vector<int> gpoints;

    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> points[i][j];

    for (int i = 0; i < n; ++i)
    {
        bool good = true;
        for (int j = 0; j < n; ++j)
        {
            if (j != i)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (k != i)
                    {
                        long double dxy = 0, dxx = 0, dyy = 0;
                        for (int l = 0; l < 5; ++l)
                        {
                            dxy += ((points[j][l] - points[i][l]) * (points[k][l] - points[i][l]));
                            dxx += ((points[j][l] - points[i][l]) * (points[j][l] - points[i][l]));
                            dyy += ((points[k][l] - points[i][l]) * (points[k][l] - points[i][l]));
                        }
                        long double lxx = sqrt(dxx), lyy = sqrt(dyy);

                        long double ans = acos(dxy / (lxx * lyy)) * 180.0 / PI;
                        if (ans < 90 || ans != ans)
                        {
                            good = false;
                            break;
                        }
                    }
                }
                if (!good)
                    break;
            }
        }
        if (good)
            gpoints.push_back(i);
    }

    cout << gpoints.size() << '\n';

    for (auto it : gpoints)
        cout << it + 1 << '\n';
}