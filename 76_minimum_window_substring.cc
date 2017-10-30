#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {

            vector<int> map(128, 0);
            int count = t.size();
            int d = INT_MAX;

            for (auto c : t) map[c]++;

            int begin, end, head;
            begin = end = head = 0;
            while (end < s.size()) {
                if (map[s[end++]]-- > 0) count--;

                while (count == 0) {
                    if (end - begin < d) d = end - (head = begin);
                    if (map[s[begin++]]++ == 0) count++;
                }
            }

            return d == INT_MAX? "" : s.substr(head, d);
        }

        int lengthOfLongestSubstring(string s) {
            vector<int> map(128,0);
            int counter=0, begin=0, end=0, d=0; 
            while(end<s.size()){
                if(map[s[end++]]++>0) counter++; 
                while(counter>0) if(map[s[begin++]]-->1) counter--;
                d=max(d, end-begin); //while valid, update d
            }
            return d;
        }
};


int main() {

    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.lengthOfLongestSubstring("ADOBECODEBANC") << endl;
    return 0;
}
