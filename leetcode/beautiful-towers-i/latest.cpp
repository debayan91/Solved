class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        unsigned long long mx = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            // i is gonna be the peak
            unsigned long long sum = 0;
            int last = heights[i];
            sum += last;
            for(int j = i - 1; j >= 0; j--){
                last = min(last, heights[j]);
                sum += last;
            }
            last = heights[i];
            for(int j = i + 1; j < n; j++){
                last = min(last, heights[j]);
                sum += last;
            }
            mx = max(sum, mx);
        }
        return mx;
    }
};