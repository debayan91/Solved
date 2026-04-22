class Solution {
    public int minOperations(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        int a = sum%k;
        return a;
    }
}