package Java;

import java.util.Scanner;

class Solution {
    public int numTilings(int n) {
        final int MOD = 1_000_000_007;
        int[][] dp = new int[n + 1][2];

        dp[0][0] = 1;
        dp[0][1] = 0;

        for (int i = 1; i <= n; i++) {
            // triPlaced == false (0)
            dp[i][0] = dp[i - 1][0];
            if (i >= 2) {
                dp[i][0] = (dp[i][0] + dp[i - 2][0]) % MOD;
                dp[i][0] = (int) ((dp[i][0] + 2L * dp[i - 2][1] % MOD) % MOD);
            }

            // triPlaced == true (1)
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
        }

        return dp[n][0];
    }
}

public class DominoAndTrominoTiling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.print("Enter n: ");
        int n = scanner.nextInt();

        int result = sol.numTilings(n);
        System.out.println("Number of tilings: " + result);
    }
}
