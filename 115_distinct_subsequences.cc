#include <iostream>
using namespace std;

class Solution
{
    public:
        int numDistinct(string s, string t)
        {
            int nrows = t.size() + 1;
            int ncols = s.size() + 1;
            int D[nrows][ncols];

            for (int col = 0; col < ncols; col++)
                D[0][col] = 1;

            for (int row = 1; row < nrows; row++)
                D[row][0] = 0;

            for (int row = 1; row < nrows; row++) {
                for (int col = 1; col < ncols; col++) {
                    D[row][col] = D[row][col-1];
                    if (s[col-1] == t[row-1])
                        D[row][col] += D[row-1][col-1];
                }
            }

            return D[nrows-1][ncols-1];
        }
};


int main()
{
    Solution s;
    cout << s.numDistinct("b", "") << endl;  // 1
    cout << s.numDistinct("ab", "") << endl; // 1
    cout << s.numDistinct("", "a") << endl;  // 0
    cout << s.numDistinct("", "ab") << endl; // 0
    cout << s.numDistinct("", "") << endl;   // 1
    cout << s.numDistinct("acdabefbc", "ab") << endl;
    cout << s.numDistinct("rabbbit", "rabbit") << endl;

    return 0;
}
