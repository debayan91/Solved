class Solution {
    public int[] findThePrefixCommonArray(int[] a, int[] b) {
        Set<Integer> set = new HashSet<>();
        int[] c = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            int count = 0;

            int a_element = a[i];
            int b_element = b[i];

            if(set.contains(a_element)){
                set.remove(a_element);
                count++;
            }else{
                set.add(a_element);
            }

            if(set.contains(b_element)){
                set.remove(b_element);
                count++;
            }else{
                set.add(b_element);
            }

            c[i] = (i == 0) ? count : count + c[i-1];
        }

        return c;
    }
}