#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        void generate_parenthesis(vector<string>& p, string paren, int m, int no, int nc)
        {
            if (no <= 0 && nc <= 0) {
                p.push_back(paren);
                return;
            }

            if (m > 0) {
                if (no > 0) {
                    generate_parenthesis(p, paren + ")", m - 1, no, nc - 1);
                    generate_parenthesis(p, paren + "(", m + 1, no - 1, nc);
                } else { // no <= 0 && nc > 0
                    generate_parenthesis(p, paren + ")", m + 1, no, nc - 1);
                }
            } else { // m == 0
                generate_parenthesis(p, paren + "(", m + 1, no - 1, nc);
            }
        }

        vector<string> generateParenthesis(int n) {
            if (n < 1) return vector<string>();

            vector<string> p;
            generate_parenthesis(p, "", 0, n, n);
            return p;
        }
};

int main()
{

    Solution s;
    for (int i = 1; i <= 5; i++) {
        vector<string> answer = s.generateParenthesis(i);
        cout << "i = " << i << endl;
        for (string s : answer) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
