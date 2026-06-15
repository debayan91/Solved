class Solution {
public:
    void next(vector<int>& nums) {
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
    }
    string getPermutation(int n, int k) {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = i + 1;
        for (int i = 0; i < k - 1; i++) {
            next(v);
        }
        string str;
        str.reserve(n);
        for (int num : v) {
            str += (num + '0');
        }
        return str;
    }
};