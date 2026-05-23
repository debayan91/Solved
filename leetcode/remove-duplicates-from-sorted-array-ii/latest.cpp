class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        int i = 0;
        while(i < n){
            int current = nums[i]; 
            int count = 0;
            while(i < n && nums[i] == current){
                i++;
                count++;
            }
            int j = 0;
            while(count > 0 && index < n && j < 2){
                j++;
                count--;
                index++;
                nums[index] = current;
            }
        }
        return index + 1;
    }
};