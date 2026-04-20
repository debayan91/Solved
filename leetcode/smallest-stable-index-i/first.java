class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] a = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]>max) {
                max = nums[i];
                a[i] = max;
            }else{
                a[i] = max;
            }
        }
        for(int i : a){System.out.print(i+ " ");}
        int min = Integer.MAX_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            if(nums[i]<min){
                min = nums[i];
                a[i] -= min;
            }else{
                a[i] -= min;
            }
        }
        for(int i : a){System.out.print(i+" ");}
        min = Integer.MAX_VALUE;
        int mindex = -1;
        for(int i = 0;i<n;i++){
            if(a[i]<=k && a[i]<min){
                min = a[i];
                mindex = i;
                return mindex;
            }
        }
        return mindex;
    }
}