class Solution {
    public String stringHash(String s, int k) {
        int n = s.length();
        String res = "";
        for (int i = 0; i < n; i+=k) {
            int sum = 0;
            int index = -1;
            for (int j = 0; j < k; j++) {
                index = j+i;
                sum += s.charAt(index) - 'a';
            }
            char add = (char)('a' + (sum%26));
            res += add;
        }
        return res;
    }
}