class Solution {
    public int mirrorDistance(int n) {
        String s = String.valueOf(Math.abs(n));
        int a = Integer.parseInt((new StringBuilder(s).reverse().toString()));
        return Math.abs(n-a);
    }
}