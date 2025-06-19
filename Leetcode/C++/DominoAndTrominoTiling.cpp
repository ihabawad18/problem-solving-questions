#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilings(int n)
    {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[0][0] = 1;
        dp[0][1] = 0;

        for (int i = 1; i <= n; ++i)
        {
            // triPlaced == false (0)
            dp[i][0] = dp[i - 1][0];
            if (i >= 2)
            {
                dp[i][0] = (dp[i][0] + dp[i - 2][0]) % MOD;
                dp[i][0] = (dp[i][0] + 2LL * dp[i - 2][1] % MOD) % MOD;
            }

            // triPlaced == true (1)
            dp[i][1] = dp[i - 1][1];
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        }

        return dp[n][0];
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;

    int result = sol.numTilings(n);
    cout << result << endl;

    return 0;
}
