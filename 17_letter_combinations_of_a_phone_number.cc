#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
    public:

        map<char, string> phone;
        Solution() {
            phone['0'] = "";
            phone['1'] = "";
            phone['2'] = "abc";
            phone['3'] = "def";
            phone['4'] = "ghi";
            phone['5'] = "jkl";
            phone['6'] = "mno";
            phone['7'] = "pqrs";
            phone['8'] = "tuv";
            phone['9'] = "wxyz";
        }

        vector<string> letterCombinations(string digits) {
            // make sure there's no 0 or 1 in digits
            auto it = digits.begin();
            while (it != digits.end()) {
                if (*it == '0' || *it == '1')
                    it = digits.erase(it);
                if (it == digits.end()) break;
                it++;
            }

            return letterCombinations2(digits);
        }

        vector<string> letterCombinations2(string digits) {
            vector<string> combs;
            if (digits.size() == 1) {
                for(char letter : phone[digits[0]])
                    combs.push_back(string(1, letter));
            } else if (digits.size() == 2) {

                string first_str = phone[digits[0]];
                string second_str = phone[digits[1]];
                for (int i = 0; i < first_str.size(); i++) {
                    for (int j = 0; j < second_str.size(); j++) {
                        combs.push_back(
                                string(1, first_str[i])
                                + string(1, second_str[j]));
                    }
                }
            } else { // digits.size() > 2

                string letters = phone[digits[0]];
                for (char letter : letters) {
                    string tmp(digits);
                    tmp.erase(tmp.begin());
                    vector<string> cmbs =
                        letterCombinations2(tmp);
                    for (string str : cmbs)
                        combs.push_back(string(1, letter) + str);
                }

            }


            return combs;
        }
        vector<string> letterCombinations3(string digits) {
            string phone[] = { "0", "1", "abc", "def", "ghi", "jkl", "mno",
                "pqrs", "tuv", "wxyz" };
            vector<string> combinations;

            if (digits.size() == 0) return combinations; 

            combinations.push_back("");
            for (char number : digits) {
                vector<string> temp;
                for (string str : combinations)
                    for (char letter : phone[number-'0'])
                        temp.push_back(str + letter);
                combinations = temp;
            }
            return combinations;
        }

};

int main() {

    Solution s;
    for (string comb : s.letterCombinations3("023")) {
        cout << comb << endl;
    }
    return 0;
}
