package Java;
import java.util.Arrays;

class Solution {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false; // Different lengths cannot be close
        }

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        // Count character frequencies
        for (char c : word1.toCharArray()) {
            freq1[c - 'a']++;
        }
        for (char c : word2.toCharArray()) {
            freq2[c - 'a']++;
        }

        // Check if both words use the same set of characters
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] > 0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] > 0)) {
                return false;
            }
        }

        // Check if frequency distribution is the same
        Arrays.sort(freq1);
        Arrays.sort(freq2);

        return Arrays.equals(freq1, freq2);
    }
}

public class DetermineIfTwoStringsAreClose {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Test case
        String word1 = "abc";
        String word2 = "bca";

        boolean result = sol.closeStrings(word1, word2);
        System.out.println("Are the strings close? " + result);
    }
}
