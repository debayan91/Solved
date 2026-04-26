class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> set = new HashSet<>(); int count = 0;
        for(char a : jewels.toCharArray()) set.add(a);
        for(char a : stones.toCharArray()) if(set.contains(a)) count++;
        return count;
    }
}