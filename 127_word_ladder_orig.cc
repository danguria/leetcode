#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef unordered_map<string, unordered_map<string, unsigned long long int>> Matrix;
typedef unordered_map<string, unordered_map<string, bool>> Path;
typedef unordered_set<string> FoundSet;

// Time Complexit = n^2 (n = sizeof wordList)
class Solution {
    public:

        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            if (beginWord == endWord)  return 1;

            bool needInsert = true;
            for (string w : wordList) 
                if (w == beginWord) needInsert = false;
            if (needInsert) wordList.insert(wordList.begin(), beginWord);
            Matrix matrix = initMatrix(wordList);
            FoundSet foundSet;
            foundSet.insert(beginWord);
           
            while(foundSet.size() < wordList.size()) {
                string newFound = getShortest(beginWord, matrix, foundSet);
                
                if (newFound == endWord) {
                    break;
                }
                foundSet.insert(newFound);

                for (string next : wordList) {
                    if (foundSet.find(next) == foundSet.end()
                            && matrix[beginWord][newFound] + matrix[newFound][next] <= matrix[beginWord][next]) {
                        matrix[beginWord][next] = matrix[beginWord][newFound] + matrix[newFound][next];
                    }
                }
            }

            printMatrix(matrix, wordList);

            if (matrix[beginWord][endWord] == 0) return 0;
            return matrix[beginWord][endWord] + 1;
        }

        string getShortest(string beginWord, Matrix& matrix, FoundSet& foundSet) {
            string newFound;
            unsigned long long int min = INT_MAX;
            for (auto pair : matrix) {
                string node = pair.first;
                if (foundSet.find(node) != foundSet.end()) continue;
                if (matrix[beginWord][node] < min) {
                    min = matrix[beginWord][node];
                    newFound = node;
                }
            }
            return newFound;
        }

        void printMatrix(Matrix& m, const vector<string>& wordList) {
            for ( string r : wordList)
                cout << std::setw(16) << r;
            cout << endl;

            for ( string r : wordList) {
                cout << std::setw(5) << r;
                for (string c : wordList) {
                    cout << std::setw(15) << m[r][c] << " ";
                }
                cout << endl;
            }
        }
        
        Matrix initMatrix(const vector<string>& wordList) {
            Matrix m;

            for (string r : wordList) {
                for (string c : wordList) {
                    if (isConnected(r, c))
                        m[r][c] = 1;
                    else
                        m[r][c] = INT_MAX;
                }
            }
            return m;
        }
        
        bool isConnected(string s1, string s2) {
            int cnt = 0;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) {
                    cnt++;
                    if (cnt > 2 ) break;
                }
            }

            if (cnt == 1) return true;
            return false;
        }
};

int main() {

    Solution s;

    //vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log" };
    cout <<s.ladderLength("hit", "cog", wordList) << endl;

    return 0;
}
