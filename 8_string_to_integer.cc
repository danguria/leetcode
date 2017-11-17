#include <iostream>
using namespace std;

class Solution {
    public:
        /* my stupid version
           int myAtoi(string str) {

           if (str.size() == 0) return 0;

           str = trim(str);

           string::reverse_iterator rit = str.rbegin();

           int num = 0, base = 1, sign = 1, end;
           if (str[0] == '-') {
           sign = -1;
           end = -1;
           } else if (str[0] == '+') {
           sign = 1;
           end = -1;
           } else {
           sign = 1;
           end = 0;
           }

           for (; rit != str.rend() + end; rit++) {
           int d = *rit - '0';
           cout << "check: " << d << "(" << *rit << ")" << endl;
           if (d < 0 || d > 9) {
           num = 0;
           base = 1;
           continue;
           }
           num = num + (d * base);
           if (sign == 1 && num < 0) return 2147483647;
           if (sign == -1 && sign * num > 0) return -2147483648;
           base *= 10;
           }
           return num * sign;
           }
           */

        string trim(const string& str) {
            const string pattern = " \f\n\r\t\v";

            string tmp = str.substr(str.find_first_not_of(pattern));
            return tmp.substr(0, tmp.find_last_not_of(pattern) + 1);
        }

        int myAtoi(string str) {

            if (str.empty()) return 0;

            str = trim(str);

            int i = 0, num = 0, sign = 1;
            if (str[i] == '-') {
                sign = -1; i++;
            } else if (str[i] == '+') {
                sign = 1; i++;
            }

            while (str[i] >= '0' && str[i] <= '9') {
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                num = num * 10 + str[i++] - '0';
            }

            return num * sign;
        }

};

int main() {
    Solution s;
    cout << s.myAtoi("-123") << endl; // -123
    cout << s.myAtoi("+123") << endl; // 123
    cout << s.myAtoi("123") << endl; // 123
    cout << s.myAtoi(" 123 ") << endl; // 123
    cout << s.myAtoi("1,2") << endl; // 1
    cout << s.myAtoi("+-12") << endl; // 0
    cout << s.myAtoi("1.2") << endl; // 1
    cout << s.myAtoi("") << endl; // 0
    cout << s.myAtoi("2147483648") << endl; // 2147483647
    cout << s.myAtoi("  +b12102370352") << endl; // 0
    cout << s.myAtoi("-1") << endl; // -1
    return 0;
}

