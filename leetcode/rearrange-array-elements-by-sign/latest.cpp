class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> res(n);
        int a = 0;
        int b = 1;
        for (int i = 0; i < n; i++) {
            if(nums[i]>0){
                res[a] = nums[i];
                a += 2;
            }else{
                res[b] = nums[i];
                b += 2;
            }
        }
        return res;
    }
};