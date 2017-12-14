#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;
class Position {
    public:
        Position(int x, int y, int z) { idx_s3 = x; idx_s1 = y; idx_s2 = z; }
        int idx_s3, idx_s1, idx_s2;
        bool operator==(const Position& b) const {
            return idx_s3 == b.idx_s3
                && idx_s1 == b.idx_s1
                && idx_s2 == b.idx_s2;
        }
};

namespace std {
    template <>
    struct hash<Position> {
        size_t operator () (const Position &f) const {
            return (std::hash<int>()(f.idx_s3) << 2)
                ^ (std::hash<int>()(f.idx_s1) << 1)
                ^ std::hash<int>()(f.idx_s2);
        }
    };
}

class Solution {

    public:
        bool isInterleave(const string s1, const string s2, const string s3) {

            if (s3.size() != (s1.size() + s2.size())) return false;

            Position target(s3.size(), s1.size(), s2.size());
            Position cur(0, 0, 0);

            unordered_set<Position> visited;
            stack<Position> s;
            s.push(cur);
            visited.insert(cur);

            while (!s.empty()) {
                cur = s.top();
                s.pop();
                
                if (cur == target) return true;

                if (cur.idx_s1 < s1.size() && s1[cur.idx_s1] == s3[cur.idx_s3]) {
                    Position p(cur.idx_s3 + 1, cur.idx_s1 + 1, cur.idx_s2);
                    if (visited.find(p) == visited.end()) {
                        s.push(p);
                        visited.insert(p);
                    }
                } 
                
                if (cur.idx_s2 < s2.size() && s2[cur.idx_s2] == s3[cur.idx_s3]) {
                    Position p(cur.idx_s3 + 1, cur.idx_s1, cur.idx_s2 + 1);
                    if (visited.find(p) == visited.end()) {
                        s.push(p);
                        visited.insert(p);
                    }
                }
            }

            return false;
        }
};
int main() {
    Solution s;

    //cout << s.isInterleave("dbbca", "aabcc", "aadbbcbcac") << endl;
    //cout << s.isInterleave("dbbca", "aabcc", "aadbbbaccc") << endl;
    //cout << s.isInterleave("aa", "ab", "aaba") << endl;


    cout << s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
            "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
            "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;




    return 0;
}
