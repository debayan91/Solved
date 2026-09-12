class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> m; int count = 0;
        for(int i = 0; i < size(nums); i++) m[nums[i]].push_back(i);
        for(auto& [a, b] : m){
            if(size(b) >= 3){
                int d = b[1] - b[0]; bool flag = 1;
                for(int i = 2; i < size(b); i++){
                    if(b[i] - b[i - 1] != d){
                        flag = 0; break;
                    }
                }
                if(flag) count++;
            }
        }
        return count;
    }
};