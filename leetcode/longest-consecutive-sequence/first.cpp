class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        unordered_set<int> st;
        for(int i : nums) st.insert(i);
        // for(int i = 0; i < nums.size(); i++){
        //     if(st.count(nums[i] - 1) != 0) continue;
        //     if(st.count(nums[i] + 1) != 0){
        //         int a = nums[i];
        //         int temp = 0;
        //         while(st.count(a++) > 0) temp++;
        //         if(temp > count) count = temp;
        //     }
        // }

        for(int i : st){
            if(st.count(i - 1) != 0) continue;
            int temp = 0;
            while(st.count(i++) > 0) temp++;
            if(temp > count) count = temp;
        }
        return count;
    }
};