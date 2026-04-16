class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int> s;
        // for(int i = 0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // nums.clear();
        // for(int x : s) {
        //     nums.push_back(x);
        // }
        // return s.size();

        // //--------------- horrible -----------------
        // int first_seen = v[0];

        // for(int i = 1 ; i < v.size() ;i++){
        //     if(v[i] == first_seen){
        //         v.erase(v.begin()+i);
        //         i--;
        //     }else{
        //         first_seen = v[i];
        //     }
        // }
        // return v.size();

        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        nums.erase(nums.begin() + i + 1,nums.end());
        return i + 1;
    }
};