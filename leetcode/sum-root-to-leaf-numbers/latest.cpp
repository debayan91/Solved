/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        stack<pair<TreeNode*, string>> stack;
        stack.push({root, ""});
        while(!stack.empty()){
            TreeNode* temp = stack.top().first;
            if(!temp->right && !temp->left){
                // if leaf node
                stack.top().second += to_string(temp->val);
                sum += stoi(stack.top().second);
            }
            else{
                // if not leaf node
                stack.top().second += to_string(temp->val);
            }
            string s = stack.top().second;
            stack.pop();
            if(temp->left) stack.push({temp->left, s});
            if(temp->right) stack.push({temp->right, s});
        }
        return sum;
    }
};

#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
static const size_t ARENA_SIZE = 1 << 26; 
alignas(max_align_t) static unsigned char arena[ARENA_SIZE];
static size_t arena_pos = 0;

void* operator new(size_t sz) {
    size_t aligned = (sz + alignof(max_align_t) - 1) & ~(alignof(max_align_t) - 1);
    if (arena_pos + aligned > ARENA_SIZE) {
        throw bad_alloc();
    }
    void* ptr = arena + arena_pos;
    arena_pos += aligned;
    return ptr;
}

void operator delete(void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete[](void *, size_t) noexcept {}