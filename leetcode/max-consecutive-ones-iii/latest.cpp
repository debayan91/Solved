class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = size(nums);
        int mx = 0;
        queue<int> q;
        int start = 0;
        for(int i = 0; i < n; i++){
            if(!nums[i]){
                q.push(i);
            }
            if(q.size() > k){
                start = q.front() + 1;
                q.pop();
            }
            mx = max(mx, i - start + 1);
        }
        return mx;
    }
};