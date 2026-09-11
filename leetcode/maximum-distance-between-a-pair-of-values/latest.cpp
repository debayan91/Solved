class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = size(nums1), n = size(nums2), i = 0, j = 0, res = 0;
        while(i < m && j < n){
            if(i > j) j++;
            else if(nums1[i] <= nums2[j]){
                // i <= j ---> j can go right/lesser .. decreasing
                res = max(res, j - i);
                j++;
            } else {
                // i > j ---> if j goes right it gets worse, i needs to reduce
                i++;
            }
        }
        return res;
    }
};