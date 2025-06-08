#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
        {
            return false; // Different lengths cannot be close
        }
        // freq arrays to count character frequencies
        int freq1[26] = {0}, freq2[26] = {0};
        bool checked[26] = {false};
        for (char c : word1)
        {
            freq1[c - 'a']++;
        }
        for (char c : word2)
        {
            freq2[c - 'a']++;
        }
        // Check if both words have same characters
        for (int i = 0; i < 26; i++)
        {
            if ((freq1[i] > 0 && freq2[i] == 0) || (freq1[i] == 0 && freq2[i] > 0))
            {
                return false; // One word has a character that the other does not
            }
        }
        // Check if both words have same number of occurrences we don't care about the type of characters but they
        // should have same frequency distribution
        sort(freq1, freq1 + 26);
        sort(freq2, freq2 + 26);
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string word1, word2;
    cin >> word1 >> word2;

    bool result = sol.closeStrings(word1, word2);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
