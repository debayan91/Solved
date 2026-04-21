class Solution {
    public int maxDistinct(String s) {
        int[] a = new int[26];
        for(int i = 0 ;i<s.length();i++){
            a[s.charAt(i) - 'a'] = 1;
        }
        return Arrays.stream(a).sum();
    }
}