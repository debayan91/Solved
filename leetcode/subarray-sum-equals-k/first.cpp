class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m; // need, frequency
        int sum = 0;
        m[0] = 1;
        int count = 0;
        for(int i = 0; i < size(nums); i++){
            // sum contains the sum of all elements till now including this element
            sum += nums[i];
            // how much much must i remove to get my k sum -> how back is my start
            int need = sum - k;
            // need is the prefix sum of a certain element - so if need exists that means x elements have the needed prefix sum
            if(m.count(need)) count += m[need];
            // store the prefix sum
            m[sum]++;
        }
        return count;
    }
};