class Solution {
    public boolean isStrictlyPalindromic(int n) {
        for (int i = 2; i < n - 1; i++) {
            int bits = (n == 0) ? 1 : (int) (Math.log(n) / Math.log(i)) + 1;
            String s = "";
            int k = n;
            while (k > 0) {
                s += Integer.toString(k % i);
                k /= i;
            }
            String s_rev = new StringBuilder(s).reverse().toString();
            if (!s.equals(s_rev))
                return false;
        }
        return true;
    }
}