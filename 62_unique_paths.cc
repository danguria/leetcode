#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n) {

            if (m < 1 || m < 1) return 0;
            if (m == 1 || n == 1) return 1;
            if (m < n) uniquePaths(n, m); // make it create smaller vector

            vector<int> prev(n, 1); // previous row
            vector<int> curr(n, 1); // current row

            for (int i = m - 2; i >= 0; i--) {
                for (int j = n - 2; j >= 0; j--) {
                    curr[j] = curr[j+1] + prev[j]; // right + down
                }
                swap(curr, prev);
            }
            return prev[0];
        }
};

int main() {
    Solution s;

    cout << s.uniquePaths(2, 2) << endl;
    cout << s.uniquePaths(2, 3) << endl;
    cout << s.uniquePaths(1, 10) << endl;
    return 0;
}
