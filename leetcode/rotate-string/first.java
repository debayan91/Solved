class Solution {
    public boolean rotateString(String s, String goal) {
        int n = goal.length();
        char[] a = s.toCharArray();
        char[] b = goal.toCharArray();

        if(a.length != b.length) return false;

        int index = 0;

        for (int i = 0; i < n; i++) {
            int temp = i;
            if (a[index] == b[i]) {
                int count = 0;
                while (index < n && a[index] == b[i]) {
                    index++;
                    i = (i + 1) % n;
                    count++;
                    System.out.println(count);
                }
                if(count == n) return true;
                index = 0;
                i = temp;
                System.out.println("reset");
            }
        }
        return false;
    }
}