class Solution {
    public List<Integer> findValidElements(int[] nums) {
        List<Integer> res = new ArrayList<>();

        int[] left = new int[nums.length];
        int[] right = new int[nums.length];

        int maxleft = 0;
        int maxright = 0;
        int lindex = -1;
        int rindex = -1;

        for (int i = 0; i < nums.length; i++) {
            int index = nums.length - 1 - i;
            if(nums[i] > maxleft){
                maxleft = nums[i];
                lindex = i;
            }
            left[i] = lindex;
            if(nums[index] > maxright){
                maxright = nums[index];
                rindex = index;
            }
            right[index] = rindex;
        }

        res.add(nums[0]);

        for (int i = 1; i < nums.length - 1; i++){
            if(i == right[i] || i == left[i]) res.add(nums[i]);
        }
        
        if(nums.length != 1) res.add(nums[nums.length - 1]);

        return res;
    }
}