#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    void sol() {
        string begStr, endStr;
        int dicSize = 0;
        unordered_set<string> dic;
        cin >> dicSize;
        cin >> begStr >> endStr;
        for (int i = 0; i < dicSize; i++) {
            string temp;
            cin >> temp;
            dic.insert(temp);
        }
        queue<string> q;
        unordered_map<string, int> visited;
        q.push(begStr);
        visited[begStr] = 1;
        while (!q.empty()) {
            string tmp = q.front();
            q.pop();
            int path = visited[tmp];
            for (int i = 0; i < tmp.size(); i++) {
                string newWord = tmp;
                for (char c = 'a'; c <= 'z'; c++) {
                    newWord[i] = c;
                    if (newWord == endStr) {
                        cout << path + 1 << endl;
                    }
                    if (dic.find(newWord) != dic.end() &&
                        visited.find(newWord) == visited.end()) {
                        visited[newWord] = path + 1;
                        q.push(newWord);
                    }
                }
            }
        }
        cout << 0 << endl;
    }
};
int main() { Solution().sol(); }
int
