#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> counter;
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for (vector<int> row : grid)
        {
            counter[row] += 1;
        }
        for (int i = 0; i < row; i++)
        {
            vector<int> column_list = {};
            for (int j = 0; j < col; j++)
            {
                column_list.push_back(grid[j][i]);
            }
            ans += counter[column_list];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int result = sol.equalPairs(grid);
    cout << result << endl;
    return 0;
}
