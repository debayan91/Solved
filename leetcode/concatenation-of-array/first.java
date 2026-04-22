class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] a = new int[nums.length * 2];
        System.arraycopy(nums, 0, a, 0, nums.length);
        System.arraycopy(nums, 0, a, nums.length, nums.length);
        return a;
    }
}