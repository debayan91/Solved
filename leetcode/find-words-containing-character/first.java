class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        int n = words.length;
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String s = words[i];
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == x) {
                    res.add(i);
                    break;
                }
            }
        }
        return res;
    }
}