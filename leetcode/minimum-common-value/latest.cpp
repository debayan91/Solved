class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n = nums2.size();
        int min = INT_MAX;
        for(int k = 0; k < nums1.size(); k++){
            while(i < n && nums2[i] < nums1[k]) i++;
            if(i == n) break;
            if(nums2[i] == nums1[k]){
                if(nums2[i] < min){
                    min = nums2[i];
                }
            }
        }
        if(min == INT_MAX) return -1;
        return min;
    }
};