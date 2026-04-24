class Solution {
    public static int[] bin(int a) {
        int[] b = new int[32];
        for (int i = 0; i < 32; i++) {
            b[i] = (a >>> i) & 1;
        }
        return b;
    }

    public int getSum(int a, int b) {
        int[] x = bin(a);
        int[] y = bin(b);
        int[] z = new int[32];

        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int s = x[i] ^ y[i] ^ carry;
            carry = (x[i] & y[i]) + (carry & (x[i] ^ y[i]));
            z[i] = s;
        }

        int res = 0;
        int two = 1;
        for (int i = 0; i < 32; i++) {
            if(z[i] == 1) res += two;
            two *= 2;
        }
        return res;
    }
}