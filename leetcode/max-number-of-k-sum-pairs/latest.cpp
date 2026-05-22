class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map; 
        
        int count = 0;
        for(int i : nums){
            int need = k - i;
            if(map[need]){
                map[need]--;
                count++;
            }else{
                map[i]++;
            }
        }
        return count;
    }
};