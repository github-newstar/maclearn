#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int v, e;
    int v1, v2, val;
    struct Edge {
        int s, d, val;
    };
    vector<int> father;
    void init() {
        for (int i = 1; i < father.size(); ++i) father[i] = i;
    }
    int find(int i) { return father[i] == i ? i : father[i] = find(father[i]); }
    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    void sol() {
        vector<Edge> edges;
        cin >> v >> e;
        while (e--) {
            cin >> v1 >> v2 >> val;
            edges.push_back({v1, v2, val});
        }
        father = vector<int>(v + 1, 0);
        init();
        sort(edges.begin(), edges.end(),
             [](const Edge &e1, const Edge &e2) { return e1.val < e2.val; });
        int ans = 0;
        for (const Edge &i : edges) {
            int s = i.s;
            int d = i.d;
            if (isSame(s, d)) return;
            join(s, d);
            ans += i.val;
        }
        cout << ans << endl;
    }
};
int main() { Solution().sol(); }
