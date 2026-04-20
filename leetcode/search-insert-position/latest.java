class Solution {
    int bs(int[] nums, int t, int l, int h){
        int mid = l + (h-l)/2;
        if(nums[mid] == t) return mid;
        if(h-l == 1){
            if(t>nums[h]) return h+1;
            else if(t>nums[l]) return l+1;
            else return l;
        }else if(l == h){
            if(t>nums[l]) return h+1;
            return h;
        }
        if(t<nums[mid]) return bs(nums,t,l,mid-1);
        return bs(nums,t,mid+1,h);
    }
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        return bs(nums, target,0, n-1);
    }
}