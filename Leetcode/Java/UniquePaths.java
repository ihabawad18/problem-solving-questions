package Java;

import java.util.Scanner;

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
}

public class UniquePaths {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution sol = new Solution();
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int result = sol.uniquePaths(m, n);
        System.out.println(result);
    }
}
