#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
    public:
        virtual int lengthOfLongestSubstring(string) = 0;
};

/*
 * Time Complexity  : O(n^3)
 * Space Complexity : O(min(n, m)) where m is the charactershet in string
 */
class BruteForce : public Solution {
    public:
        bool allUnique(string str, int s, int e) {

            set<char> _set;

            for (int i = s; i < e; i++) {
                if (_set.find(str[i]) != _set.end())
                    return false;
                _set.insert(str[i]);
            }
            return true;
        }
        virtual int lengthOfLongestSubstring(string s) {

            int size = s.size();
            int max = 0;
            for (int i = 0; i < size; i++) {
                for (int j = i + 1; j <= size; j++) {
                    if (allUnique(s, i, j)) {
                        max = std::max(max, j - i);
                    }
                }
            }

            return max;

        }
};

/*
 * Time Complexity  : O(2n)
 * Space Complexity : O(min(n, m))
 */
class SlideWindowWithSet : public Solution
{
        virtual int lengthOfLongestSubstring(string s) {
            int max = 0;

            int head = 0, tail = 0;
            int size = s.size();

            set<char> w;
            while (head < size && tail < size) {
                if (w.find(s.at(tail)) == w.end()) {
                    // a key doesn't contains a speficied key
                    w.insert(s.at(tail++));
                    max =  max > (tail - head) ? max : tail - head;
                } else {
                    w.erase(w.find(s.at(head++)));
                }
            }
            return max;
        }
};

/*
 * Time Complexity  : O(n)
 * Space Complexity : O(min(n, m))
 */
class SlideWindowWithMap : public Solution
{
    virtual int lengthOfLongestSubstring(string s) {

        int size = s.size();
        int max = 0;
        int head = 0, tail = 0;

        unordered_map<char, int> w;

        for (; tail < size; tail++) {
            if (w.find(s[tail]) != w.end()) {
                head = w[s[tail]] + 1 > head? w[s[tail]] + 1: head;
                w[s[tail]] = tail;
            } else {
                w[s[tail]] = tail;
            }
            max =  max > (tail - head + 1) ? max : (tail - head + 1);
        }
        return max;
    }
};

void execute(Solution& s) {
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;
    cout << s.lengthOfLongestSubstring("tmmzuxt") << endl;
}

int main() {
    BruteForce bf;
    SlideWindowWithSet s;
    SlideWindowWithMap m;
    execute(bf);
    execute(s);
    execute(m);
    return 0;
}
