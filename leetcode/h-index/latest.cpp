class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        vector<int> p(n + 1, 0); // ith index is number of papers w more then i citations
        for(int i : nums){
            if(i > n){
                p[n]++;
            }else{
                p[i]++;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            p[i] += p[i + 1];
        }
        for(int i = n; i >= 0; i--){
            if(p[i] >= i){
                return i;
            }
        }
        return max;
    }
};