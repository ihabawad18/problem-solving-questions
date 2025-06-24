// Hi, here's your problem today. This problem was recently asked by Amazon:

// You are given a string s, and an integer k. Return the length of the longest substring in s that contains at most k distinct characters.

// For instance, given the string:
// aabcdefff and k = 3, then the longest substring with 3 distinct characters would be defff. The answer should be 5.

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int left = 0, right = 0, maxLength = 0;
        map<char, int> charCount;

        while (right < s.size())
        {
            charCount[s[right]]++;

            while (charCount.size() > k)
            {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0)
                {
                    charCount.erase(s[left]);
                }
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    string s;
    int k;

    cin >> s >> k;

    int result = sol.lengthOfLongestSubstringKDistinct(s, k);
    cout << result << endl;
    return 0;
}
