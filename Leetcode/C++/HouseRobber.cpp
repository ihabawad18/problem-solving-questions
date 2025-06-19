#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int i, bool taken, vector<vector<int>> &dp, vector<int> &nums)
    {
        if (i == nums.size())
        {
            return 0;
        }

        int &ret = dp[i][taken];
        if (ret != -1)
        {
            return ret;
        }

        // Option 1: Skip current
        ret = helper(i + 1, false, dp, nums);

        // Option 2: Take current if previous was not taken
        if (!taken)
        {
            ret = max(ret, nums[i] + helper(i + 1, true, dp, nums));
        }

        return ret;
    }

    int rob(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, -1));
        return helper(0, false, dp, nums);
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int result = sol.rob(nums);
    cout << result << endl;

    return 0;
}
