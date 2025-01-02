
#include <algorithm>
#include <atomic>
#include <climits>
#include <cstdarg>
#include <ctime>
#include <functional>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <system_error>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class MyCalendar {
    set<pair<int, int>> s;
    MyCalendar() {}
    bool book(int startTime, int endTime) {
        auto it = s.lower_bound({endTime, 0});
        if (it == s.begin() || (--it)->second <= startTime) {
            s.emplace(startTime, endTime);
            return true;
        }
        return false;
    }
};
class Solution {
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return root;
        if (root->val < low) {
            root->right = trimBST(root->right, low, high);
            return root->right;
        }
        if (root->val > high) {
            root->left = trimBST(root->left, low, high);
            return root->left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
