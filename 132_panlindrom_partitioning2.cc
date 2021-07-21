#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        unordered_map<string, int> map;
        int minCut(string s)
        {
            auto it = map.find(s);
            if (it != map.end()) {
                return it->second;
            } else if (isPalindrome(s)) {
                map[s] = 0;
                return 0;
            }

            int min = INT_MAX;
            int size = s.size();
            for (int i = 0; i < size - 1; i++) {
                string l = s.substr(0, i + 1);
                string r = s.substr(i + 1, size - (i + 1));
                cout << "l : " << l << endl;
                cout << "r : " << r << endl;

                int ml, mr;
                auto it = map.find(l);
                if (it != map.end()) {
                    ml = it->second;
                } else {
                    ml = minCut(l);
                    map[l] = ml;
                }

                it = map.find(r);
                if (it != map.end()) {
                    mr = it->second;
                } else {
                    mr = minCut(r);
                    map[r] = mr;
                }
                cout << "minCut(" + l << ") = " << ml << endl;
                cout << "minCut(" + r << ") = " << mr << endl;
                //int cut = minCut(s.substr(0, i + 1)) + minCut(s.substr(i + 1, size - (i + 1))) + 1;
                int cut = ml + mr + 1;
                if (cut < min) min = cut;
            }

            return min;
        }


        bool isPalindrome(string s)
        {
            int begin = 0;
            int end = s.size() - 1;
            
            while (begin < end) {
                if (s[begin] != s[end]) return false;
                begin++;
                end--;
            }

            return true;
        }
};

int main(int argc, char** argv)
{
    if (argc != 2) {
        cerr << "usage : " << argv[0] << " [string]" << endl;
        return 0;
    }
    Solution s;
    int min = s.minCut(argv[1]);
    cout << "minCu(" << argv[1] << ") = " << min << endl;
    return 0;
}
