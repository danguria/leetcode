#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
    public:
        virtual int minMutation(string start, string end, vector<string>& bank) = 0;
};
class Recursive : public Solution {
    public:
        int minMutation(string start, string end, vector<string>& bank, vector<string> path) {
            if (start == end) return path.size() - 1;

            int min = INT_MAX;
            for (string new_string : bank) {
                int similarity = 0;
                for (int j = 0; j < start.size(); j++)
                    if (start[j] != seq[j]) similarity++;

                if (similarity == 1) {
                    int already_in_path = false;
                    for (auto p : path) if (p == seq) already_in_path = true;

                    if (!already_in_path) {
                        path.push_back(seq);
                        int cnt = minMutation(seq, end, bank, path);
                        if (cnt != -1 && cnt < min) min = cnt;
                        path.pop_back();
                    }
                }
            }

            if (min == INT_MAX) return -1;
            return min;
        }

        virtual int minMutation(string start, string end, vector<string>& bank) {
            vector<string> path;
            path.push_back(start);
            return minMutation(start, end, bank, path);
        }
};

class BFS_QUEUE : public Solution {
        virtual int minMutation(string start, string end, vector<string>& bank) {
            queue<string> q; // queue for BFS
            set<string> v; // set of visited seq

            set<string> bset(bank.begin(), bank.end());

            q.push(start);
            v.insert(start);

            int level = 1;
            while(!q.empty()) {
                int size = q.size();
                while (size-- > 0) {
                    string s = q.front();
                    q.pop();

                    //cout << "s: " << s << endl;
                    //cout << "level: " << level << endl;

                    for (int i = 0; i < s.size(); i++) {
                        for (auto c : string("ACTG")) {
                            char old = s[i];
                            s[i] = c;
                            //cout << "check seq: " << s << endl;
                            set<string>::const_iterator visited  = v.find(s);
                            set<string>::const_iterator contains = bset.find(s);

                            if (visited == v.end() && contains != bset.end()) {
                                // if we can move to the sequence
                                // and it has not been visited yet.
                                //cout << "push seq: " << s << endl;
                                if (s == end) return level;
                                v.insert(s);
                                q.push(s);
                            }
                            s[i] = old;
                        }
                    }
                }

                level++;
            }
            return -1;
        }
};

void execute(Solution& s, string start, string end, vector<string>& bank) {
    cout << s.minMutation(start, end, bank) << endl;
}


int main() {
    Recursive r;
    BFS_QUEUE bq;
    string start = "AAAAAAAA";
    string end = "AAAAAATT";

    vector<string> bank = {
        "AAAAAAAA",
        "AAAAAAAT",
        "AAAAAATT",
        "AAAAATTT"};
    execute(r, start, end, bank);
    execute(bq, start, end, bank);

    start = "AACCGGTT";
    end = "AACCGGTA";

    bank = {
        "AACCGGTA"};
    execute(r, start, end, bank);
    execute(bq, start, end, bank);

    start = "AAAAACCC";
    end =   "AACCCCCC";
    bank ={ "AAAACCCC", "AAACCCCC", "AACCCCCC"};
    execute(r, start, end, bank);
    execute(bq, start, end, bank);

    start = "AAAAACCC";
    end =   "AACCCCCT";
    bank ={ "AAAACCCC", "AAACCCCC", "AACCCCCC"};
    execute(r, start, end, bank);
    execute(bq, start, end, bank);


    start = "AACCGGTT";
    end = "AAACGGTA";
    bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    execute(r, start, end, bank);
    execute(bq, start, end, bank);

    start = "AAAACCCC";
    end = "CCCCCCCC";
    bank = {"AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"};
    execute(r, start, end, bank);
    execute(bq, start, end, bank);

    return 0;
}
