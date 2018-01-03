#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            if (p.empty()) return s.empty();

            // ab, a*b
            if (p[1] == '*') {
                return (isMatch(s, p.substr(2))
                        || (!s.empty() && (s[0] == p[0] || p[0] == '.' ) && isMatch(s.substr(1), p)));
            } else {
                return !s.empty() && (s[0] == p[0] || p[0] == '.' ) && isMatch(s.substr(1), p.substr(1));
            }
        }
};

int main() {
    Solution s;
    cout << s.isMatch("aa", "aa") << endl;
    return 0;
}
