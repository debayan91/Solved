class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m; for(int i = 0; i < size(nums); i++) m[nums[i]].push_back(i); int mn = INT_MAX;
        for(auto& [a, b] : m){
            if(size(b) < 3) continue;
            int sum = 0;
            for(int i = 2; i < size(b); i++){
                int c = abs(b[i] - b[i - 1]) + abs(b[i - 1] - b[i - 2]) + abs(b[i] - b[i - 2]);
                mn = min(mn, c);
            }
        }
        return mn == INT_MAX ? -1 : mn;
    }
};