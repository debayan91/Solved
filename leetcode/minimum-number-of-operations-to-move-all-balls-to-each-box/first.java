class Solution {
    public int[] minOperations(String boxes) {
        int[] pre = new int[boxes.length()];
        int balls = 0;
        int steps = 0;
        char[] list = boxes.toCharArray();
        System.out.println(java.util.Arrays.toString(list));
        for (int i = 0; i < list.length; i++) {
            steps = steps + balls;
            pre[i] = steps;
            if (list[i] == '1') {
                balls++;
            }
        }
        int[] post = new int[boxes.length()];
        steps = 0;
        balls = 0;
        for (int i = list.length - 1; i >= 0; i--) {
            steps = steps + balls;
            post[i] = steps;
            if (list[i] == '1') {
                balls++;
            }
            pre[i]+=post[i];
        }
        System.out.println(java.util.Arrays.toString(pre));
        System.out.println(java.util.Arrays.toString(post));
        return pre;
    }
}