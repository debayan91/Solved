
#pragma GCC optimize("Ofast")
#include <iostream>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return &BUFFER[pos - size];
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}
class Solution {
public:
    int max_depth = 0;
    void res(TreeNode* root, int depth){
        if(root == nullptr){
            max_depth = max(max_depth, depth);
            return;
        }
        res(root->right, depth + 1);
        res(root->left, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        res(root, 0);
        return max_depth;
    }
};