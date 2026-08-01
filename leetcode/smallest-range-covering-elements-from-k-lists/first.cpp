class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(), i = -1, j = -1, mn = INT_MAX;
        vector<pair<int, int>> arr; // {value, listIndex}
        for (int list = 0; list < k; list++)
            for (int value : nums[list])
                arr.push_back({value, list});
        sort(arr.begin(), arr.end());
        unordered_map<int, int> window;
        int formed = 0, left = 0;
        for (int right = 0; right < arr.size(); right++) {
            int list = arr[right].second;
            window[list]++;
            if (window[list] == 1)
                formed++;
            while (formed == k) {
                int L = arr[left].first;
                int R = arr[right].first;
                if (R - L < mn || (R - L == mn && L < i)) {
                    mn = R - L;
                    i = L;
                    j = R;
                }
                int leftList = arr[left].second;
                window[leftList]--;
                if (window[leftList] == 0)
                    formed--;

                left++;
            }
        }
        return {i, j};
    }
};