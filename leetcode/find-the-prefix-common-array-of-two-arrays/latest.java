class Solution {
    public int[] findThePrefixCommonArray(int[] a, int[] b) {
        //Set<Integer> set = new HashSet<>();
        int[] nums = new int[a.length + 1];
        int[] c = new int[a.length];
        int count = 0;
        for (int i = 0; i < a.length; i++) {

            int a_element = a[i];
            int b_element = b[i];

            if (nums[a[i]] == 1) {
                nums[a[i]]--;
                count++;
            } else {
                nums[a[i]]++;
            }

            if (nums[b[i]] == 1) {
                nums[b[i]]--;
                count++;
            } else {
                nums[b[i]]++;
            }

            c[i] = count;
        }

        return c;
    }
}