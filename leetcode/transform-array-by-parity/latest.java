class Solution {
    public int[] transformArray(int[] nums) {
        int z = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] % 2 == 0){
                nums[z] = 0;
                z++;
            }
        }
        for(int i = z; i < nums.length; i++) nums[i] = 1;
        return nums;
    }
}