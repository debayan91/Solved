class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 0;
        for (int i = digits.length - 1; i >= 0; i--) {
            if (i == digits.length - 1) {
                digits[i]++;
                if (digits[i] > 9) {
                    carry = digits[i] / 10;
                    digits[i] %= 10;
                }
            } else {
                digits[i] += carry;
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
        if (carry > 0) {
            int[] a = new int[digits.length + 1];
            a[0] = carry;
            for (int i = 1; i < a.length; i++) {
                a[i] = digits[i - 1];
            }
            return a;
        }
        return digits;
    }
}