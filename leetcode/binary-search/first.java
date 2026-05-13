class Solution {
    public int bs(int[] nums, int l,int h, int t){
        if(l>h) return - 1;
        int m = (h + l)/ 2;
        if(nums[m] == t) return m;
        if(nums[m] < t)  return bs(nums, m + 1, h, t);
        else return bs(nums, l, m - 1, t);
    }
    public int search(int[] nums, int target) {
        return bs(nums, 0, nums.length - 1, target);
    }
}