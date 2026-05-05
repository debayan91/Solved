class Solution {
    public int longestCommonSubsequence(String a, String b) {
        int[][] dp = new int[a.length() + 1][b.length() + 1];
        for(int i = 1; i < a.length() + 1; i++){
            for(int j = 1; j < b.length() + 1; j++){
                if(a.charAt(i - 1) == b.charAt(j - 1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[a.length()][b.length()];
    }
}