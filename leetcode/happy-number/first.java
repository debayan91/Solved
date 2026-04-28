class Solution {
    Set<Integer> h = new HashSet<>();
    public boolean isHappy(int n) {
        if(n == 1)return true;
        int a = 0;
        while(n>0){
            a += (n%10)*(n%10);
            n /= 10;
        }
        System.out.println(a);
        if(h.contains(a)) return false;
        else h.add(a);
        return isHappy(a);
    }
}