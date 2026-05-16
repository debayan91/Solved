static const bool __boost = [] () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

const size_t BUFFER_SIZE = 0x8000000; 
alignas (std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new (size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);

    if (buffer_pos % alignment != 0) {
        buffer_pos += alignment - (buffer_pos % alignment);
    }
    
    void* ptr = &buffer[buffer_pos];
    buffer_pos += size;
    return ptr;
}

void operator delete (void*, unsigned long) noexcept {}
void operator delete (void*) noexcept {}
void operator delete[] (void*) noexcept {}
void operator delete[] (void*, size_t) noexcept {}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;

        // check if the array is in descending order
        while(j > 0){
            if(!(nums[j] <= nums[j - 1])) break;
            else j--;
        }

        if(j == 0){
            sort(nums.begin(), nums.end());
            return;
        }

        // to find and replace the main element
        j = nums.size() - 1;
        while(nums[j] <= nums[j - 1]) j--;
        j--; // the element that we need to change
        int replacement = INT_MAX;
        int mindex = -1; // the replacement's index
        for(int i = j + 1; i < nums.size(); i++){
            if(nums[i] < replacement && nums[i] > nums[j]){
                replacement = nums[i];
                mindex = i;
            }
        }
        if(mindex == -1) return;
        swap(nums[j], nums[mindex]);
        sort(nums.begin() + j + 1, nums.end());
        // cout << j;
    }
};