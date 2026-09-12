class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> m; int count = 0;
        for(int i = 0; i < size(nums); i++) m[nums[i]].push_back(i);
        for(auto& [a, b] : m){
            if(size(b) == 3){
                if(b[1] - b[0] == b[2] - b[1]) count++;
            }
        }
        return count;
    }
};