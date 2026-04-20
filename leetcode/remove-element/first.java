class Solution {
    public void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public int removeElement(int[] nums, int val) {
        int n = nums.length;
        if(n == 0) return 0;
        int back = n - 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(nums[i] != val) count++;
        }
        
        for(int i = 0;i<n;i++){
            if(nums[i] == val && i<back){
                while(nums[back] == val && back>0){
                    back--;
                }
                if(i<back) swap(nums,i,back);
            }
        }

        return count;
    }
}