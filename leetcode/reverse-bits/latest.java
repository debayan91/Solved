class Solution {
    public int reverseBits(int n) {
        int res = 0;
        int twos = 1;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            System.out.print(bit);
            res += twos * bit;
            twos *= 2;
        }
        return res;
    }
}