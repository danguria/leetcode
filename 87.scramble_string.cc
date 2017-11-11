#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
        virtual bool isScramble(string s1, string s2) = 0;
};

class Recursive : public Solution {

    public:
        virtual bool isScramble(string s1, string s2) {
            int len = s1.size();
            if (len != s2.size()) return false;
            if (s1 == s2) return true;

            for (int i=1; i < len; ++i) {
                string s1l = s1.substr(0, i), s1r = s1.substr(i, len);
                // w/o swap
                string s2l = s2.substr(0, i), s2r = s2.substr(i, len);
                if (isScramble(s1l, s2l) && isScramble(s1r, s2r)) return true;
                // w/ swap
                s2l = s2.substr(0, len-i); s2r = s2.substr(len-i, len);
                if (isScramble(s1l, s2r) && isScramble(s1r, s2l)) return true;
            }

            return false;
        }
};

class RecursiveWithCache : public Solution {
    public:
        virtual bool isScramble(string s1, string s2) {
            std::map<string, string> map;
            return isScramble(s1, s2, map);
        }
    private:
        bool isScramble(string s1, string s2, std::map<string, string>& map) {
            int len = s1.size();
            if (len != s2.size()) return false;
            if (s1 == s2) {
                map[s1] = s2;
                return true;
            }

            for (int i=1; i < len; ++i) {
                string s1l = s1.substr(0, i), s1r = s1.substr(i, len);
                // w/o swap
                string s2l = s2.substr(0, i), s2r = s2.substr(i, len);
                if (isScramble(s1l, s2l) && isScramble(s1r, s2r)) {
                    map[s1l] = s2l;
                    map[s1r] = s2r;
                    return true;
                }
                // w/ swap
                s2l = s2.substr(0, len-i); s2r = s2.substr(len-i, len);
                if (isScramble(s1l, s2r) && isScramble(s1r, s2l)) {
                    map[s1l] = s2r;
                    map[s1r] = s2l;
                    return true;
                }
            }

            return false;
        }

};

class DP : public Solution {
    public:
        virtual bool isScramble(string s1, string s2) {
            int len = s1.size();

            if (s1.size() != s2.size()) return false;
            if (s1 == s2) return true;

            bool T[len][len][len];

            for (int i = 0; i < len; i++)
                for (int j = 0; j < len; j++)
                    T[i][j][0] = s1[i] == s2[j]? true : false;


            for (int k = 1; k < len; k++) {
                for (int i = 0; i < len - k; i++) {
                    for (int j = 0; j < len - k; j++) {
                        T[i][j][k] = false;
                        for (int p = 0; p < k; p++) {
                            if ((T[i][j][p] && T[i+p+1][j+p+1][k-p-1])
                                    || (T[i][j+k-p][p] && T[i+p+1][j][k-p-1])) {
                                T[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }

            return T[0][0][len-1];
        }
};


int main() {

    Recursive r;
    RecursiveWithCache rc;
    DP dp;
    
    Solution *s = &r;
    cout << s->isScramble("great", "rgate") << endl;

    s = &rc;
    cout << s->isScramble("great", "rgate") << endl;

    s = &dp;
    cout << s->isScramble("abcd", "bdac") << endl;

    return 0;
}
