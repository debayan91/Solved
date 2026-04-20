class Solution {
    public int myAtoi(String s) {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1 && !Character.isDigit(s.charAt(0)))
            return 0;


        int a = 1;
        int start = 0;
        char[] nums = s.toCharArray();
        int temp = start;

        while (nums[temp] == ' ') {
            temp++;
            if (temp == nums.length)
                return 0;
        }
        start += temp;
        if (nums[start] == '-') {
            start++;
            a = -1;
        } else if (nums[start] == '+') {
            start++;
        }

        temp = start;

        if (nums[temp] == '0') {
            while (nums[temp] == '0') {
                temp++;
                if (temp == nums.length)
                    return 0;
            }
            if (!Character.isDigit(nums[temp]))
                return 0;
        }

        start = temp;
        
        if (!Character.isDigit(nums[start]))
            return 0;
        long res = 0;
        int end = nums.length;
        for (int i = start; i < nums.length; i++) {
            if (!Character.isDigit(nums[i])) {
                end = i;
                break;
            }
        }
        long range = (int) Math.pow(10, end - start - 1);
        for (int i = start; i < end; i++) {
            res += range * Character.getNumericValue(nums[i]);
            range /= 10;
        }
        long r = res * a;
        if (r > Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        if (r < Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        return (int) r;
    }
}