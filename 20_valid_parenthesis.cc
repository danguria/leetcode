#include <iostream>
#include <stack>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> stack;
            for (auto c : s) {
                switch (c) {
                    case '(':
                    case '{':
                    case '[':
                        stack.push(c);
                        break;
                    case ')':
                        if (stack.empty() || stack.top() != '(')
                            return false;
                        stack.pop();
                        break;
                    case '}':
                        if (stack.empty() || stack.top() != '{')
                            return false;
                        stack.pop();
                        break;
                    case ']':
                        if (stack.empty() || stack.top() != '[')
                            return false;
                        stack.pop();
                        break;
                    default:;
                        // do nothing
                }
            }

            return stack.empty();
        }
        bool isValid1(string s) {

            stack<char> stack;
            for (auto c : s) {
                if (c == '(' || c == '{' || c == '[') {
                    stack.push(c);
                } else if (c == ')' || c == '}' || c == ']') {
                    if (stack.empty()) {
                        return false;
                    } else {
                        char pair = stack.top();
                        stack.pop();
                        if (!((c == ')' && pair == '(')
                                || (c == '}' && pair == '{') 
                                || (c == ']' && pair == '['))) 
                            return false;
                    }
                }
            }

            if (stack.empty()) 
                return true;
            return false;
        }

};
int main() {

    Solution s;
    cout << s.isValid("hi(there) [({I'm sung})] {keun}") << endl;

    return 0;
}
