#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int columns;
    cin >> columns;

    vector<string> grid(2);
    cin >> grid[0] >> grid[1];

    vector<vector<int>> isA(2, vector<int>(columns + 5, 0));

    for (int row = 0; row < 2; row++)
    {
        for (int col = 1; col <= columns; col++) 
        {
            isA[row][col] = (grid[row][col - 1] == 'A');
        }
    }

    auto ds = [&](int x, int y, int z)
    {
        return (x + y + z) / 2;
    };

    const int NEG = -1e9;

    vector<vector<int>> dp(columns + 5, vector<int>(3, NEG));

    dp[0][0] = 0;

    for (int pd = 0; pd <= columns; pd++) 
    {

    
        if (dp[pd][0] != NEG)
        {

            
            if (pd + 3 <= columns) 
            {

                int gain =
                    ds(isA[0][pd + 1], isA[0][pd + 2], isA[0][pd + 3]) +
                    ds(isA[1][pd + 1], isA[1][pd + 2], isA[1][pd + 3]);

                dp[pd + 3][0] =
                    max(dp[pd + 3][0], dp[pd][0] + gain);
            }

            
            if (pd + 2 <= columns)
            {

                int gain =
                    ds(isA[1][pd + 1],
                                  isA[0][pd + 1],
                                  isA[0][pd + 2]);

                dp[pd + 1][1] =
                    max(dp[pd + 1][1], dp[pd][0] + gain);

                
                gain =
                    ds(isA[0][pd + 1],
                                  isA[1][pd + 1],
                                  isA[1][pd + 2]);

                dp[pd + 1][2] =
                    max(dp[pd + 1][2], dp[pd][0] + gain);
            }
        }

      
        if (dp[pd][1] != NEG)
        {           
            if (pd + 4 <= columns)
            {

                int gain =
                    ds(isA[0][pd + 2],
                                  isA[0][pd + 3],
                                  isA[0][pd + 4]) +

                    ds(isA[1][pd + 1],
                                  isA[1][pd + 2],
                                  isA[1][pd + 3]);

                dp[pd + 3][1] =
                    max(dp[pd + 3][1], dp[pd][1] + gain);
            }

       
            if (pd + 2 <= columns)
            {

                int gain =
                    ds(isA[1][pd + 1],
                                  isA[1][pd + 2],
                                  isA[0][pd + 2]);

                dp[pd + 2][0] =
                    max(dp[pd + 2][0], dp[pd][1] + gain);
            }
        }

        if (dp[pd][2] != NEG)
        {
        
            if (pd + 4 <= columns)
            {

                int gain =
                    ds(isA[1][pd + 2],
                                  isA[1][pd + 3],
                                  isA[1][pd + 4]) +

                    ds(isA[0][pd + 1],
                                  isA[0][pd + 2],
                                  isA[0][pd + 3]);

                dp[pd + 3][2] =
                    max(dp[pd + 3][2], dp[pd][2] + gain);
            }


            if (pd + 2 <= columns) 
            {
                int gain =
                    ds(isA[0][pd + 1],
                                  isA[0][pd + 2],
                                  isA[1][pd + 2]);

                dp[pd + 2][0] =
                    max(dp[pd + 2][0], dp[pd][2] + gain);
            }
        }
    }
    cout << dp[columns][0] << '\n';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) 
    {
        solve();
    }
}