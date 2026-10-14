class Solution {
public:
    int centeredSubarrays(vector<int>& nums) { int res = 0;
        for(int i = 0; i < size(nums); i++){
            set<int> st;
            int sum = 0;
            for(int j = i; j < size(nums); j++){
                sum += nums[j];
                st.insert(nums[j]);
                if(st.count(sum)) res++;
            }
        } return res;
    }
};