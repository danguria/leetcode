#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
using namespace std;
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


vector<string> split(const string &s, regex rgx) {
    vector<string> tokens;

    sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    sregex_token_iterator end;
    for ( ; iter != end; ++iter)
        tokens.push_back(*iter);

    return tokens;
}

int numWords(const string line) {
    return split(line, regex("\\s+")).size();
}

string getExtraSpace(int n) {
    string s;
    for (int i = 0; i < n; i++) s += ' ';
    return s;
}

string addExtraSpace(const string line, string extraSpace, int num) {
    size_t pos = 0;

    string result = line;
    vector<string> tokens = split(result, regex("\\s+"));
    for (int i = 0; i < num; i++) {
        pos = result.find(tokens[i], pos);
        if (pos != string::npos) {
            pos += tokens[i].size();
            result.insert(pos, extraSpace);
        } else {
            cerr << "failed to add Extra space" << endl;
            return string("");
        }
    }

    return result;
}


string fullJustify(const string line, const int maxWidth) {
    string result;
    int numSpace = numWords(line) - 1;
    int remain = maxWidth - line.size();

    if (numSpace != 0) {
        result = addExtraSpace(line, getExtraSpace(remain/numSpace), numSpace);
        result = addExtraSpace(result, " ", remain%numSpace);
    } else if (numSpace == 0 && maxWidth > 0) {
        result = addExtraSpace(line, getExtraSpace(remain), 1);
    } else {
        result = line;
    }

    return result;
}

string leftJustify(const string line, const int maxWidth) {
    int remain = maxWidth - line.size();
    string result = line;
    for (int i = 0; i < remain; i++) 
        result += ' ';
    return result;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {

    vector<string> result;
    string newLine;
    bool remain = false;
    for (string w : words) {
        int size = newLine.size() + w.size();

        if (size == maxWidth) {
            newLine += w;
            newLine = fullJustify(trim(newLine), maxWidth);
            result.push_back(newLine);
            newLine.clear();
            remain = false;
        } else if (size > maxWidth) {
            newLine = fullJustify(trim(newLine), maxWidth);
            result.push_back(newLine);
            newLine.clear();

            if (w.size() < maxWidth)
                newLine += w + " ";
            else if (w.size() == maxWidth)
                newLine += w;
            else {/* never happens */}
            remain = true;
        } else {// size < maxWidth
            newLine += w + " ";
            remain = true;
        }
    }
    if (!newLine.empty() || remain) {
        newLine = leftJustify(newLine, maxWidth);
        result.push_back(newLine);
    }
    return result;
}

int main() {

    int maxWidth;
    vector<string> words;

    words.push_back("Here");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification.");
    maxWidth = 14;

    for (string str : fullJustify(words, maxWidth)) {
        cout << str << endl;
    }
    return 0;
}
