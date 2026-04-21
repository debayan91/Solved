class Solution {
    private void addValue(Map<Integer, List<Integer>> map, int key, int value) {
        // 1. Check if the key is already in the map
        if (!map.containsKey(key)) {
            // 2. If not, put a new empty list there
            map.put(key, new ArrayList<>());
        }
        // 3. Get the list (which definitely exists now) and add the value
        map.get(key).add(value);
    }

    // private int dist(int a, int index, List<Integer> nums) {
    //     int p = Math.abs(a - index);
    //     int q = Math.abs((a + nums.size()) - index);
    //     int t = Math.abs((index + nums.size()) - a);
    //     int r = Math.min(p, Math.min(q, t));

    //     return r;
    // }

    private int dist(int a, int index, int n) {
        int d = Math.abs(a - index);
        return Math.min(d, n - d);
    }

    public List<Integer> solveQueries(int[] nums, int[] queries) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            addValue(map, nums[i], i);
        }
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < queries.length; i++) {
            int index = queries[i] % nums.length;
            int value = nums[index];
            if (map.containsKey(value)) {
                List<Integer> list = map.get(value);
                if (list.size() == 1) {
                    l.add(-1);
                    continue;
                }else if(list.size() == 2){
                    int other = list.get(0) == index ? list.get(1) : list.get(0);
                    l.add(dist(other, index, nums.length));
                    continue;
                }

                // for (int a : map.get(value)) {
                //     if (a != index) {
                //         int p = Math.abs(a - index);
                //         int q = Math.abs((a + nums.length) - index);
                //         int t = Math.abs((index + nums.length) - a);
                //         int r = Math.min(p, Math.min(q,t));
                //         if (r < min) {
                //             flag = false;
                //             min = r;
                //         }
                //     }
                // }

                int pos = Collections.binarySearch(list, index);
                int p = list.get((pos + 1) % list.size());
                int q = list.get((pos - 1 + list.size()) % list.size());

                int min = Math.min(dist(p,index,nums.length),dist(q,index,nums.length));
                l.add(min);
            } else {
                l.add(-1);
            }
        }
        return l;
    }
}