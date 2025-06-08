#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for accumulate

using namespace std;

// Function to compute the minimum distance for each fountain
void solve()
{
    int TC;
    cin >> TC; // Read number of test cases

    while (TC--)
    {
        int n, K;
        cin >> n >> K; // Read n (number of fountains) and K (edge length of the regular polygon)

        vector<int> d(n); // Distances between consecutive circles
        for (int i = 0; i < n; ++i)
        {
            cin >> d[i];
        }

        // To find the circle with the largest possible radius
        int maxRadius = -1;
        int minIndex = -1;

        // Calculate the prefix sum for distance calculation
        vector<int> prefixSum(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + d[(i - 1) % n];
        }

        // Calculate possible radius for each circle
        for (int i = 0; i < n; ++i)
        {
            int radius = min(prefixSum[i + (n / 2)] - prefixSum[i], K - (prefixSum[i + (n / 2)] - prefixSum[i]));
            if (radius > maxRadius)
            {
                maxRadius = radius;
                minIndex = i + 1; // 1-based index
            }
        }

        // Print the smallest index of the circle with the largest radius
        cout << minIndex << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
