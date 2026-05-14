class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> buckets;
        int max = 0;
        for (int i : nums) {
            if (buckets.count(i) == 0)
                buckets[i] = 0;
            buckets[i]++;
            if(buckets[i] > max) max = buckets[i];
        }
        vector<vector<int>> counts(max + 1);
        for(auto& [key,value] : buckets){
            counts[value].push_back(key);
        }
        vector<int> res(k);
        int index = 0;
        int i = max;
        while(index < k){
            while(counts[i].empty()) i--;
            for(int number : counts[i]){
                if(index < k) res[index++] = number;
            }
            i--;
        }
        return res;
    }
};