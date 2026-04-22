class Solution {
    public int[] recoverOrder(int[] order, int[] friends) {
        Set<Integer> a = new HashSet<>();
        int[] c = new int[friends.length];
        for (int b : friends)
            a.add(b);
        int index = 0;
        for (int x : order) {
            if (a.contains(x) && index < friends.length) {
                c[index] = x;
                index++;
            }
        }
        return c;
    }
}