class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, count_a = 0, count_b = 0;
        for(int i : nums){
            if(i == a) count_a++;
            else if(i == b) count_b++;
            else if(count_a == 0){
                a = i;
                count_a++;
            }
            else if(count_b == 0){
                b = i;
                count_b++;
            }
            else {
                count_a--;
                count_b--;
            }
        }
        int count = 0;
        for(int i : nums) if(i == a) count++;
        vector<int> res;
        if(count > size(nums) / 3) res.push_back(a);
        count = 0;
        for(int i : nums) if(i == b) count++;
        if(count > size(nums) / 3) res.push_back(b);
        return res;
    }
};