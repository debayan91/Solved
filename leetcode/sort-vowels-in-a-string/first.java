class Solution {
    public String sortVowels(String s) {
        int n = s.length();
        char[] str = s.toCharArray();
        int[] ascii = new int[128];
        for (int i = 0; i < n; i++) {
            char ch = Character.toLowerCase(str[i]);
            if (ch == 'a' || ch == 'o' || ch == 'i' || ch == 'e' || ch == 'u') {
                ascii[(int)(str[i])]++;
                str[i] = '0';
            }
        }
        int i = 0;
        int j = 0;
        while (i < n) {
            if (str[i] == '0') {
                while (ascii[j] == 0) {
                    j++;
                }
                ascii[j]--;
                str[i] = (char)j;
            }
            i++;
        }
        return new String(str);
    }
}