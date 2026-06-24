#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m , h;
    cin >> n >> m >> h;

    vector<int> col(m);
    for(int i = 0; i < m; i++)
        cin >> col[i];


    vector<int> row(n);
    for(int i = 0; i < n; i++)
        cin >> row[i];

    vector<vector<int>> height(n , vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> height[i][j];
        }
    }

    vector<vector<int>>answer ( n , vector<int>(m , 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(height[i][j] == 1)
            {
                if(row[i] == col[j])
                {
                    answer[i][j] = row[i];
                }
                else
                {
                    if(col[j] > row[i])
                    {
                        answer[i][j] = row[i];
                    }
                    else
                    {
                        answer[i][j] = col[j];
                    }
                }

            }
        }

    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }



return 0;}