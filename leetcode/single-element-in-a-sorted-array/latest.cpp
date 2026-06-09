class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(size(nums) == 1) return nums[0];
        for(int i = 0; i < size(nums); i += 2){
            // cout << nums[i] << " " << nums[i + 1] << endl;
            if(i + 1 < size(nums) && nums[i] != nums[i + 1]) return nums[i];
        }
        return nums.back();
    }
};


#pragma GCC optimize("Ofast")
static constexpr size_t BUFFER_SIZE = 64ull << 20;
alignas(std::max_align_t)
static unsigned char BUFFER[BUFFER_SIZE];
static unsigned char* ptr = BUFFER;
void* operator new(std::size_t n) {
    constexpr size_t A = alignof(std::max_align_t);
    n = (n + A - 1) & ~(A - 1);
    if (ptr + n > BUFFER + BUFFER_SIZE)throw std::bad_alloc();
    void* r = ptr;    ptr += n;
    return r;
}
void* operator new[](std::size_t n) {
    return operator new(n);
}
void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, std::size_t) noexcept {}
void operator delete[](void*, std::size_t) noexcept {}