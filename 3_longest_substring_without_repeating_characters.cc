#include <iostream>
#include <string>
using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            string sub;
            int max = 0;

            for (int i = 0; i < s.size(); i++) {
                sub.clear();
                for (int j = i; j < s.size(); j++) {
                    if (sub.find(s[j]) != string::npos) {
                        max = max > sub.size() ? max : sub.size();
                        //cout << "max: " << max << ", " << sub << endl;
                        sub = s[j];
                    } else {
                        sub += s[j];
                    }
                }
                max = max > sub.size() ? max : sub.size();
            }
            max = max > sub.size() ? max : sub.size();
            //cout << "max: " << max << ", " << sub << endl;
            return max;
        }
};


int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;
    return 0;
}
