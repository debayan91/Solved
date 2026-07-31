#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt,abm")
class Solution {
public:
    int count = 0;
    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;

        int p = i;
        int q = mid + 1;

        while(p <= mid && q <= r){
            if(nums[p] > 2LL * nums[q]){
                count += mid - p + 1;
                q++;
            } else p++;
        }

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }
        while (j <= r) {
            temp.push_back(nums[j++]);
        }
        for (int k = l; k <= r; k++) {
            nums[k] = temp[k - l];
        }
    }
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, size(nums) - 1);
        return count;
    }
};