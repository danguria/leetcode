#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <map>
using namespace std;


class Solution {
    private:
        string trim(const string& str) {
            size_t first = str.find_first_not_of(' ');
            if (string::npos == first)
            {
                return str;
            }
            size_t last = str.find_last_not_of(' ');
            return str.substr(first, (last - first + 1));
        }

        bool checkAnswer(bool anser, bool expected) { return expected == anser; }

    public:
        bool wordPattern(string pattern, string str) {
            bool ret = true;

            regex ws_re("\\s+");
            vector<string> vstr{
                sregex_token_iterator(str.begin(), str.end(), ws_re, -1), {}
            };

            if (pattern.size() != vstr.size()) return false;

            auto o_sit = vstr.begin();
            auto o_pit = pattern.begin();
            for (; o_sit < vstr.end(); o_sit++, o_pit++) {
                auto i_sit = o_sit + 1;
                auto i_pit = o_pit + 1;
                for (; i_sit < vstr.end(); i_sit++, i_pit++) {

                    if ((*o_pit == *i_pit && *o_sit != *i_sit)
                            || (*o_pit != *i_pit && *o_sit == *i_sit)) {
                        ret = false;
                    }
                }
            }
            return ret;
        }
};


int main() {

    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;
    cout << s.wordPattern("jquery", "jquery") << endl;

}
