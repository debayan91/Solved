#pragma GCC optimize("Ofast")

#include <iostream>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding =
        (max_align - (pos % max_align)) % max_align;

    pos += padding + size;

    return static_cast<void *>(&BUFFER[pos - size]);
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
    int bs(vector<int>& nums, int l, int h) {
        if (l == h) return nums[l];

        if (l + 1 == h)
            return min(nums[l], nums[h]);

        int mid = (l + h) / 2;

        if (nums[mid] < nums[mid - 1])
            return nums[mid];

        if (nums[mid] > nums[mid + 1])
            return nums[mid + 1];

        if (nums[l] < nums[mid])
            return bs(nums, mid + 1, h);

        return bs(nums, l, mid - 1);
    }

    int findMin(vector<int>& nums) {
        if (nums[0] <= nums[nums.size() - 1])
            return nums[0];

        return bs(nums, 0, nums.size() - 1);
    }
};