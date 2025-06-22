#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    int m, n;

    cin >> m;
    cin >> n;

    int result = sol.uniquePaths(m, n);
    cout << result << endl;

    return 0;
}
