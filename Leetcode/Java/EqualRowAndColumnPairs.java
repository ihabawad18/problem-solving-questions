package Java;
import java.util.*;


class Solution {
    public int equalPairs(int[][] grid) {
        Map<List<Integer>, Integer> rowCounter = new HashMap<>();
        int n = grid.length;
        int ans = 0;

        // Count frequency of each row
        for (int i = 0; i < n; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add(grid[i][j]);
            }
            rowCounter.put(row, rowCounter.getOrDefault(row, 0) + 1);
        }

        // Compare with columns
        for (int col = 0; col < n; col++) {
            List<Integer> column = new ArrayList<>();
            for (int row = 0; row < n; row++) {
                column.add(grid[row][col]);
            }
            ans += rowCounter.getOrDefault(column, 0);
        }

        return ans;
    }
}

public class EqualRowAndColumnPairs {
    public static void main(String[] args) {
        int[][] grid = {
            {3, 2, 1},
            {1, 7, 6},
            {2, 7, 7}
        };

        Solution solution = new Solution();
        int result = solution.equalPairs(grid);
        System.out.println("Equal Row and Column Pairs: " + result);
    }
}
