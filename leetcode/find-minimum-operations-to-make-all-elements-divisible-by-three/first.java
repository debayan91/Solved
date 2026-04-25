class Solution {
    public int minimumOperations(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 3)
                count++;
            else {
                int a = nums[i] % 3;
                int b = (nums[i] + 3) % 3;
                int c = ((nums[i] / 3) + 1) * 3 - nums[i];
                count += Math.min(a, Math.min(b, c));
            }
        }
        return count;
    }
}