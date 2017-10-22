#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int D(const string& R, const string& S, int i, int j) {
            //cout << "i: " << i << ", j: " << j << endl;
            if (i == -1 && j == -1) { 
                //cout << "return 0" << endl;
                return 0; 
            }
            if (i != -1 && j == -1) {
                //cout << "return " << i + 1 << endl;
                return i + 1; 
            }
            if (i == -1 && j != -1) {
                //cout << "return " << j + 1 << endl;
                return j + 1; 
            }

            int d1 = D(R, S, i - 1, j) + 1;
            int d2 = D(R, S, i, j - 1) + 1;
            int d3 = D(R, S, i - 1, j - 1) + (R[i] == S[j]? 0 : 1);
            int d = d1 < d2 ? d1 : d2;
            d = d  < d3 ? d  : d3;

            //cout << "return " << d << endl;
            return d;
        }

        int minDistance(string R, string S) {
            //cout << R << " to " << S << endl;
            int n = R.size();
            int m = S.size();
            //cout << "n: " << n << ", m: " << m << endl;
            int D[n + 1][m + 1];

            for (int i = 0; i < n + 1; i++) D[i][0] = i;
            for (int j = 0; j < m + 1; j++) D[0][j] = j;

            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < m + 1; j++) {
                    //cout << "i: " << i << ", j: " << j << endl;
                    int d1 = D[i-1][j] + 1;
                    int d2 = D[i][j-1] + 1;
                    int d3 = D[i-1][j-1] + (R[i-1] == S[j-1] ? 0 : 1);

                    int d = d1 < d2 ? d1 : d2;
                    d = d  < d3 ? d  : d3;
                    //cout << "d : " << d << endl;
                    D[i][j] = d;
                }
            }
            return D[n][m];
        }
};

int main() {
    Solution s;
    cout << s.minDistance("", "") << endl; // 0
    cout << s.minDistance("horse", "ros") << endl; // 3
    cout << s.minDistance("sea", "ate") << endl;  // 3
    cout << s.minDistance("plasma", "altruism") << endl;  // 6
    cout << s.minDistance("mart", "karma") << endl;  // 3
    cout << s.minDistance("dustry", "terest") << endl;  // 6
    cout << s.minDistance("kindustry", "linterest") << endl;  // 7
    cout << s.minDistance("", "a") << endl;  // 1
    cout << s.minDistance("a", "b") << endl;  // 1
    cout << s.minDistance("dinitrophenylhydrazine", "denzalphenylhydrazone") << endl;  // 7, but 8
    return 0;
}
