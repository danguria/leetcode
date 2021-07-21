#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
// 1way BFS + findNextWord1 = 621 ms
// 1way BFS + findNextWord2 = 89 ms
// 2way BFS + findNetWord = 38 ms
class Solution
{
    public:

        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
        {
            unordered_set<string> wordDict(wordList.begin(), wordList.end());
            unordered_map<string, vector<string>> nodeNeighbors;
            unordered_map<string, int> distance;
            bfs(beginWord, endWord, wordDict, nodeNeighbors, distance);

            vector<string> curPath;
            vector<vector<string>> paths;
            dfs(beginWord, endWord, nodeNeighbors, distance, curPath, paths);
            
            return paths;
        }

        void bfs(string beginWord, string endWord, unordered_set<string>& wordDict,
                unordered_map<string, vector<string>>& nodeNeighbors,
                unordered_map<string, int>& distance)
        {
            queue<string> toVisit;
            toVisit.push(beginWord);
            distance[beginWord] = 0;

            while (!toVisit.empty()) {
                bool reach = false;
                int n = toVisit.size();
                for (int i = 0; i < n; i++) {
                    string curWord = toVisit.front();
                    toVisit.pop();
                    vector<string> neighbors;
                    getNeighbors(curWord, wordDict, neighbors);
                    nodeNeighbors[curWord] = neighbors;
                    for (string n : neighbors) {
                        if (distance.find(n) == distance.end()) {
                            distance[n] = distance[curWord] + 1;
                            if (endWord == n) reach = true;
                            else toVisit.push(n);
                        }
                    }

                }
                if (reach) break;
            }
        }

        void dfs(string curWord, string endWord,
                unordered_map<string, vector<string>>& nodeNeighbors, unordered_map<string, int>& distance,
                vector<string>& curPath, vector<vector<string>>& paths)
        {
            curPath.push_back(curWord);
            if (curWord == endWord) {
                paths.push_back(curPath);
            } else {
                for (string n : nodeNeighbors[curWord]) {
                    if (distance[n] == distance[curWord] + 1)
                        dfs(n, endWord, nodeNeighbors, distance, curPath, paths);
                }
            }

            curPath.pop_back();
        }

        void getNeighbors(string word, unordered_set<string>& wordDict,  vector<string>& neighbors)
        {
            string orgWord = word;
            for (int p = 0; p < (int)word.length(); p++) {
                char letter = word[p];
                for (int k = 0; k < 26; k++) {
                    word[p] = 'a' + k;
                    if (wordDict.find(word) != wordDict.end())
                        neighbors.push_back(word);
                }
                word[p] = letter;
            }
        }
};

int main() {

    Solution s;

    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    vector<vector<string>> ans = s.findLadders("hit", "cog", wordList);

    for (auto words : ans)
        for (auto w : words)
            cout << w << ", ";
    cout << endl;

    return 0;
}
