
// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.

#include <iostream>
using namespace std;

class Solution {
    public:
        /* my first version - accepted, but terrible
        string convert(string s, int n) {
            if (n == 1) return s;
            int size = s.size();
            char T[size][size];
            int i = 0, j = 0;

            for (i = 0; i < size ; i++)
                for (j = 0; j < size; j++)
                    T[i][j] = ' ';

            i = 0; j = 0;
            for (char c : s) {
                T[i][j] = c;
                if (i % (n-1) == 0) {
                    if (j + 1 < n) j++;
                    else  { i++; j--; }
                } else {
                    if (j - 1 < 0) j++;
                    else { i++; j--; }
                }
            }

            int m = i;

            string output;
            for (j = 0; j < n; j++)
                for (i = 0; i <= m; i++)
                    if (T[i][j] != ' ') 
                        output += T[i][j];

            return output;
        }
        */
        string convert(string s, int n) {

            if (n == 1) return s;

            int size = s.size();

            string *rows = new string[n];

            int row = 0, step;
            for (auto c : s) {
                rows[row] += c;
                if (row == 0) step = 1;
                else if (row == n - 1) step = -1;

                row += step;
            }

            string output;
            for (int i = 0; i < n; i++)
                output += rows[i];
            return output;
        }
};

int main() {

    Solution s;

    cout << s.convert("PAYPALISHIRING", 1) << endl;
    cout << s.convert("PAYPALISHIRING", 2) << endl;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("PAYPALISHIRING", 5) << endl;
    cout << s.convert("A", 2) << endl;
    return 0;
}
