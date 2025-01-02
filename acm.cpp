#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int v, e;
    void sol() {
        cin >> v >> e;
        vector<vector<int>> grid(v + 1, vector<int>(v + 1, 1e5 + 1));
        vector<int> minDist(v + 1, 1e5 + 1);
        vector<bool> inMap(v + 1, false);
        int s, t, val;
        for (int i = 0; i < e; ++i) {
            cin >> s >> t >> val;
            grid[s][t] = val;
            grid[t][s] = val;
        }
        for (int i = 1; i < v; ++i) {
            int cur = -1;
            int minDes = INT_MAX;
            for (int j = 1; i <= v; ++j) {
                if (!inMap[j] && minDes > minDist[j]) {
                    cur = j;
                    minDes = minDist[j];
                }
            }
            inMap[cur] = true;
            for (int j = 1; j <= v; ++j) {
                if (!inMap[j] && grid[cur][j] < minDist[j]) {
                    minDist[j] = grid[cur][j];
                }
            }
        }
        int result = 0;
        for (int i = 2; i <= v; ++i) {
            result += minDist[i];
        }
        cout << result << endl;
    }
};
int main() { Solution().sol(); }
