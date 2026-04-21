class Solution {
    public int maxDistance(int[] colors) {
        int a = 0;
        int b = colors.length - 1;
        int max = -1;
        while (a < b) {
            if (colors[a] == colors[b]) {
                b--;
            }
            if (colors[a] != colors[b]) {
                max = b - a;
                break;
            }
        }
        a = 0;
        b = colors.length - 1;
        while (a < b) {
            if (colors[a] == colors[b]) {
                a++;
            }
            if (colors[a] != colors[b]) {
                if (b - a > max) {
                    max = b - a;
                }
                break;
            }
        }
        return Math.max(max,0);
    }
}