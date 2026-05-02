class Solution {
    public int rev(int n) {
        int num = 0;
        while (n > 0) {
            num = num * 10 + n % 10;
            n /= 10;
        }
        return num;
    }

    public int countDistinctIntegers(int[] nums) {
        boolean[] damn = new boolean[1000001];
        int count = 0;
        for (int a : nums) { 
            if (!damn[a]) {
                damn[a] = true;
                count++;
            }
            if(!damn[rev(a)]){
                damn[rev(a)] = true;
                count++;
            }
        }
        return count;
    }
}