#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
// 1way BFS + findNextWord1 = 621 ms
// 1way BFS + findNextWord2 = 89 ms
// 2way BFS + findNetWord = 38 ms
class Solution
{
    public:

        int ladderLength(string beginWord, string endWord, vector<string>& wordList)
        {
            unordered_set<string> wordDict(wordList.begin(), wordList.end());
            return ladderLength2(beginWord, endWord, wordDict);
        }

        int ladderLength2(string beginWord, string endWord, unordered_set<string>& wordDict)
        {
            unordered_set<string> head, tail, *phead, *ptail;

            head.insert(beginWord);
            tail.insert(endWord);
            if (wordDict.find(endWord) != wordDict.end()) {
                wordDict.erase(beginWord);
                wordDict.erase(endWord);
            } else {
                return 0;
            }
            int distance = 2;

            while (!head.empty() && !tail.empty()) {
                if (head.size() < tail.size()) {
                    phead = &head;
                    ptail = &tail;
                } else {
                    phead = &tail;
                    ptail = &head;
                }

                unordered_set<string> tmp;
                auto it = phead->begin();
                while (it != phead->end()) {
                    string word = *it;
                    wordDict.erase(word);
                    for (int p = 0; p < (int)word.length(); p++) {
                        char letter = word[p];
                        for (int k = 0; k < 26; k++) {
                            word[p] = 'a' + k;
                            if (ptail->find(word) != ptail->end()) return distance;
                            if (wordDict.find(word) != wordDict.end()) {
                                tmp.insert(word);
                                wordDict.erase(word);
                            }
                        }
                        word[p] = letter;
                    }
                    it++;
                }
                distance++;
                swap(*phead, tmp);
            }
            return 0;
        }


        int ladderLength1(string beginWord, string endWord, unordered_set<string>& wordDict)
        {
            queue<string> toVisit;
            findNextWords2(beginWord, wordDict, toVisit);
            //findNextWords1(beginWord, wordDict, toVisit);
            int distance = 2;

            while (!toVisit.empty()) {
                int n = toVisit.size();
                for (int i = 0; i < n; i++) {
                    string word = toVisit.front();
                    toVisit.pop();
                    if (word == endWord) return distance;
                    findNextWords2(word, wordDict, toVisit);
                    //findNextWords1(word, wordDict, toVisit);
                }
                distance++;
            }
            return 0;
        }

        void findNextWords2(string word, unordered_set<string>& wordDict, queue<string>& toVisit)
        {
            wordDict.erase(word);
            for (int p = 0; p < (int)word.length(); p++) {
                char letter = word[p];
                for (int k = 0; k < 26; k++) {
                    word[p] = 'a' + k;
                    if (wordDict.find(word) != wordDict.end()) {
                        toVisit.push(word);
                        wordDict.erase(word);
                    }
                }
                word[p] = letter;
            }
        }

        void findNextWords1(string word, unordered_set<string>& wordDict, queue<string>& toVisit)
        {
            wordDict.erase(word);

            auto it = wordDict.begin();
            while (it != wordDict.end()) {
                if (isConnected(word, *it)) {
                    toVisit.push(*it);
                    it = wordDict.erase(it);
                } else {
                    it++;
                }
            }
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

    vector<string> wordList = { "hot", "dot", "dog", "lot", "log" };
    cout << s.ladderLength("hit", "cog", wordList) << endl;

    return 0;
}
