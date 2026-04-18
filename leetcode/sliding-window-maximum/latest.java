class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        int[] res = new int[nums.length - k + 1];

        Deque<Integer> d = new ArrayDeque<>();

        for (int i = 0; i < k; i++) {
            while (!d.isEmpty() && nums[d.peekLast()] < nums[i]) {
                d.removeLast();
            }
            d.addLast(i);
        }
        res[0] = nums[d.peekFirst()];
        for (int i = 1; i < res.length; i++) {
            int r = i - 1;
            int a = i + k - 1;
            if (d.peekFirst() == r)
                d.removeFirst();
            while (!d.isEmpty() && nums[d.peekLast()] < nums[a]) {
                d.removeLast();
            }
            d.addLast(a);
            res[i] = nums[d.peekFirst()];
        }
        return res;
    }
}