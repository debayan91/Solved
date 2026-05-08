class Solution {
    public int[] transformArray(int[] nums) {
        int n = nums.length;
        int z = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                nums[z] = 0;
                z++;
            }
        }
        for(int i = z; i < n; i++) nums[i] = 1;
        return nums;
    }
}