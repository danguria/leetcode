#include <iostream>
using namespace std;

class Solution {
    public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x%10 == 0)) return 0;

        int rev = 0;
        while (rev < x) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        return x == rev || x == (rev / 10);
    }
};

int main() {

    Solution s;
    cout << s.isPalindrome(1221) << endl;
    cout << s.isPalindrome(12321) << endl;
    cout << s.isPalindrome(234) << endl;
    cout << s.isPalindrome(0) << endl;
    cout << s.isPalindrome(123123) << endl;
    cout << s.isPalindrome(10) << endl;
    return 0;
}
