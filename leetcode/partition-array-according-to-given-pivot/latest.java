class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] res = new int[nums.length];
        int index = 0;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < pivot) {
                res[index] = nums[i];
                index++;
            } else if (nums[i] == pivot) {
                count++;
            }
        }
        for (int i = 0; i < count; i++) {
            res[index] = pivot;
            index++;
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > pivot) {
                res[index] = nums[i];
                index++;
            }
        }
        return res;
    }
}