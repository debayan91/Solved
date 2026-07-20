class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> a, b;
        for(int i = 0; i < size(nums); i++){
            if(i % 2) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        sort(begin(a), end(a), greater<int>());
        sort(begin(b), end(b));
        int i = 0, j = 0;
        int k = 0;
        while(k < size(nums)){
            if(k % 2) nums[k++] = a[i++];
            else nums[k++] = b[j++];
        }
        return nums;
    }
};