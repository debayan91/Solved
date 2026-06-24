class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int types = m.size();
        int mx = 0;
         for (char c : tasks){
            m[c]++;
            mx = max(m[c], mx);
        }
        int count_mx = 0;
        for (auto& [ch, freq] : m)
            if (freq == mx)
                count_mx++;
        int m1 = mx + (mx - 1) * n + count_mx - 1;
        int s = size(tasks);
        return max(m1, s);
    }
};