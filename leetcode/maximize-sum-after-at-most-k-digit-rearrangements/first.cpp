class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n  = size(nums);
        vector<pair<int, int>> d;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            string a = to_string(nums[i]);
            sort(begin(a), end(a), greater<>());
            d.push_back({stoi(a) - nums[i], nums[i]});
        }
        sort(begin(d), end(d), greater<>());
        for(int i = 0; i < n; i++){
            if(i < k){
                sum += 1LL * d[i].second + d[i].first;
            } else sum += d[i].second;
        }
        return sum;
    }
};