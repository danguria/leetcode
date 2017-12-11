#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int n = strs.size();
            if (strs.size() == 0) return string("");
            if (strs.size() == 1) return strs[0];

            int m1 = strs[0].size();
            int last_index;

            for (int col = 0; col < m1; col++) {
                char c = strs[0][col];
                bool matched = true;
                last_index = col;

                for (int row = 1; row < n; row++)
                    if (col >= strs[row].size() || strs[row][col] != c)
                        matched = false;

                if (!matched) {
                    last_index--;
                    break;
                }
            }
            return strs[0].substr(0, last_index + 1);
        }
};

int main() {

    vector<string> s1 = {"abcd", "abce", "abcf"};
    vector<string> s2 = {"abcd"};
    vector<string> s3;
    vector<string> s4 = {"ab", "abce", "abcf"};
    vector<string> s5 = {"ab", "ab", "ab"};
    vector<string> s6 = {"ab", "cd", "ef"};
    vector<string> s7 = {"aa", "a"};
    Solution s;

    cout << s.longestCommonPrefix(s1) << endl; // abc
    cout << s.longestCommonPrefix(s2) << endl; // abcd
    cout << s.longestCommonPrefix(s3) << endl; // ""
    cout << s.longestCommonPrefix(s4) << endl; // ab
    cout << s.longestCommonPrefix(s5) << endl; // ab
    cout << s.longestCommonPrefix(s6) << endl; // ""
    cout << s.longestCommonPrefix(s7) << endl; // a

    return 0;
}
