class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = size(nums);
        vector<int> left(n + 1, 0);
        vector<int> right(n + 1, 0);
        if(nums[n - 1] == 1) right[n - 1] = 1; 
        for (int i = 1; i < n; i++) {
            if(nums[i - 1] == 0){
                left[i]++;
            }
            left[i] += left[i - 1];
            int j = n - 1 - i;
            if(nums[j] == 1){
                right[j]++;
            }
            right[j] += right[j + 1];
        }
        left[n] = left[n - 1];
        if(nums[n - 1] == 0) left[n]++;
        for (int i = 0; i < n; i++) {
            left[i] += right[i];
        }
        int mx = *max_element(begin(left), end(left));
        vector<int> r;
        for(int i = 0; i <= n; i++){
            if(left[i] == mx) r.push_back(i);
        }
        return r;
    }
};