class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        bool flag = true;
        while(flag){
            flag = false;
            for(int& a : nums){
                if(a == o){
                    o *= 2;
                    flag = true;
                    break;
                }
            }
        }
        return o;
    }
};