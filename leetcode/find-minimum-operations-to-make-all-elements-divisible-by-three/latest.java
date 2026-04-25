class Solution {
    public int minimumOperations(int[] nums) {
        int count = nums.length;
        for (int i : nums)
            if (i % 3 == 0)
                count--;
        return count;
    }
}