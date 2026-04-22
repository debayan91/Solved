class Solution {
    public int scoreOfString(String s) {
        char[] a = s.toCharArray();
        int count = 0;
        for(int i = 1;i<s.length();i++){
            count += Math.abs(a[i] - a[i-1]);
        }
        return count;
    }
}