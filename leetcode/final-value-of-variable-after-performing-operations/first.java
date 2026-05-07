class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for(String a : operations){
            if(a.contains("++")) x++;
            else x--;
        }
        return x;
    }
}