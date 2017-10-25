
#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:

        int reverse(int x) {
            long rx = 0;

            while ( (x / 10) != 0) {
               rx = (rx * 10) + (x % 10);
               x = x / 10;
            }
            rx = (rx * 10) + (x % 10);

            int irx = rx;
            return irx == rx? irx : 0;
        }
};
int main() {
    Solution s;

    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(2147483647) << endl;
    cout << s.reverse(-2147483647) << endl;
    return 0;
}
