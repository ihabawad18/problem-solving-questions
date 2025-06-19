package Java;

import java.util.Arrays;
import java.util.Scanner;

class Solution {
    public int helper(int i, int taken, int[][] dp, int[] nums) {
        if (i == nums.length) {
            return 0;
        }

        if (dp[i][taken] != -1) {
            return dp[i][taken];
        }

        // Option 1: skip current
        dp[i][taken] = helper(i + 1, 0, dp, nums);

        // Option 2: take current if previous not taken
        if (taken == 0) {
            dp[i][taken] = Math.max(dp[i][taken], nums[i] + helper(i + 1, 1, dp, nums));
        }

        return dp[i][taken];
    }

    public int rob(int[] nums) {
        int[][] dp = new int[nums.length + 1][2];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return helper(0, 0, dp, nums);
    }
}

public class HouseRobberMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input size and array
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        Solution sol = new Solution();
        int result = sol.rob(nums);

        System.out.println("Maximum amount that can be robbed: " + result);
    }
}
