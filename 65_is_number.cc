#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <map>
using namespace std;
class Solution {

    public:
        string trim(const string& str) {
            size_t first = str.find_first_not_of(' ');
            if (string::npos == first)
            {
                return str;
            }
            size_t last = str.find_last_not_of(' ');
            return str.substr(first, (last - first + 1));
        }
        bool isNumber(string s) {

            vector<regex> patterns;
            s = trim(s);

            patterns.push_back(regex("(\\+|-)?([1-9][[:digit:]]+)?(\\.[[:digit:]]+)?")); // decimal
            patterns.push_back(regex("(\\+|-)?(0x|0X)[[1-9][:digit:]a-fA-F]+(\\.[[:digit:]a-fA-F]+)?"));  // hexa with prefix
            patterns.push_back(regex("(\\+|-)?[[1-9][:digit:]]+[[:digit:]a-fA-F]+(\\.[[:digit:]a-fA-F]+)?"));  // hexa without prefix
            for (regex p : patterns)
                if (regex_match(s, p)) return true;

            return false;
        }
};

int main() {
    Solution s;

    cout << s.isNumber("   +123")  << " : true"     << endl;
    cout << s.isNumber("+123   ")  << " : true"     << endl;
    cout << s.isNumber("+1 23   ") << " : false"    << endl;
    cout << s.isNumber(".1")       << " : true"     << endl;
    cout << s.isNumber("-0.123")   << " : true"     << endl;
    cout << s.isNumber("-.123")    << " : true" << endl;
    cout << s.isNumber("0xabc")    << " : true" << endl;
    cout << s.isNumber("abc.def")  << " : false" << endl;
    cout << s.isNumber("d")        << " : false" << endl;
    cout << s.isNumber("0e")        << " : false" << endl;


    return 0;
}

