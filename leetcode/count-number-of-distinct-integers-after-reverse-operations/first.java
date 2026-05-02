class Solution {
    public int rev(int n) {
        return Integer.parseInt(new StringBuilder(Integer.toString(n)).reverse().toString());
    }

    public int countDistinctIntegers(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int a : nums) {
            set.add(a);
            set.add(rev(a));
        }
        return set.size();
    }
}