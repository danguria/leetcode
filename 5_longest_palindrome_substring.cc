#include <iostream>
using namespace std;

class Solution {
    public:
        virtual string longestPalindrome(string) = 0;
};

class BruteForce : public Solution {
    public:
        bool IsPalindrome(string s) {
            int i = 0, j = s.size() -1;

            while (i != j && i < j)
                if (s[i++] != s[j--]) return false;
            return true;
        }

        virtual string longestPalindrome(string s) {

            int size = s.size();
            int longest = 1, start = 0;
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j < size; j++) {
                    int len = j - i + 1;
                    if (IsPalindrome(s.substr(i, len))) {
                        if (len > longest) {
                            longest = len;
                            start = i;
                        }
                    }
                }
            }
                       
            return s.substr(start, longest);
        }

};

class DP : public Solution {
    public:

        virtual string longestPalindrome(string s) {

            int size = s.size();
            bool DP[size][size];

            int longest = 1;
            int start = 0;
            for (int j = 0; j < size; j++) {
                for (int i = size - 1; i >= 0; i--) {
                    DP[i][j] = (s[i] == s[j]) && ((i + 1) >= (j - 1) || DP[i + 1][j - 1]);

                    if (DP[i][j] && j - i + 1 > longest) {
                        longest = j - i + 1;
                        start = i;
                    }
                }
            }

            return s.substr(start, longest);
        }
};

void execute(Solution& s) {
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("abc") << endl;
    cout << s.longestPalindrome("ccc") << endl;
}

int main() {

    BruteForce bf;
    DP dp;

    execute(bf);
    execute(dp);

    return 0;
}
