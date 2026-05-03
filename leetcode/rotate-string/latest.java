class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length()) return false;
        s = s + s;
        return (s + s).contains(goal);
    }
}