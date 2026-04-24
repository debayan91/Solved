class Solution {
    public int[] countBits(int n) {
        int[] res = new int[n + 1];
        for (int i = 0; i < res.length; i++) {
            int a = i;
            while(a != 0){
                a = a & (a-1);
                res[i]++;
            }
        }
        return res;
    }
}